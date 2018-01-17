#include <stdio.h>
void swap(int &a,int &b);
int main(){
    int N,i,j,a[1005],count;
    while(scanf("%d",&N)!=EOF){
        for(i=0;i<N;i++)scanf("%d",&a[i]);
        count=0;
        for(i=N-1;i>0;i--){
            for(j=0;j<i;j++){
                if(a[j]>a[j+1])swap(a[j],a[j+1]),count++;
            }
        }
        printf("Minimum exchange operations : %d\n",count);
    }
    return 0;
}
void swap(int &a,int &b){
    int t=a;a=b;b=t;
}
