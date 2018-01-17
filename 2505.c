//http://163.32.63.202/show.php?2505

#include <stdio.h>
int main()
{
int H,W;
scanf("%d%d",&H,&W);
char DNA[H][W];
int dp[H][W];
int res[H*W/4];
int startX,startY;//record start point
int count,tmp,s,result=0,sum=0;
unsigned long long multi=1;


for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
            scanf(" %c",&DNA[i][j]);//scan DNA
            if(DNA[i][j]=='.')//copy to reference
                dp[i][j]=1;
            else
                dp[i][j]=0;
    }
}

for(int i=0;i<H-1;i++){
    for(int j=0;j<W-1;j++){

        if(dp[i][j]==1 && dp[i+1][j]==1 && dp[i][j+1]==1){
                startX=j;
                startY=i;
                count=1;//counting point.
                dp[i][j]=0;
                while(!(i==startY+1 && j==startX)){//check end point if it is [i-1][j]
                    tmp=count;//check if need to break
                    while(++j<W && dp[i][j]==1){
                        count++;
                        dp[i][j]=0;
                    }
                    j--;
                    while(++i<H && dp[i][j]==1){
                        count++;
                        dp[i][j]=0;
                    }
                    i--;
                    while(--i>=0 && dp[i][j]==1){
                        count++;
                        dp[i][j]=0;
                    }
                    i++;
                    while(--j>=0 && dp[i][j]==1){
                        count++;
                        dp[i][j]=0;
                    }
                    j++;
                    if(tmp==count)break;//check if need to break

                }
                if(i==startY+1 && j==startX){
                    res[result]=count;
                    result++;
                }
            j=startX;
            i=startY;
    }else{
       dp[i][j]=0;
    }

    }
}

for(int i=0;i<result;i++){
    multi*=res[i];
    sum+=res[i];
}
printf("%d %d %llu\n",result,sum,multi);

}

