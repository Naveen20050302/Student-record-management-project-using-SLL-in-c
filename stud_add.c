#include"header.h"
void add(SLL **ptr)
{
    SLL *new,*t;
    new=malloc(sizeof(SLL));
    int rollno=1;
    while(isrollno(rollno,*ptr))
    {
        rollno++;
    }
    new->rollno=rollno;
    printf("Enter name\n");
    scanf(" %[^\n]",new->name);
    while(isname(new->name))
    {
        printf("Name is invalid, Enter another name\n");
         scanf(" %[^\n]",new->name);
    }
    printf("Enter the percentage\n");
    scanf("%f",&new->percentage);
    while(new->percentage<0 || new->percentage>100)
    {
        printf("Enter the percentage between 0 to 100\n");
        scanf("%f",&new->percentage);
    }

    if(((*ptr)==0) || (new->rollno<(*ptr)->rollno))
    {
        new->next=*ptr;
        *ptr=new;
    }
    else
    {
        t=*ptr;
        while(t->next!=0 && t->next->rollno<new->rollno)
            t=t->next;
        new->next=t->next;
        t->next=new;
    }
}
int isrollno(int num,SLL *ptr)
{
    if(ptr==0)
        return 0;
    while(ptr)
    {
        if(ptr->rollno==num)
        return 1;
        ptr=ptr->next;
    }
    return 0;
}
int isname(char *p)
{
    while(*p)
    {
        if(!((*p>='a' && *p<='z')||(*p>='A' && *p<='Z')||(*p==' ')))
         return 1;
        p++;
    }
    return 0;
}