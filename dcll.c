#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* insertAtStart(Node* last, Node* p)
{
    if(last==NULL)
    last=p;
    else
    {
        p->next=last->next;
        p->prev=last;
        last->next->prev=p;
        last->next=p;
    }
    return last;
}

Node* deleteAtEnd(Node* last)
{
    Node* tmp=last;
    if(tmp->next==last)
    {
        last=NULL;
    }
    else
    {
        while(tmp->next!=last)
        tmp=tmp->next;
        tmp->next=last->next;
        last->next->prev=tmp;
        Node* tmp2=last;
        last=tmp;
        free(tmp2);
    }
    return last;
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
    head->prev = third;
    
    second->data = 2;
    second->next = third;
    second->prev = head;
    
    third->data = 3;
    third->next = head;
    third->prev = second;
    Node* last = third;
    tmp=last;
    
    do
    {
        printf("%d\n",tmp->data);
        tmp=tmp->next;
    }while(tmp!=last);
    
    ins->data=5;
    ins->next=NULL;
    ins->prev=NULL;
    
    last=insertAtStart(last,ins);
    tmp=last;

    printf("\n\n\n");
    do 
    {
        printf("%d\n",tmp->data);
        tmp=tmp->next;
    }while (tmp!=last);

    last=deleteAtEnd(last);
    tmp=last;

    printf("\n\n\n");
    do 
    {
        printf("%d\n",tmp->data);
        tmp=tmp->next;
    }while (tmp!=last);

    return 0;
}