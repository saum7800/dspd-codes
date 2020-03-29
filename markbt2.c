#include<stdio.h>
#include<stdlib.h>
#define LEFT 0
#define RIGHT 1


typedef struct Tree_Node
{
    int data;
    int marked;
    int par;
    struct Tree_Node* left;
    struct Tree_Node* right;
}Tree_Node;

Tree_Node* createNode(int data)
{
    Tree_Node* new=(Tree_Node*)malloc(sizeof(Tree_Node));
    new->data=data;
    new->marked=0;
    new->par=-1;
    new->left=NULL;
    new->right=NULL;
    return new;
}

Tree_Node* insert(Tree_Node* root, int data)
{
    Tree_Node* newNode = createNode(data);
    if(root==NULL)
    {
        root=newNode;
    }
    else
    {
        int right=0;
        Tree_Node* prev= NULL;
        Tree_Node* curr= root;
        while(curr!=NULL)
        {
            prev=curr;
            if(data>curr->data)
            {
                curr=curr->right;
                right=1;
            }
            else
            {
                curr=curr->left;
                right=0;
            }
        }
        if(right)
            prev->right=newNode;
        else
            prev->left=newNode;
    }
    return root;
}

void LVR(Tree_Node* root)
{
    if(root!=NULL)
    {
        LVR(root->left);
        printf("%d\n",root->data);
        LVR(root->right);
    }
}

void VLR(Tree_Node* root)
{
    if(root!=NULL)
    {
        printf("%d-%d\n",root->data,root->marked);
        VLR(root->left);
        VLR(root->right);
    }
}

void LRV(Tree_Node* root)
{
    if(root!=NULL)
    {
        LRV(root->left);
        LRV(root->right);
        printf("%d\n",root->data);
    }
}

Tree_Node* search(Tree_Node* root, int data)
{
    Tree_Node* retval=NULL;
    int found=0;
    while (!found && root!=NULL)
    {
        if(root->data==data)
        {
            printf("%d found\n",data);
            retval=root;
            found=1;
        }
        else if(root->data<data)
        {
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    if(!found)
        printf("%d not found\n", data);
    return retval;
}

void mark(Tree_Node* root)
{
    Tree_Node* curr = root;
    Tree_Node* prev = NULL;
    Tree_Node* tmp;

    while(curr!=NULL)
    {
        while((curr->left!=NULL && curr->left->marked!=1)||(curr->right!=NULL && curr->right->marked!=1))
        {
            if(curr->left!=NULL && curr->left->marked!=1)
            {
                curr->par = LEFT;
                tmp = curr->left;
                curr->left = prev;
                prev = curr;
                curr = tmp;
            }
            else if(curr->right!=NULL && curr->right->marked!=1)
            {
                curr->par = RIGHT;
                tmp = curr->right;
                curr->right = prev;
                prev = curr;
                curr = tmp;
            }
        }

        curr->marked = 1;
        if(prev == NULL)
        {
            break;
        }
        else
        {
            if(prev->par == LEFT)
            {
                tmp = prev->left;
                prev->left = curr;
            }
            else if(prev->par == RIGHT)
            {
                tmp = prev->right;
                prev->right = curr;
            }
            curr = prev;
            prev = tmp;
        }
    }

}

int main()
{
    Tree_Node* root = NULL;
    root = insert(root, 25);
    root = insert(root, 10);
    root = insert(root, 40);
    root = insert(root, 5);
    root = insert(root, 18);
    root = insert(root, 32);
    root = insert(root, 50);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 21);
    root = insert(root, 28);
    root = insert(root, 35);
    root = insert(root, 45);
    root = insert(root, 55);
    root = insert(root, 8);
    root = insert(root, 47);
    VLR(root);
    mark(root);
    printf("\n\n\n");
    VLR(root);
    return 0;
}