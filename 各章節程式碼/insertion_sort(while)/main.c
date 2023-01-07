#include <stdio.h>

int main() {
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    for(int i=1;i<10;i++) {
        int n = i;
        while (n >= 0) {
            if (arr[n] < arr[n - 1]) {
                int temp = arr[n];
                arr[n] = arr[n - 1];
                arr[n - 1] = temp;
            }
            n--;
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
