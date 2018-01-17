#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
void init();
map<string,char> M;
int main(){
    init();
    char s[1000];
    while(fgets(s,sizeof(s),stdin)){
        int len=strlen(s);
        for(int i=0;i<len;i++){
            if((s[i]>='A'&&s[i]<='Z')||s[i]==' ')putchar(s[i]);
            else if(s[i]>='0'&&s[i]<='9'){
                int L=i,R=L;
                //printf("L=%d R=%d\n",L,R);
                while(R+1<len&&s[R+1]>='0'&&s[R+1]<='9'){
                    R++;
                    if(s[R]=='0')break;
                    else if(R>L&&s[R]<s[R-1]){R--;break;}
                }
                char tmp[10];
                for(int j=L;j<=R;j++)tmp[j-L]=s[j];
                tmp[R-L+1]='\0';
                //printf("tmp=%s\n",tmp);
                string tmp2=tmp;
                if(M.count(tmp2))putchar(M[tmp2]),i=R;
                else{
                    R--;
                    tmp[R-L+1]='\0';
                    tmp2=tmp;
                    //printf("new tmp=%s\n",tmp);
                    if(M.count(tmp2))putchar(M[tmp2]),i=R;
                    else putchar(' ');
                }
            }
        }
        puts("");
    }
    return 0;
}
void init(){
    M["123457"]='A';    M["1234567"]='B';   M["456"]='C';
    M["1580"]='D';      M["12456"]='E';     M["1249"]='F';
    M["12569"]='G';     M["13457"]='H';     M["37"]='I';
    M["3567"]='J';      M["13459"]='K';     M["156"]='L';
    M["12357"]='M';     M["3579"]='N';      M["123567"]='O';
    M["1458"]='P';      M["12347"]='Q';     M["123459"]='R';
    M["12467"]='S';     M["278"]='T';       M["13567"]='U';
    M["1379"]='V';      M["135790"]='W';    M["90"]='X';
    M["1347"]='Y';      M["23456"]='Z';
}
