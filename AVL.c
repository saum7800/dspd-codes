#include<stdio.h>
#include<stdlib.h>

typedef struct Tree_Node
{
    int data;
    int height;
    struct Tree_Node* left;
    struct Tree_Node* right;
    struct Tree_Node* parent;
    
}Tree_Node;

Tree_Node* createNode(int data)
{
    Tree_Node* new=(Tree_Node*)malloc(sizeof(Tree_Node));
    new->data=data;
    new->height=1;
    new->parent=NULL;
    new->left=NULL;
    new->right=NULL;
    return new;
}

int height(Tree_Node* node)
{
    if(node==NULL)
    return 0;
    else
    return node->height;
}

int max(int a, int b)
{
    if(a>b)
    return a;
    else
    return b;
}

void rightRotate(Tree_Node* z)
{
    Tree_Node* parent = z->parent;
    Tree_Node* y = z->left;
    Tree_Node* T3 = y->right;
    if(parent!=NULL)
    {
        if(parent->right == z)
        parent->right = y;
        else
        parent->left = y;
    }
    z->parent = y;
    y->parent = parent;

    z->left = T3;
    y->right = z;
    
    if(T3!=NULL)
    T3->parent = z;

    z->height = max(height(z->left),height(z->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
}

void leftRotate(Tree_Node* z)
{
    Tree_Node* parent = z->parent;
    Tree_Node* y = z->right;
    Tree_Node* T3 = y->left;
    if(parent!=NULL)
    {
        if(parent->right == z)
        parent->right = y;
        else
        parent->left = y;
    }
    z->parent = y;
    y->parent = parent;

    z->right = T3;
    y->left = z;
    
    if(T3!=NULL)
    T3->parent = z;

    z->height = max(height(z->left),height(z->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
}

Tree_Node* check_and_update(Tree_Node* node)
{
    Tree_Node* prev = node;
    Tree_Node* final_root = NULL;
    while(prev!=NULL)
    {
        prev->height = max(height(prev->left),height(prev->right)) + 1;
        int imbalance = height(prev->left) - height(prev->right);
        if(imbalance>1) //
        {
            if(height(prev->left->left) >= height(prev->left->right))
            {
                rightRotate(prev);
            }
            else
            {
                leftRotate(prev->left);
                rightRotate(prev);
            }
        }
        else if(imbalance<-1)
        {
            if(height(prev->right->left) <= height(prev->right->right))
            {
                leftRotate(prev);
            }
            else
            {
                rightRotate(prev->right);
                leftRotate(prev);
            }
        }
        final_root = prev;
        prev = prev->parent;
    }
    return final_root;
}

Tree_Node* insert(Tree_Node* root, int data)
{
//    Tree_Node *upper, *middle, *lower;
    Tree_Node* final_root;
    Tree_Node* newNode = createNode(data);
    if(root==NULL)
    {
        root=newNode;
        final_root = root;
    }
    else
    {
        int right=0;
        Tree_Node* prev= NULL;
        Tree_Node* curr= root;
        while(curr!=NULL)
        {
//            curr->height = curr->height + 1;
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
        
        newNode->parent = prev;

        while(prev!=NULL)
        {
            prev->height = max(height(prev->left),height(prev->right)) + 1;
            int imbalance = height(prev->left) - height(prev->right);
            if(imbalance>1) //
            {
                if(data<prev->left->data)
                {
                    rightRotate(prev);
                }
                else
                {
                    leftRotate(prev->left);
                    rightRotate(prev);
                }
            }
            else if(imbalance<-1)
            {
                if(data>prev->right->data)
                {
                    leftRotate(prev);
                }
                else
                {
                    rightRotate(prev->right);
                    leftRotate(prev);
                }
            }
            final_root = prev;
            prev = prev->parent;
        }
    }
    return final_root;
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
        printf("%d-%d\n",root->data,root->height);
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
    Tree_Node *parent, *curr, *final_root;
    int right=0;
    parent=NULL;
    curr=root;
    final_root = root;
    
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
                parent->right = curr->right;
            else
                parent->left = curr->right;
            curr->parent = parent;
            final_root = check_and_update(parent);
        }
        else
        {
            root = root->right;
            root->parent = NULL;
            final_root = check_and_update(root);
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
            curr->parent = parent;
            final_root = check_and_update(parent);
        }
        else
        {
            root = root->left;
            root->parent = NULL;
            final_root = check_and_update(root);
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
            curr->left->parent = succ;
        }
        else
        {
            prev_succ->left = succ->right;
            if(succ->right!=NULL)
            succ->right->parent = prev_succ;

            succ->right = curr->right;
            curr->right->parent = succ;

            succ->left = curr->left;
            curr->left->parent = succ;
        }

        if(parent != NULL)
        {
            if(right)
            parent->right = succ;
            else
            parent->left = succ;
            
            succ->parent = parent;

            if(flag == 0)
            final_root = check_and_update(succ);
            else
            final_root = check_and_update(prev_succ);
        }
        else
        {
            root = succ;
            succ->parent = NULL;
            final_root = check_and_update(root);
        }            
        free(curr);
    }
    return final_root;
}

int main()
{
    Tree_Node* root = NULL;
    int data;
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
    printf("\n\n\n");
//    Tree_Node* searchedElement=search(root, 7);
    //searchedElement=search(root, 14);
//    root=delete(root,18);
//    VLR(root);*/
    while(1)
    {
        scanf("%d",&data);
        root = delete(root, data);
        printf("\n");
        VLR(root);
        printf("\n");
    }
    return 0;
}