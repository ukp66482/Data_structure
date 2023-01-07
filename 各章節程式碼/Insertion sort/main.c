#include <stdio.h>

int main() {
    int arr[10] ={9,8,7,6,5,4,3,2,1,0};
    printf("Before insertion sort: ");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }

    for(int i=1;i<10;i++){
        int t = arr[i];
        int j;
        for(j=i-1;j>=0 && t<arr[j];j--){
            arr[j+1] = arr[j];
            arr[j] = t;
        }
    }
    printf("\n");
    printf("After insertion sort: ");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
