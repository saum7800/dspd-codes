#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void printFrom(int n, Node* last)
{
    Node *tmp=last;
    tmp=tmp->next;
    int done=0,one_round_done=0,tot=1,move;
    while (!done)
    {
        if(!one_round_done)
        {
            if(tmp==last)
            {
                one_round_done=1;
                move=tot-n;
            }
            else
            {
                tot++;
                tmp=tmp->next;
            }
        }
        else
        {
            if(move!=0)
            {
                tmp=tmp->next;
                move--;
            }
            else
            {
                done=1;
            }
        }
    }
    printf("Data:%d\n\n",tmp->data);
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
    third->next = head;
    last=third;
    printFrom(0,last);
/*    tmp=head;
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
    }*/
    return 0;
}