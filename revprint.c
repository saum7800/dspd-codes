#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void printRev(Node* curr, Node* last)
{
    if(curr!=last)
    {
        printRev(curr->next,last);
    }
    printf("%d ",curr->data);
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
    third->next = ins;

    ins->data = 4;
    ins->next=head;
    last=ins;
    //printf("%d ",last->data);
    printRev(last->next,last);
    //printf("\n\n%d\n\n",list->data);
}