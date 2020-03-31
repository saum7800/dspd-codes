#include<stdio.h>
#include<stdlib.h>

typedef struct Tree_Node
{
    int data;
    struct Tree_Node* left;
    struct Tree_Node* right;
}Tree_Node;

Tree_Node* createNode(int data)
{
    Tree_Node* new=(Tree_Node*)malloc(sizeof(Tree_Node));
    new->data=data;
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
        printf("%d\n",root->data);
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

Tree_Node* delete(Tree_Node* root, int data)
{
    Tree_Node *parent, *curr;
    int right=0;
    parent=NULL;
    curr=root;
    
    while(curr!=NULL && curr->data!=data)
    {
        parent=curr;
        if(curr->data<data)
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

    if(curr->left==NULL)
    {
        if(parent != NULL)
        {
            if(right)
            parent->right=curr->right;
            else
            parent->left=curr->right;
        }
        else
        {
            root = root->right;
        }
        free(curr);
    }
    else if(curr->right==NULL)
    {
        if(parent != NULL)
        {
            if(right)
            parent->right=curr->left;
            else
            parent->left=curr->left;
        }
        else
        {
            root = root->left;
        }
        free(curr);
    }
    else
    {
        Tree_Node* prev_succ=curr;
        Tree_Node* succ=curr->right;
        int flag=0;
        while(succ->left!=NULL)
        {
            prev_succ=succ;
            succ=succ->left;
            flag = 1;
        }
        
        if(flag==0)
        {
            succ->left = curr->left;   
        }
        else
        {
            prev_succ->left = succ->right;
            succ->right = curr->right;
            succ->left = curr->left;
        }
        if(parent != NULL)
        {
            if(right)
            parent->right = succ;
            else
            parent->left = succ;
        }
        else
        {
            root = succ;
        }            
        free(curr);
    }
    return root;
}

int main()
{
    Tree_Node* root = NULL;
    root = insert(root, 25);
    root = insert(root, 10);
    root = insert(root, 40);
    
    VLR(root);
    printf("\n\n\n");
    root=delete(root,25);
    VLR(root);
    return 0;
}