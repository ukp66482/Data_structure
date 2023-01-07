#include <stdio.h>
#include <stdlib.h>
#define capacity 10
int top = -1;
int stack[capacity] = {0};     //stack = 1,2,3,4,5,(top)   top is the next element

void Isempty();
void Isfull();
int Top();
void push(int x);
void pop();
void printstack();
void doublearray();

int main() {
    push(3);
    push(5);
    push(4);
    printstack();
    Top();
    pop();
    printstack();
    Top();
    return 0;
}
void Isempty(){
    if(top == 0){
        printf("The stack is empty top == 0\n");
    }
}

void Isfull(){
    if(top == capacity){
        printf("The stack is full now\n");
    }
}

int Top(){
    printf("Top = %d\n",top);
}

void push(int x) {
    if (top != capacity) {
        stack[++top] = x;
    }else {
        printf("The stack is FULL\n");
    }
}

void pop(){
    if(top != -1) {
        top--;
    }else if(top == -1){
        stack[top] = 0;
    }
}

void printstack(){
    for(int i=0;i<=top;i++){
        printf("[%d] = %d ",i,stack[i]);
    }
    printf("\n");
}

