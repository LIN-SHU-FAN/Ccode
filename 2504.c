//http://163.32.63.202/show.php?2504
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int N;
    double Area=0.0;
    scanf("%d",&N);
    int A[N][3];
    for(int i=0;i<N;i++){
        scanf("%d%d%d",&A[i][0],&A[i][1],&A[i][2]);
        A[i][0]*=10;
        A[i][1]*=10;
        A[i][2]*=10;
    }
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            for(int k=0;k<N;k++){
                if(pow((A[k][0]-j),2)+pow((A[k][1]-i),2)<=pow((A[k][2]),2)){
                Area+=0.01;
                break;
                }
            }
        }
    }
    int s;
    s=floor(Area+0.5);
    printf("%d",s);
    return 0;
}

