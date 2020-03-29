#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *ptr,*nptr;
    ptr=NULL;
    int i;
    for(i=0;i<10;i++)
    {
        nptr=(struct node*) malloc(sizeof(struct node));
        nptr->data=i;
        nptr->next=ptr;
        ptr=nptr;
    }
    nptr=ptr;
    while(nptr!=NULL)
    {
        printf("%d\n",nptr->data);
        nptr=nptr->next;
    }
    return 0;
}
