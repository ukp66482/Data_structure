#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char alpha;
    struct node *next;
}node;

void printNode(const node* now);

int main() {
    node *now = 0;
    node *head = 0;
    for(int i=0;i<5;i++) {
        now = (node *) malloc(sizeof(node));
        now->alpha = 'A' + i;
        now->next = head;
        head = now;
        printNode(head);
    }
    printf("------------------------\n");
    while(head){
        node *del = head;
        head = head->next;
        printNode(head);
        free(del);
    }
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