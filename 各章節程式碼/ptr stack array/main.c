#include <stdio.h>
#include <stdlib.h>
typedef struct stackarray{
    int top;
    int x;
    int *next;
}stackarray;

void push(stackarray *stack,int x);

int main() {
    int capacity = 10;
    stackarray *stack =(stackarray*) malloc(sizeof (capacity));
    stack[0].top=0;
    stack[0].x=0;
    stack[0].next = 0;
}

void push(stackarray *stack,int x){
    stackarray *now;
    
}