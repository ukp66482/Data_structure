#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *top = NULL; //linked list head

void push(int data) {
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = top;
    top = temp;
}


int pop() {
    node *temp;
    if (top == NULL) {
        printf("Stack is empty");
    } else {
        int x;
        temp = top;
        x = temp->data;
        top = top->next;
        temp->next = NULL;
        free(temp);
        return x;

    }
}



int main() {

    return 0;
}