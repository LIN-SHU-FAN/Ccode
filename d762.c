#include <stdio.h>
bool find(int o[],int m,int n,int count);
int main(){
	int a,b,c,d,e,o[5],arr[5];
	bool flag;
    while(scanf("%d%d%d%d%d",&o[0],&o[1],&o[2],&o[3],&o[4])!=EOF){
        if(!o[0]&&!o[1]&&!o[2]&&!o[3]&&!o[4])break;
        flag=0;
        for(a=0;a<5&&!flag;a++){
        	for(b=0;b<5&&!flag;b++){
        		if(a==b)continue;
        		for(c=0;c<5&&!flag;c++){
        			if(a==c||b==c)continue;
        			for(d=0;d<5&&!flag;d++){
        				if(a==d||b==d||c==d)continue;
        				for(e=0;e<5&&!flag;e++){
        					if(a==e||b==e||c==e||d==e)continue;
							arr[0]=o[a];
							arr[1]=o[b];
							arr[2]=o[c];
							arr[3]=o[d];
							arr[4]=o[e];
							//printf("%d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4]);
							if(find(arr,arr[0],arr[1],2))flag=1;
						}	
        			}	
        		}		
        	}	
        }	
	    if(flag)printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}
bool find(int o[],int m,int n,int count){
    if(count==5){
        if(m+n==23)return 1;
        if(m-n==23)return 1;
        if(m*n==23)return 1;
        return 0;
    }
    if(find(o,m+n,o[count],count+1))return 1;
    if(find(o,m-n,o[count],count+1))return 1;
    if(find(o,m*n,o[count],count+1))return 1; 
}
