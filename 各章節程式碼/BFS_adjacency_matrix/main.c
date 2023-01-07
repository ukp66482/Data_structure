#include <stdio.h>
#include <stdlib.h>


int** matrix_INI(int m){

    int **matrix = (int**) malloc(sizeof(int*)*m*2);
    for(int i=0;i<m+1;i++){
        matrix[i] = (int*) calloc(m,sizeof(int));
    }
    return matrix;
}

typedef struct queue{
    int front;
    int tail;
    int size;
    int *array;
}queue;

int isEmpty(queue *queue){
    if(queue->front == queue->tail){
        return 1;
    }
        return 0;
}

void enqueue(queue *queue,int j){
    queue->tail++;
    queue->array[queue->tail] = j;
}

int dequeue(queue *queue){
    queue->front++;
    int j = queue->array[queue->front];

    return  j;
}

void BFS(int **matrix,int *visited,int start,int vertex_num,queue *Queue){

    printf("%d ",start);
    visited[start] = 1;
    enqueue(Queue,start);

    while(!isEmpty(Queue)){
        int temp = dequeue(Queue);

        for(int i=0;i<vertex_num;i++){

            if(matrix[temp][i] == 1 && visited[i] == 0){
                printf("%d ",i);
                visited[i] = 1;
                enqueue(Queue,i);
            }
        }
    }
}

int main() {
    int dataset_num,vertex_num,start;
    int **matrix;
    queue *Queue;
    Queue->front =-1;
    Queue->tail = -1;
    Queue->size = 100000;
    Queue->array = calloc(Queue->size,sizeof (int));

    scanf("%d",&dataset_num);

    for(int i=0;i<dataset_num;i++){

        scanf("%d %d",&vertex_num,&start);

        int* visited = calloc(vertex_num,sizeof(int));
        matrix = matrix_INI(vertex_num);


        for(int j = 0; j < vertex_num ; j++){
            for(int k = 0; k < vertex_num ; k++){
                scanf("%d",&matrix[j][k]);
            }
        }

        BFS(matrix,visited,start,vertex_num,Queue);
        printf("\n");
    }
    return 0;
}
