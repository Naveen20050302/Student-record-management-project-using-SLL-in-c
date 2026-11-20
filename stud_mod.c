#include"header.h"
void mod(SLL *ptr)
{    
    char op;    printf("R\\r:Search by rollno\n");
    printf("N\\n:Search by name\n");    
    printf("P\\p:Search by percentage\n");    
    printf("Enter the choice\n");    
    scanf(" %c",&op);
    switch(op)
    {
        case 'R':
        case 'r':
        mod_by_rollno(ptr);
        break;
        case 'N':
        case 'n':
        mod_by_name(ptr);
        break;
        case 'P':
        case 'p':
        mod_by_marks(ptr);
        break;
        default:
        printf("Invalid option\n");
    }
}
void mod_by_rollno(SLL *ptr)
{
    int rollno;
    char name[20];
    printf("Enter the rollno to search\n");
    scanf("%d",&rollno);
    while(ptr)
    {
        if(ptr->rollno==rollno)
        {
            printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
            printf("Enter the name to modify\n");
            scanf(" %[^\n]",name);
            while(isname(name))
            {
                printf("Name is invalid, Enter another name\n");
             scanf(" %[^\n]",name);
            }
            strcpy(ptr->name,name);
            printf("Enter the percentage\n");
            scanf("%f",&ptr->percentage);
            while(ptr->percentage < 0 || ptr->percentage > 100)
            {
                printf("Enter percentage between 0 and 100:\n");
                scanf("%f", &ptr->percentage);
            }
        }
        ptr=ptr->next;
    }
}
void mod_by_name(SLL *ptr)
{
    char name[20];
    int rollno=1;
    printf("Enter the name to search\n");
    scanf(" %[^\n]",name);
    int c=countname(name,ptr);
    SLL *t=ptr;
    if(c==1)
    {
        rollno=1;
        while(ptr)
        {
            if(strcmp(ptr->name,name)==0)
            {
                printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                while(isrollno(rollno,t))
                rollno++;
                ptr->rollno=rollno;
                printf("Enter the percentage to modify\n");
                scanf("%f",&ptr->percentage);
                while(ptr->percentage < 0 || ptr->percentage > 100)
                {
                    printf("Enter percentage between 0 and 100:\n");
                    scanf("%f", &ptr->percentage);
                }
            }
            ptr=ptr->next;
        }
    }
    else if(c>1)
    {
        rollno=1;
        printname(name,ptr);
        int roll;
        printf("Enter the rollno to modify\n");
        scanf("%d",&roll);
        while(ptr)
        {
            if(ptr->rollno==roll)
            {
                printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                while(isrollno(rollno,t))
                rollno++;
                ptr->rollno=rollno;
                printf("Enter the percentage\n");
                scanf("%f",&ptr->percentage);
                while(ptr->percentage < 0 || ptr->percentage > 100)
                {
                    printf("Enter percentage between 0 and 100:\n");
                    scanf("%f", &ptr->percentage);
                }
            }
            ptr=ptr->next;
        }
    }
}
void mod_by_marks(SLL *ptr)
{
    float percentage;
    char name[20];
    int rollno=1;
    printf("Enter the percentage to search\n");
    scanf("%f",&percentage);
    int c=countmarks(percentage,ptr);
    SLL *t=ptr;
    if(c==1)
    {
        rollno=1;
        while(ptr)
        {
            if(ptr->percentage==percentage)
            {
                printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                while(isrollno(rollno,t))
                rollno++;
                ptr->rollno=rollno;
                printf("Enter the name to modify\n");
                scanf(" %[^\n]",name);
                while(isname(name))
                {
                    printf("Name is invalid, Enter another name\n");
                scanf(" %[^\n]",name);
                }
                strcpy(ptr->name,name);
            }
            ptr=ptr->next;
        }
    }
    else if(c>1)
    {
        rollno=1;
        printmarks(percentage,ptr);
        int roll;
        printf("Enter rollno to modify\n");
        scanf("%d",&roll);
        while(ptr)
        {
            if(ptr->rollno==roll)
            {
                printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                while(isrollno(rollno,t))
                rollno++;
                ptr->rollno=rollno;
                printf("Enter the name to modify\n");
                scanf(" %[^\n]",name);
                while(isname(name))
                {
                    printf("Name is invalid, Enter another name\n");
                    scanf(" %[^\n]",name);
                }
                strcpy(ptr->name,name);
            }
            ptr=ptr->next;
        }
    }
}
void sort(SLL *ptr)
{
    char op;
    printf("N\\n:Sort by name\n");
    printf("P\\p:Sort by percentage\n");
    printf("Enter the choice\n");
    scanf(" %c",&op);
    switch(op)
    {
        case 'n':
        case 'N':
        sort_by_name(ptr);
        break;
        case 'P':
        case 'p':
        sort_by_marks(ptr);
        break;
        default:
        printf("Invalid choice\n");
    }
}
void sort_by_name( SLL *ptr)
{
    SLL *p1;
    SLL *p2;
    SLL t;
    int i,j,c=countNode(ptr);
    p1=ptr;
    for(i=0;i<c-1;i++)
    {
        p2=p1->next;
        for(j=0;j<c-i-1;j++)
        {
            if(strcmp(p1->name,p2->name)>0)
            {
                t.rollno=p1->rollno;
                strcpy(t.name,p1->name);
                t.percentage=p1->percentage;
                p1->rollno=p2->rollno;
                strcpy(p1->name,p2->name);
                p1->percentage=p2->percentage;
                p2->rollno=t.rollno;
                strcpy(p2->name,t.name);
                p2->percentage=t.percentage;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}
void sort_by_marks( SLL *ptr)
{
    SLL *p1,*p2,t;
    int i,j,c=countNode(ptr);
    p1=ptr;
    for(i=0;i<c-1;i++)
    {
        p2=p1->next;
        for(j=0;j<c-i-1;j++)
        {
            if(p1->percentage<p2->percentage)
            {
                t.rollno=p1->rollno;
                strcpy(t.name,p1->name);
                t.percentage=p1->percentage;
                p1->rollno=p2->rollno;
                strcpy(p1->name,p2->name);
                p1->percentage=p2->percentage;
                p2->rollno=t.rollno;
                strcpy(p2->name,t.name);
                p2->percentage=t.percentage;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}
void rev(SLL **ptr)
{
    SLL *prev=0;
    SLL *curr=*ptr;
    SLL *next;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *ptr=prev;
}
int countmarks(float m,SLL *ptr)
{
    int c=0;
    while(ptr)
    {
        if(ptr->percentage==m)
            c++;
        ptr=ptr->next;
    }
    return c;
}
void printmarks(float m,SLL *ptr)
{
    while(ptr)
    {
        if(m==ptr->percentage)
        {
            printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
        }
        ptr=ptr->next;
    }
}