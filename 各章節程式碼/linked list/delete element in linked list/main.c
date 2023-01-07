#include <stdio.h>

typedef struct node{
    char alpha;
    struct node *next;
}node;

int main() {
    char letter[4]={'W','E','A','R'};
    char target = 'E';
    node a[4];
    node *now = &a[0];
    node *pre = &a[0];


    for(int i=0;i<4;i++){
        now->alpha = letter[i];
        if(i==3){
            now->next = 0;
        }else{
            now->next = &a[i+1];
        }
        printf("[%d] %c %x\n",i,now->alpha,now->next);
        now = now->next;
    }
    now = &a[0];
    while(now){
        if(now->alpha == target){
            pre->next = now->next;
            break;
        }
        pre = now;
        now = now->next;
    }

    printf("\nAfter delete 'E' \n");
    now = &a[0];
    for(int i=0;i<3;i++){
        printf("[%d] %c %x\n",i,now->alpha,now->next);
        now = now->next;
    }





    return 0;
}
