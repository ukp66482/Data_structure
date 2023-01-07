#include <stdio.h>
#include <stdlib.h>

int stack[1000];
int top=-1;

void push(int data){
    stack[++top] = data;
}

int pop(){
    return stack[top--];
}

int peek(){
    return stack[top];
}

int** matrix_INI(int m){

    int **matrix = (int**) malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++){
        matrix[i] = (int*) calloc(m,sizeof(int));
    }
    return matrix;
}

int getunvisited(int n,int **matrix,int *visited,int vertex_num){
    for(int i = 0;i<vertex_num;i++){
        if(matrix[n][i]==1 && visited[i] == 0){
            return i;
        }
    }
    return -1;
}

void DFS(int**matrix,int *visited,int start,int vertex_num){

    printf("%d ",start);
    visited[start] = 1;
    push(start);

    while(top!=-1){
        int unvisited = getunvisited(peek(),matrix,visited,vertex_num);
        if(unvisited == -1){
             pop();
        }else{
            visited[unvisited] = 1;
            printf("%d ",unvisited);
            push(unvisited);
        }
    }
}

int main() {
    int dataset_num,vertex_num,start;
    int **matrix;

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

        DFS(matrix,visited,start,vertex_num);
        printf("\n");

    }
    return 0;
}
