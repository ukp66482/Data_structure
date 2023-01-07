#include <stdio.h>
typedef struct node{
    char alpha;
    struct node *next;   // node type ptr (not int char.....)
}Node;
int main() {
    Node a,c,t;
    a.alpha = 'A';
    a.next = &c;
    a.next ->alpha = 'C';
    a.next ->next = &t;
    a.next ->next ->alpha = 'T';
    a.next ->next ->next = 0;
    Node *now = &a;
    while(now){
        printf("%c ",now->alpha);
        now = now->next;
    }



    return 0;
}
