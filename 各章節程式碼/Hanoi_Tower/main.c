#include <stdio.h>

void tower(int n,int start,int other,int end){
    if(n==0){
        return;
    }
    tower(n-1,start,end,other); //將N-1個盤從start移到other
    printf("%d %d %d\n",n,start,end);//底部最大的N 從start 移到 end
    tower(n-1,other,start,end);//將N-1個盤從other移到end
}




int main(void){
    int n;
    scanf("%d",&n);
    tower(n,1,2,3);

}