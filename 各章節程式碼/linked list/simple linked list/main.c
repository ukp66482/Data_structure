#include <stdio.h>

typedef struct node{
    char alpha;
    struct node *next;
}Node;

int main() {

    Node a,c;
    a.alpha = 'A';
    a.next = &c;
    a.next->alpha = 'C';

    printf("%c %c",a.alpha,c.alpha);

    return 0;
}
