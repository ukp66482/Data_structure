#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char alpha;
    struct node *next;
}node;

void printNode(const node* now);
void push(node **stack,char letter);

int main() {
    node *head = 0;
    push(&head,'U');
    push(&head,'K');
    push(&head,'C');
    push(&head,'N');
    printNode(head);
    return 0;
}

void printNode(const node* now){
    while(now){
        printf("%c ",now->alpha);
        now = now->next;
    }
    printf("\n");
}

void push(node *stack,char letter){
    node *temp = (node*) malloc(sizeof(node));
    temp->alpha = letter;
    temp->next = stack;
    stack = temp;
}