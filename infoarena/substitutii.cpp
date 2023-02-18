#include <bits/stdc++.h>
#define NMAX 200
#define MOD 9999991

using namespace std;

ifstream fi("substitutii.in");
ofstream fo("substitutii.out");

int n,k,teste;
long long fact[NMAX+5],invfact[NMAX+5];

long long logput(long long a,int b){
    long long ret=1LL;
    while(b){
        if(b%2==0){
            b/=2;
            a=(1LL*a*a)%MOD;
        }else{
            b--;
            ret=(1LL*ret*a)%MOD;
        }
    }
    return ret;
}

long long calc(){
    long long ret=0;
    if(k>=2){
        for(int i=2;i<=k;i++){
            ret+=(1LL*((1LL*fact[n-i]*invfact[k-i])%MOD)*(i-1))%MOD;
            ret%=MOD;
        }
        ret=(1LL*ret*fact[k-2])%MOD;
    }else{
        ret=fact[n-1];
    }
    return ret;
}

int main(){
    fact[0]=1;
    invfact[0]=1;
    for(int i=1;i<=NMAX;i++){
        fact[i]=(1LL*fact[i-1]*i)%MOD;
        invfact[i]=logput(fact[i],MOD-2);
    }
    while(fi>>n){
        if(n==0){
            break;
        }
        fi>>k;
        teste++;
        fo<<teste<<":"<<calc()<<'\n';
    }
    fi.close();
    fo.close();
}
