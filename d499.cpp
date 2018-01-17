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
    LL a ,n ;

    while (~scanf("%lld%lld",&a ,&n )){
        big_int Ans(1) ,D(a) ,C ;
        while (n){
            if (n&1)C=Ans*D ,Ans=C ;
            C=D*D,D=C ;
            n/=2 ;
        }
        Ans.output() ;
    }
}
