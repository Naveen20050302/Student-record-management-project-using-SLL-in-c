#include"header.h"
int main()
{
    SLL *head=0;
    char op,op1;
    load(&head);
    while(1)
    {
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
         printf("s/S : Show the list\n");
         printf("m/M : Modify a record\n");
         printf("v/V : Save records\n");
         printf("e/E : Exit\n");
         printf("t/T : Sort the list\n");
         printf("l/L : Delete all the records\n");
         printf("r/R : Reverse the list\n");
         printf("Enter choice:\n");
         scanf(" %c",&op);
         switch(op)
         {
             case 'a':
             case 'A':
                 add(&head);
                 break;
             case 'd':
             case 'D':
                 del(&head);
                 break;
             case 's':
             case 'S':
                 show(head);
                 break;
             case 'm':
             case 'M':
                 mod(head);
                 break;
             case 'v':
             case 'V':
                 save(head);
                 break;
             case 'e':
             case 'E':
                 printf("S/s:Save & exit\n");
                 printf("E/e:Exit without saving\n");
                 printf("Enter the choice\n");
                 scanf(" %c",&op1);
                 switch(op1)
                 {
                     case 's':
                     case 'S':
                         save(head);
                         del_all(&head);
                         free(head);
                         return 0;
                     case 'e':
                     case 'E':
                         del_all(&head);
                         free(head);
                         return 0;
                 }
             case 't':
             case 'T':
                 sort(head);
                 break;
             case 'l':
             case 'L':
                 del_all(&head);
                 break;
             case 'r':
             case 'R':
                 rev(&head);
                 break;
             default:
                 printf("Invalid Choice:\n");
         }
     }
 }