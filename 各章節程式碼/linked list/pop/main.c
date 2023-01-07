#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char alpha;
    struct node *next;
}node;

void printNode(node *now);
void push(node **stack,char letter);
void pop(node **stack);
int main() {
    node *head = 0;
    push(&head , 'U');
    push(&head , 'K');
    push(&head , 'C');
    push(&head , 'N');
    // head is on the top of stack
    printNode(head);
    pop(&head);
    printNode(head);
    pop(&head);
    printNode(head);
    pop(&head);
    printNode(head);
    pop(&head);
    printNode(head);
    return 0;
}

void printNode(node *now){
    while(now){
        printf("%c ",now->alpha);
        now = now->next;
    }
    printf("\n");
}

void push(node **stack,char letter){
    node *new_node = (node*) malloc(sizeof (node));
    new_node->alpha = letter;
    new_node->next = *stack;
    *stack = new_node;
}

void pop(node **stack){
    node *temp = *stack;
    *stack = temp->next;
    free(temp);
}