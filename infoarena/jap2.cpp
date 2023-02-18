
#include <bits/stdc++.h>
#define PMAX 1000007

using namespace std;

ifstream f("jap2.in");
ofstream g("jap2.out");

int p,q;
unsigned long long a,b;
unsigned long long fact[PMAX+5],invfact[PMAX+5];

unsigned long long putere(unsigned long long x,int e){
    unsigned long long ret=1;
    while(e){
        if(e%2==0){
            x=(1ULL*x*x)%p;
            e/=2;
        }else{
            ret=(1ULL*ret*x)%p;
            e--;
        }
    }
    return ret;
}

unsigned long long calc(){
    unsigned long long pp=1;
    unsigned long long ret=1,aa,bb;
    while(pp<=a/p){
        pp*=1ULL*p;
    }
    while(pp){
        aa=a/pp;
        bb=b/pp;
        if(aa>bb){
            ret=(1ULL*ret*fact[aa])%p;
            ret=(1ULL*ret*invfact[bb])%p;
            ret=(1ULL*ret*invfact[aa-bb])%p;
        }else if(aa<bb){
            ret=0;
        }
        a-=aa*pp;
        b-=bb*pp;
        pp/=p;
    }
    return ret;
}

int main(){
    f>>p>>q;
    fact[0]=1;
    invfact[0]=1;
    for(int i=1;i<=p;i++){
        fact[i]=(1LL*fact[i-1]*i)%p;
        invfact[i]=1LL*putere(fact[i],p-2);
    }
    while(q--){
        f>>a>>b;
        g<<calc()<<'\n';
    }
    f.close();
    g.close();
}
