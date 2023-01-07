#include <stdio.h>
#include <stdlib.h>
int main() {
    int **array = (int **) malloc(sizeof (int*)*2);
    for(int i=0;i<2;i++){
        array[i] = (int*) malloc(sizeof (int)*3);
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            array[i][j] = i+j ;
        }
    }

    printf("Before 2*3 array\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }

    int *row_array = (int*)malloc(sizeof(int)*(2*3));

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            row_array[j+i*3] = array[i][j];
        }
    }

    printf("\nAfter row mapping\n");

    for(int i=0;i<2*3;i++){
        printf("%d ",row_array[i]);
    }



    return 0;
}
