#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node* insertAtBetweeen(Node* head, Node* p, Node* q)
{
    Node *one,*two;
    one=head;
    two=head;

    while(two!=NULL)
    {
        one=one->next;
        two=two->next;
        if(two!=NULL)
        two=two->next;
    }

    q->next=one->next;
    p->next=q;
    one->next=p;
    return head;
}

int main()
{
    Node *second = NULL;
    Node *third = NULL;
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    second->data = 2;
    third->data = 3;
    Node *list = NULL;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a;
        scanf("%d", &a);
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = a;
        newNode->next = list;
        list = newNode;
    }
    list = insertAtBetweeen(list,second,third);
    printf("\n\n\n");
    while (list != NULL)
    {
        printf("%d\n", list->data);
        list = list->next;
    }
    //printf("\n\n%d\n\n",list->data);
}