#include"header.h"
void save(SLL *ptr)
{
    FILE *fp=fopen("student.dat","w");
    while(ptr)
    {
        fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
        ptr=ptr->next;
    }
    fclose(fp);
}

void load(SLL **ptr)
{
    FILE *fp = fopen("student.dat", "r");
    if(fp == NULL)
    {
        printf("No File Found\n");
        return;
    }
    while(1)
    {
        SLL *new;
        SLL *last;
        int result;
        new = malloc(sizeof(SLL));
        if(new == NULL)
        {
            printf("Memory allocation failed\n");
            break;
        }
        result = fscanf(fp, "%d %49s %f",&new->rollno,new->name,&new->percentage);
        if(result != 3)
        {
            free(new);
            break;
        }
        new->next = NULL;
        if(*ptr == NULL)
        {
            *ptr = new;
        }
        else
        {
            last = *ptr;
            while(last->next)
                last = last->next;
            last->next = new;
        }
    }
    fclose(fp);
}
