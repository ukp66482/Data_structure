#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    int value;
}Node;

typedef struct Minheap{
    Node *array;
    int size_now;
}Minheap;

int parent(int i){
    return (i-1)/2;
}

int leftnode(int i){
    return (2*i+1);
}

int rightnode(int i){
    return (2*i+2);
}

Minheap* initial() {
    Minheap *minheap = (Minheap *) malloc(sizeof(Minheap));
    minheap->array = (int *) malloc(sizeof(int) * 1000);
    minheap->size_now = 0;
    return minheap;
}

int swim(Minheap* minheap,int index){

    int now = index;
    while(now>0 && minheap->array[parent(now)]>minheap->array[now]){
        int temp = minheap->array[parent(now)];
        minheap->array[parent(now)] = minheap->array[now];
        minheap->array[now] = temp;
        now = parent(now);
    }
    return now;
}

Minheap* sink(Minheap* minheap,int index){
    if(minheap->size_now<=1)
        return minheap;

    int left = leftnode(index);
    int right = rightnode(index);

    int smallest = index;

    if(left < minheap->size_now && minheap->array[left] < minheap->array[index]){
        smallest = left;
    }
    if(right < minheap->size_now && minheap->array[right] < minheap->array[smallest]){
        smallest = right;
    }
    if(smallest != index){
        int temp = minheap->array[index];
        minheap->array[index] = minheap->array[smallest];
        minheap->array[smallest] = temp;
        minheap = sink(minheap,smallest);
    }
    return minheap;
}

Minheap* insert(Minheap* minheap,int data){
    minheap->size_now++;
    int now = minheap->size_now - 1;
    minheap->array[now] = data;

    swim(minheap,now);

    return minheap;
}

Minheap* Remove(Minheap* minheap){
    if(minheap->size_now == 0){
        printf("empty\n");
        return minheap;}
    int size = minheap->size_now;
    int last_data = minheap->array[size-1];

    printf("%d\n",minheap->array[0]);

    minheap->array[0] = last_data;
    minheap->size_now--;

    minheap = sink(minheap,0);
    return minheap;
}

void change(Minheap* minheap,int index,int data){
    if(minheap->size_now-1 >= index && index >= 0){
        minheap->array[index] = data;

        swim(minheap,index);
        sink(minheap,index);

    }
    else{
        printf("out of range\n");
    }
}


int main() {
    Minheap* minheap = initial();
    char cmd[7]={0};
    int num,x;

    while (1) {
        fgets(cmd,7,stdin);

        if (cmd[0] == 'q') {

            exit(0);
        }
        if (cmd[0] == 'i') {
            scanf(" %d", &num);
            insert(minheap, num);
        }
        if (cmd[0] == 'r') {
            Remove(minheap);
        }
        if (cmd[0] == 'c') {
            scanf(" %d,%d", &x, &num);
            change(minheap, x, num);
        }
    }
    return 0;
}
