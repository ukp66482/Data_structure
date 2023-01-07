#include <stdio.h>
#include <stdlib.h>
#define MAX 2

int main() {

    int *stack = (int *)malloc(MAX * sizeof(int));
    *stack = 0;
    *(stack + 1) = 1;

    printf("%d %d\n", *stack, *(stack + 1));

    stack = (int *)realloc(stack, 2 * MAX * sizeof(int));

    *(stack + 2) = 2;
    *(stack + 3) = 3;

    printf("%d %d %d %d\n", *stack, *(stack + 1), *(stack + 2), *(stack + 3));

    return 0;
}
