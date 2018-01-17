//http://163.32.63.202/show.php?2533

#include <stdio.h>
#include <limits.h>
int main()
{
    long long  m,a,b;
    long long x1=0,y1=0,t=1,y,x2,y2;
    long long  max=LLONG_MIN;
    scanf("%lld%lld%lld",&m,&a,&b);
    while(1){
        if((m-b*y1)%a==0){
            break;
        }
        y1--;
    }
        y=y1;
    while(1){
        x1=(m-b*y1)/a;
        if(x1*y1>max){
            max=x1*y1;
            x2=x1;
            y2=y1;
        }else{
            if(t==-1)break;
            y1=y;
            t=-1;
        }
        y1=y1+a*t;
    }
    printf("%lld\n%lld",x2,y2);
    return 0;
}

