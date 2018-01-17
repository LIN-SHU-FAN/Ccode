#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

typedef long long int LL ;
const LL Unite =100000000 ;

struct big_int {
    //member ----------------
    int len ;
    vector<LL> ele ;
    big_int (LL a =0){
        len=1 ;
        ele.resize(1) ;
        ele[0]=a ;
    }
    void output(){
        printf("%lld",ele[len-1]) ;
        for (int i=len-2 ;i>=0 ;i-- ){
            printf("%08lld",ele[i]) ;
        }
        puts("") ;
    }
    int digitsum(){
        int sum=0 ;
        for (int i=0 ;i<ele.size();i++){
			int e= ele[i] ;
            while (e){
				sum+=e%10 ;
				e/=10 ;
            }
        }
        return sum ;
    }
};
big_int operator * (big_int A ,big_int B ){
    big_int C ;
    C.ele.resize( A.len +B.len ) ;
    C.len=A.len+B.len ;
    fill(C.ele.begin() ,C.ele.end() ,0 ) ;

    for (int i=0 ;i<A.len ;i++ )
        for (int j=0 ;j<B.len ;j++ )
            C.ele[ i+j ]+=A.ele[i]*B.ele[j] ;

    for (int i=0 ;i<C.len ;i++ ){
        C.ele[i+1]+=C.ele[i]/Unite ;
        C.ele[i]%=Unite ;
    }
    int d=C.len ;while (d>1 && C.ele[d-1]==0 )d-- ;
    C.ele.resize(d) ;
    C.len=d ;

    return C ;
}

int main(){
    int n=1000 ;
    big_int Ans(1) ,D(2) ;
    while (n){
        if (n&1)Ans=Ans*D ;
        D=D*D ;
        n=n>>1 ;
    }
    //Ans.output() ;
    printf("%d\n",Ans.digitsum()) ;
}
