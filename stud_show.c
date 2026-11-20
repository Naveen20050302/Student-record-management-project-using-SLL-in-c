#include"header.h"
void show(SLL *ptr)
{
    if(ptr==0)
    {
        printf("No records found\n");
        return ;
    }
    printf("-----------------------------------------------------------------\n");
    printf("Rollno\tName\tPercentage\n");
    printf("-----------------------------------------------------------------\n");
    while(ptr)
    {
        printf("%d\t%s\t%f\n",ptr->rollno,ptr->name,ptr->percentage);
        ptr=ptr->next;
    }
    printf("-----------------------------------------------------------------\n");
}
int countNode(SLL *ptr)
{
    int c=0;
    while(ptr)
    {
        c++;
        ptr=ptr->next;
    }
    return c;
}