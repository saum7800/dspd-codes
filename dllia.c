#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* insertAfter(Node* p, Node* q, Node* lptr)
{
    if(p==NULL)
    {
        if(lptr==NULL)//empty list
        {
            lptr=q;
        }
        else
        {
            q->next=lptr;
            lptr->prev=q;
            lptr=q;
        }
    }
    else if(p->next==NULL)//last
    {
        p->next=q;
        q->next=NULL;
        q->prev=p;
    }
    else
    {
        Node* tmp=p->next;
        p->next=q;
        q->prev=p;
        q->next=tmp;
        tmp->prev=q;
    }
    return lptr;
}

int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *ins = NULL;
    Node* tmp;
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    ins = (Node *)malloc(sizeof(Node));
    head->data = 1;
    head->next = second;
    head->prev = NULL;
    second->data = 2;
    second->next = third;
    second->prev = head;
    third->data = 3;
    third->next = NULL;
    third->prev = second;
    tmp=head;
    while (tmp!=NULL)
    {
        printf("%d\n",tmp->data);
        tmp=tmp->next;
    }
    ins->data=5;
    ins->next=NULL;
    ins->prev=NULL;
    head=insertAfter(NULL,ins,head);
    tmp=head;
    printf("\n\n\n");
    while (tmp!=NULL)
    {
        printf("%d\n",tmp->data);
        tmp=tmp->next;
    }
    return 0;
}