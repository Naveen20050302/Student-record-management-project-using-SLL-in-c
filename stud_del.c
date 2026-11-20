#include"header.h"
void del(SLL **ptr)
{
    char op;
    printf("r\\R:Delete by rollno\n");
    printf("N\\n:Delete by name\n");
    printf("Enter the choice\n");
    scanf(" %c",&op);
    switch(op)
    {
        case 'r':
        case 'R':
            del_by_rollno(ptr);
            break;
        case 'n':
        case 'N':
            del_by_name(ptr);
            break;
        default:
            printf("Invalid option\n");
    }
}
void del_by_rollno(SLL **ptr)
{
    SLL *del,*prev;
    int rollno;
    printf("Enter the rollno to delete:\n");
    scanf("%d",&rollno);
    del=*ptr;
    while(del)
    {
        if(rollno==del->rollno)
        {
            if(del==*ptr)
                *ptr=del->next;
            else
                prev->next=del->next;
            free(del);
            printf("Rollno deleted successfully\n");
            return ;
        }
        prev=del;
        del=del->next;
    }
    printf("Roll No not found\n");
}
void del_by_name(SLL **ptr)
{
    SLL *del,*prev;
    char name[20];
    int c;
    printf("Enter the name to delete:\n");
    scanf(" %[^\n]",name);
    c=countname(name,*ptr);
    del=*ptr;
    if(c==1)
    {
        while(del)
        {
            if(strcmp(name,del->name)==0)
            {
                if(del==*ptr)
                    *ptr=del->next;
                else
                    prev->next=del->next;
                free(del);
                printf("Name deleted successfully\n");
                return ;
            }
            prev=del;
            del=del->next;
        }
    }
    else if(c>1)
    {
        printname(name,*ptr);
        int roll;
        printf("Enter the rollno to delete\n");
        scanf("%d",&roll);
        while(del)
        {
            if(roll==del->rollno)
            {
                if(del==*ptr)
                    *ptr=del->next;
                else
                    prev->next=del->next;
                free(del);
                printf("Rollno deleted successfully\n");
                return ;
            }
            prev=del;
            del=del->next;
        }
    }
    printf("Name Not found\n");
}
void del_all(SLL **ptr)
{
    if(*ptr==0)
    {
        return ;
    }
    SLL *del=*ptr;
    while(del)
    {
        *ptr=del->next;
        free(del);
        del=*ptr;
    }
}
int countname(char *p,SLL *ptr)
{
    int c=0;
    while(ptr)
    {
        if(strcmp(p,ptr->name)==0)
            c++;
        ptr=ptr->next;
    }
    return c;
}
void printname(char *p,SLL *ptr)
{
    while(ptr)
    {
        if(strcmp(p,ptr->name)==0)
        {
            printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
        }
        ptr=ptr->next;
    }
}