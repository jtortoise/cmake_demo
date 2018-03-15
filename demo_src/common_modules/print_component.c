#include "print_component.h"

void mine_print(char *msg)
{
   int i;
   int msg_length = strlen(msg);
   for(i=0; i<=msg_length+1; i++)
   {
        printf("*");
   }
   printf("\n*%s*\n", msg);
   for(i=0; i<=msg_length+1; i++)
   {
        printf("*");
   }
   printf("\n");

}
