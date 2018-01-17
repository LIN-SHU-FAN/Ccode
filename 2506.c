//http://163.32.63.202/show.php?2506

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{int N,M,i,sum=0,count=0,temp;
 char *p;
 scanf("%d",&N);    //N=總共有幾個字
 scanf("%d",&M);    //M=幾個字一組
 char A[N+1];
 scanf("%s",A);
 if(A[0]==A[N-1]){
    count++;
    i=N-1;
    while(A[i]==A[i-1] && i>0){//
        count++;
        i--;
    }
    p=&A[i];
   *p='\0';
 }

 if(count==N){
    printf("%d",N);
 }else{
 i=0;
 count++;
temp=strlen(A);
 while(i<temp){
    if(A[i]==A[i+1]){
        count++;
    }else{
        if(count>=M){
            sum+=(count-M+1);
        }
        count=1;
    }
 i++;
 }
 printf("%d",sum);
 }
    return 0;
}





