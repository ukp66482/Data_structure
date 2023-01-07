#include <stdio.h>
#include <stdlib.h>
int main(void){

    int **iArray;

    iArray = (int **) malloc(sizeof (int*)*3);
    for(int i=0;i<3;i++){
        iArray[i] =(int *) calloc(0,(sizeof (int)*3));
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ", iArray[i][j] );
        }
        printf("\n");
    }


    for(int i=0;i<3;i++){
        free(iArray[i]);
    }

    free(iArray);

    return 0;
}
