#include <bits/stdc++.h>
#define KMAX 1000000
#define MOD 1000000007

using namespace std;

ifstream fi("cabana.in");
ofstream fo("cabana.out");

int t;
long long n,k;
int fact[KMAX+5];

long long lgpow(long long a, long long b){
    long long ret = 1;
    while(b){
        if(b%2==0){
            b/=2;
            a = (a*a)%MOD;
        }else{
            b--;
            ret = (ret*a)%MOD;
        }
    }
    return ret;
}

void init(){
    fact[0]=1;
    for(int i=1;i<=KMAX;i++){
        fact[i]=(1LL*fact[i-1]*i)%MOD;
    }
}

long long compute_sol(){
    
    long long d = n/k, r = n%k;
    long long sol = lgpow(fact[k],d);
    sol = (((sol*fact[k])%MOD)*lgpow(fact[k-r],MOD-2))%MOD;
    return sol;
}

int main(){
    init();
    fi>>t;
    while(t--){
        fi>>n>>k;
        fo<<compute_sol()<<'\n';
    }
}