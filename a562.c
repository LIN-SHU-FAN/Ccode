#include<cstdio>
int A[110];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)scanf("%d",&A[i]);
        //run
        int now=0,go=1;
        for(int len=n;len>0;len--){
            for(int t=0;t<len;t++){
                //walk
                if(t)putchar(' ');
                printf("%d",A[now]);
                now+=go;
            }
            now-=go;
            puts("");
            go=-go;
        }
    }
    return 0;
}
