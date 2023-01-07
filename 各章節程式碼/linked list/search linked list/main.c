#include <stdio.h>

typedef struct node{
    char alpha;
    struct node *next;
}Node;

int main() {
    char letter[4]={'A','G','O'};
    char target = 'G';
    Node act[3];
    Node *now = &act[0];

    for(int i=0;i<3;i++){
        now->alpha = letter[i];
        if(i==2){
            now->next = 0;
        }else{
            now->next = &act[i+1];
        }
        printf("[%d]\t%c\t%x\n",i,now->alpha,now->next);
        now = now->next;
    }

    now = &act[0];
    while(now){
        if(now->alpha == target){
            printf("\nFound!!!   ");
            printf("at %x",now);
            break;
        }else{
            now = now->next;
        }
    }


    return 0;
}
