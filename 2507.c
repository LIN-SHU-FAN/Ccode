//http://163.32.63.202/show.php?2507

#include <stdio.h>
#include <stdlib.h>
int main(){
int N,len=0,start,end,A,B,tmp;

scanf("%d",&N);
tmp=N;
while(tmp){
    tmp/=10;
    len++;
}

switch(len){
case 7:
    start=12;
    end=98;
    break;
case 6:
    start=123;
    end=987;
    break;
case 5:
    start=1234;
    end=9876;
    break;
case 4:
    start=1234;
    end=9876;
    break;
}

for(int i=start;i<=end;i++){

    int num[10]={0};
    int count=0;

    B=i;
    while(i){
        if(num[i%10]==0 && i%10!=0){
            num[i%10]++;
            i/=10;
            count++;
        }else{
            break;
        }
    }

    A=N+B;
    i=A;
    while(i){
        if(num[i%10]==0 && i%10!=0){
            num[i%10]++;
            i/=10;
            count++;
        }else{
            break;
        }
    }
if(count==9){
    printf("%d-%d=%d\n",A,B,N);
}
i=B;
}


}

