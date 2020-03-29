#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node* changeStart(int k,Node* head)
{
    Node *first, *kth, *k_plus_one, *last;
    first=head;
    int trav=1;
    while(head!=NULL)
    {
        if(k==trav)
        kth=head;
        else if(trav==k+1)
        k_plus_one=head;
        
        if(head->next==NULL)
        last=head;
        
        trav++;
        head=head->next;
    }
    head=k_plus_one;
    last->next=first;
    kth->next=NULL;
    return head;
}

int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *ins = NULL;
    Node *last;
    Node *tmp;
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    ins = (Node *)malloc(sizeof(Node));
    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;
   
    third->data = 3;
    third->next = NULL;
    tmp=head;
    while (tmp!=NULL)
    {
        printf("%d\n",tmp->data);
        tmp=tmp->next;
    }

    head=changeStart(2,head);
    tmp=head;
    printf("\n\n\n");
    while (tmp!=NULL)
    {
        printf("%d\n",tmp->data);
        tmp=tmp->next;
    }
    return 0;
}