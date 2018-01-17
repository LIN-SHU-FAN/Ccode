//http://163.32.63.202/show.php?2509



#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i;
    int trip=0,dir=-1;
    scanf("%d",&N);
    int A[N+1],P[N+1];
    for(i=1;i<=N;i++){
        scanf("%d",&A[i]);
        P[A[i]]=i;
    }
    for(i=1;i<=N;i++){
        dir*=-1;
    if(dir>0){
        while(P[i+1]>P[i])
            i++;
            trip++;
    }else{
        while(P[i+1]<P[i])
            i++;
            trip++;
    }
    }
    printf("%d",--trip);
    return 0;
}

