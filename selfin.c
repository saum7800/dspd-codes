#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node* selectionSort(Node* lptr)
{
    Node *i_prev,*i_curr,*j_prev,*j_curr,*m_prev,*m_curr;
    Node *head=lptr;
    i_prev=NULL;
    i_curr=head;
    m_prev=NULL;
    m_curr=head;
    while(i_curr!=NULL)
    {
        if(i_curr->data<m_curr->data)
        {
            m_prev=i_prev;
            m_curr=i_curr;
        }
        i_prev=i_curr;
        i_curr=i_curr->next;
    }
    m_prev->next=m_curr->next;
    m_curr->next=head;
    head=m_curr;
    i_curr=head->next;
    i_prev=head;
    while(i_curr->next!=NULL)
    {
        j_prev=i_curr;
        j_curr=i_curr->next;
        m_prev=i_prev;
        m_curr=i_curr;
        while(j_curr!=NULL)
        {
            if(j_curr->data<m_curr->data)
            {
                m_prev=j_prev;
                m_curr=j_curr;
            }
            j_prev=j_curr;
            j_curr=j_curr->next;
        }
        i_prev->next=m_curr;
        m_prev->next=i_curr;
        Node *tmp=m_curr->next;
        m_curr->next=i_curr->next;
        i_curr->next=tmp;
        
        i_prev=m_curr;
        i_curr=i_prev->next;
    }
    return head;
}

int main()
{
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
    list = selectionSort(list);
    printf("\n\n\n");
    while (list != NULL)
    {
        printf("%d\n", list->data);
        list = list->next;
    }
    //printf("\n\n%d\n\n",list->data);
}