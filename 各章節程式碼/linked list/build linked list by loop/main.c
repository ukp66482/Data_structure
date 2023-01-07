#include <stdio.h>
typedef struct node{
    char alpha;
    struct node *next;
}Node;

int main() {
    char letter[3]={'A','C','T'};
    Node act[3];

    Node *now = &act[0];

    for(int i=0;i<3;i++) {
        now->alpha = letter[i];   // now->alpha = letter[i] == *(now.alpha) = letter[i]

        if (i == 2) {
            now->next = 0;
        } else {
            now->next = &act[i + 1];
        }
        printf("[%d]%c,%p\n",i,now->alpha,now->next);
        now = now ->next;
    }

    return 0;
}
