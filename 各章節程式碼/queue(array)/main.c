#include <stdio.h>
#define MAXQ 100

int queue[MAXQ];
int front = -1;
int tail =-1;

void Push(int a){
    if(tail==MAXQ)
        printf("佇列已滿");
    else
        queue[++tail] = a;
}

int pop(){
    return queue[++front];
}

int isempty(){
    if(front==tail)
        return 1;
    else
        return 0;
}

int main() {
    for(int i =0; i<5;i++){
        Push(i);
    }

    while(!isempty()){
        printf("佇列刪除的資料為:%d\n",pop());
    }
    return 0;
}
