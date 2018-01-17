#include <stdio.h>
int main() {
	//freopen("in.txt","r",stdin);
	int a,b;
	bool first=1;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(a==0&&b==0)break;
		if(first)first=0;else printf("\n");
		if(a%2==b%2)printf("Win");
		else printf("Loss");
	}
	return 0;
}