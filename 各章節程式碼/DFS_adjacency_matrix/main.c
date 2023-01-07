#include <stdio.h>
#include <stdlib.h>

int** matrix_INI(int m){

    int **matrix = (int**) malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++){
        matrix[i] = (int*) calloc(m,sizeof(int));
    }
    return matrix;
}
void DFS(int**matrix,int *visited,int start,int vertex_num){

    printf("%d ",start);
    visited[start] = 1;

    for(int j=0;j<vertex_num;j++){
        if( !visited[j] && matrix[start][j] == 1){
            DFS(matrix,visited,j,vertex_num);
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
