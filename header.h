#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
}SLL;
void add(SLL **);
void del(SLL **);
void show(SLL *);
void mod(SLL *);
void save(SLL *);
void sort(SLL *);
void del_all(SLL **);
void rev(SLL **);
void del_by_rollno(SLL **);
void del_by_name(SLL **);
void mod_by_rollno(SLL *);
void mod_by_name(SLL *);
void mod_by_marks(SLL *);
int countNode(SLL *);
void sort_by_name( SLL *);
void sort_by_marks( SLL *);
void load(SLL **);
int isrollno(int ,SLL *);
int isname(char *);
int countname(char *,SLL *);
void printname(char *,SLL *);
int countmarks(float ,SLL *);
void printmarks(float ,SLL *);