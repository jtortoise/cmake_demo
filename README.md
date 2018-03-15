### CMake project demo

构建个人通用基础的项目目录结构，采用cmake(替掉Makefile)作为工程管理工具。

在这里简单的规划出一个基础的项目目录结构功能，基于cmake脚本使用cmake管理完成project中各个模块的编译、测试、安装等功能。

构建以上的项目结构+cmake脚本文件部署是为了熟悉cmake工具以及下次开始一个新项目时，可以基于此模板进行脚本的简单改造，快速搭建项目的工程管理结构出来。

#### 项目目录结构规划

``` shell
.
├── demo_config						# project的各个模块配置文件
│   ├── main_module_config.ini
│   ├── module1_config.ini
│   └── module2_config.ini
├── demo_doc						# project整体程序框架、模块联系以及模块详细介绍说明
│   ├── main_module_doc.md
│   ├── module1_doc.md
│   ├── module2_doc.md
│   └── README.md
├── demo_resources					# project的资源文件，如图片等
├── demo_src						# project的源码
│   ├── common_modules				# 公共模块组件代码，该模块的组件需要其它众多模块调用
│   │   ├── print_component.c		# 如单双链表、队列、散列映射等基础数据结构组件
│   │   └── print_component.h
│   ├── main_module					# 主模块代码，该模块与其它模块高耦合，基于其它模块构建
│   │   └── main.c
│   ├── module1						# 模块1代码，该模块除了依赖公共模块的组件，不应与其它
│   │   ├── module1_component.c		# 模块耦合，需高度独立
│   │   └── module1_component.h
│   ├── module2
│   │   ├── module2_component.c		# 同模块1
│   │   └── module2_component.h
│   └── test						# 所有模块的单元测试代码都应该放到这里
│       ├── common_modules
│       │   └── common_test.c
│       ├── main_module
│       │   └── main_module_test.c
│       ├── module1
│       │   └── module1_test.c
│       └── module2
│           └── module2_test.c
└── README.md						# project功能演示、安装使用说明等基本信息

```

#### CMake脚本文件在project中部署

``` shell
.
├── CMakeLists.txt
├── demo_config
│   ├── CMakeLists.txt
│   ├── main_module_config.ini
│   ├── module1_config.ini
│   └── module2_config.ini
├── demo_doc
│   ├── CMakeLists.txt
│   ├── main_module_doc.md
│   ├── module1_doc.md
│   ├── module2_doc.md
│   └── README.md
├── demo_resources
│   └── CMakeLists.txt
├── demo_src
│   ├── CMakeLists.txt
│   ├── common_modules
│   │   ├── CMakeLists.txt
│   │   ├── print_component.c
│   │   └── print_component.h
│   ├── main_module
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   ├── module1
│   │   ├── CMakeLists.txt
│   │   ├── module1_component.c
│   │   └── module1_component.h
│   ├── module2
│   │   ├── CMakeLists.txt
│   │   ├── module2_component.c
│   │   └── module2_component.h
│   └── test
│       ├── CMakeLists.txt
│       ├── common_modules
│       │   ├── CMakeLists.txt
│       │   └── common_test.c
│       ├── main_module
│       │   ├── CMakeLists.txt
│       │   └── main_module_test.c
│       ├── module1
│       │   ├── CMakeLists.txt
│       │   └── module1_test.c
│       └── module2
│           ├── CMakeLists.txt
│           └── module2_test.c
└── README.md
```

#### 使用说明

``` shell
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=install path-to-project
make
make install #[optional]
```

在这里定义了选项`-DCMAKE_INSTALL_PREFIX=install`是为了指定执行`make install`时的安装路径，默认是`/usr/local`，做测试提取的时候，可以定义该选项。

#### 版本说明

* [8db7b18](https://github.com/jtortoise/cmake_demo/commit/8db7b18d2245af2dfac1accb20c9aac1fa06d283)

  时间限制，只构建了基础的cmake脚本文件部署到project中。因为脚本中的变量都是写死的，所以每增加一个新目录时，都需要重新修改多个cmake脚本，这里的最终目地应该是每当新添加一个新目录时，应当只关心该目录下的cmake脚本编写，而无需关心修改其它cmake脚本。再有一个就是库的命名过于简单，容易跟其它库命名发生冲突等，这些变量的定义应当需要再灵活些。以上只是简单提了这个版本存在的一些问题，就是一些缺乏灵活性的问题。

#### ToDo

- [ ] 自动调用当前目录下的子目录

      目前的Cmake脚本文件都是手动调用`add_subdirectories()`添加各个目录，每增加一个新目录，都得手动修改cmake脚本

- [ ] 库以及可执行文件命名添加项目名称前缀，避免发生命名冲突

- [ ] 各个模块调用`include_direcotories()`的指定其它模块的头文件时，需统一该变量路径，以方便各模块定位到各个模块的头文件路径

      在一个模块中的组件调用其它模块的组件时，其`include`一般都是这种格式：

      ``` c
      #include "模块名称/组件头文件"
      ```

      所以该变量路径其实就是上面目录下的`demo_src`路径，以防修改`demo_src`文件夹名称后，又得需要修改其它模块的各个cmake脚本，这一点还是很致命的。

- [ ] 多个静态库组合成一个静态库

      考虑到项目的东西发布的可能是一个可执行文件程序，也可能库，因此有必要将多个模块的静态库组成一个静态库，方便链接，而不用链接一堆模块库。

#### 关于IDE中的cmake工具思考

在部署上面的项目中的cmake脚本时，经常考虑的是如何让cmake自动识别一些源文件，一些路径之类的，这样子整个工程的走向都是自己的管理之中。

之后看到CLion中的采用的是cmake作为工程管理工具，其cmake脚本的编写中的源文件名都是写死的，这是因为使用IDE的时候，添加源文件的时候都是需要右键项目添加之类的，这样子Clion就知道要添加一个源文件，然后将该源文件写到cmake脚本中进行管理等，所以它不需要考虑让cmake自动识别一些东西。

个人觉得熟悉了手动部署cmake脚本的时候，再去使用这类IDE将会更加得心应手，可以把更多精力放到每个模块的编译规则构建中，而不是考虑自动识别一些源文件以及一些目录等人性化的操作上，这些工作都由IDE来完成，也就是由IDE完成基本的Cmake脚本部署，而用户只需把重点放在每个模块的编译规则构建中。

自动的东西往往都是手动操作累了才产生的。