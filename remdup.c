#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node* remDup(Node* head)
{
    Node *curr, *fut;
    if(head!=NULL && head->next!=NULL)//atleast 2
    {
        curr=head;
        fut=head->next;
        while(fut!=NULL)
        {
            if(curr->data==fut->data)
            {
                Node* tmp=fut;
                curr->next=fut->next;
                fut=fut->next;
                free(tmp);
            }
            else
            {
                curr=fut;
                fut=fut->next;
            }
        }
    }
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
    head->data = 3;
    head->next = second;
    
    second->data = 3;
    second->next = third;
   
    third->data = 3;
    third->next = ins;

    ins->data=3;
    ins->next=NULL;
    tmp=head;
    while (tmp!=NULL)
    {
        printf("%d\n",tmp->data);
        tmp=tmp->next;
    }

    head=remDup(head);
    tmp=head;
    printf("\n\n\n");
    while (tmp!=NULL)
    {
        printf("%d\n",tmp->data);
        tmp=tmp->next;
    }
    return 0;
}