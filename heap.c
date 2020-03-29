#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list
{
    int index;
    char var_name[20];
    int start;
    int size;
    int end;
    struct list* next;
    int buddy_num;
    int buddy_address;
}list;
int heapSize=10;
list *freeList[10];
list *allocList=NULL;

void initFreeList()
{
    for(int i=0;i<heapSize-1;i++)
    {
        freeList[i]=NULL;
    }
    freeList[heapSize-1]=(list*)malloc(sizeof(list));
    freeList[heapSize-1]->start=0;
    freeList[heapSize-1]->end=511;
    freeList[heapSize-1]->size=512;
    freeList[heapSize-1]->index=9;
    freeList[heapSize-1]->var_name[0]='\0';
    freeList[heapSize-1]->next=NULL;
}

void printFreeList()
{
    printf("free list: ");
    for(int i=0;i<heapSize;i++)
    {
        printf("{");
        list* temp=freeList[i];
        while(temp!=NULL)
        {
            printf("(%d,%d)",temp->start,temp->end);
            temp=temp->next;
        }
        printf("},");
    }
    printf("\n");
    printf("Alloc list: ");
    list *tmp=allocList;
    while(tmp!=NULL)
    {
        printf("(%d,%d)->",tmp->start,tmp->end);
        tmp=tmp->next;
    }
    printf("\n");
}

int getIndex(int size)
{
    int ind=-1;
    while(size!=0)
    {
        size/=2;
        ind++;
    }
    return ind;
}

list* getAllockBlock(int index)
{
    if(index==9 && freeList[index]==NULL)
    return NULL;
    else if(freeList[index]==NULL)
    {
        list* retval=getAllockBlock(index+1);
        return retval;
    }
    else
    {
        list* retval=freeList[index];
        while(retval->next!=NULL)
        {
            retval=retval->next;
        }
        return retval;
    }
}

void appendTo(int index,list* new)
{
    if(freeList[index]==NULL)
    {
        freeList[index]=new;
    }
    else
    {
        list* temp=freeList[index];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
}

void updateFreeList(list* block, int index)
{
    if(block->index!=index)
    {
        list* new1=(list*)malloc(sizeof(list));
        new1->start=(block->end + block->start)/2 + 1;
        new1->end=block->end;
        new1->size=block->size/2;
        new1->var_name[0]='\0';
        new1->next=NULL;
        new1->index=block->index-1;
        appendTo(block->index-1,new1);

        list* new2=(list*)malloc(sizeof(list));
        new2->start=block->start;
        new2->end=(block->end + block->start)/2;
        new2->size=block->size/2;
        new2->var_name[0]='\0';
        new2->next=NULL;
        new2->index=block->index-1;
        updateFreeList(new2,index);
    }
    else
    {
        if(allocList==NULL)
        {
            allocList=block;
        //    allocList->next=NULL;
        //    strcpy(allocList->var_name,name);
        }
        else
        {
            list* temp=allocList;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=block;
        }    
    }
    

}

void allocateMemory(int allocSize)
{
    int index=getIndex(allocSize);
    list *blockToAlloc=getAllockBlock(index);
    //printf("(%d,%d)\n",blockToAlloc->start,blockToAlloc->end);
    printf("blockToAlloc index:%d\n",blockToAlloc->index);
    updateFreeList(blockToAlloc,index);
    list *temp=freeList[blockToAlloc->index];
    if(temp->next==NULL)
    {
        freeList[blockToAlloc->index]=NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=blockToAlloc)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        free(blockToAlloc);
    }
}

int main()
{
    initFreeList();
    printFreeList();
    allocateMemory(16);
    printFreeList();
    allocateMemory(16);
    printFreeList();
    allocateMemory(16);
    printFreeList();
    allocateMemory(16);
    printFreeList();
    printFreeList();
}











