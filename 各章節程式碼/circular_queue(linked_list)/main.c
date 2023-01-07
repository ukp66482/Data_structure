#include<stdio.h>
#include<stdlib.h>
//circular queue

struct node
{
    int data;
    struct node* next;
};
struct node *f = NULL;
struct node *r = NULL;

void enqueue(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if(f == NULL && r == NULL)
    {
        f = r = temp;
        return;
    }
    r->next = temp;//linking the new node to the last node
    r = temp;//making the new node as the last node
    temp->next = f;//linking the last node to the first node
    r->next = f;
}
int dequeue()
{
    int x;
    struct node* temp = f;
    if(f == NULL)
    {
        printf("Queue is empty");
    }
    if(f == r)//if there is only one node in the queue
    {
        f->data = x;
        f = r = NULL;
        return x;
    }
    else
    {
        x = f->data;
        f = f->next;
        r->next = f;
        return x;
    }
    free(temp);
}