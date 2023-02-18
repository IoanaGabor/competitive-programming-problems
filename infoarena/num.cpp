#include <bits/stdc++.h>
#define NMAX 2000
#define MOD 1000000007

using namespace std;

ifstream fi("num.in");
ofstream fo("num.out");

int n,m;
long long d[NMAX+5][NMAX+5];
long long fact[2*NMAX+5],invfact[2*NMAX+5];
long long sol;
int cntrest[NMAX+5];

long long invmod(long long nr){
    int p=MOD-2;
    long long ret=1LL;
    while(p){
        if(p%2==0){
            nr=(nr*nr)%MOD;
            p/=2;
        }else{
            ret=(ret*nr)%MOD;
            p--;
        }
    }
    return ret;
}

long long comb(int n,int k){
    return (((fact[n]*invfact[k])%MOD)*invfact[n-k])%MOD;
}

int main(){
    fi>>n>>m;
    fact[0]=1;
    invfact[0]=1;
    for(int i=1;i<=2*n;i++){
        fact[i]=(fact[i-1]*i)%MOD;
        invfact[i]=invmod(fact[i]);
    }
    for(int i=1;i<=2*n;i++){
        if(i%m==0){
            cntrest[m]++;
        }else{
            cntrest[i%m]++;
        }
    }
    d[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            d[i][j]=0;
            for(int k=0;2*k<=cntrest[i]&&k<=j;k++){
                d[i][j]+=d[i-1][j-k]*fact[cntrest[i]]%MOD*invfact[cntrest[i]-2*k]%MOD*comb(j,k)%MOD;
                d[i][j]%=MOD;
            }
        }
    }
    sol=fact[2*n];
    for(int i=1;i<=n;i++){
        if(i%2==0){
            sol=(sol+((((comb(n,i)*fact[2*n-2*i])%MOD)*d[m][i])%MOD)+MOD)%MOD;
        }else{
            sol=(sol-((((comb(n,i)*fact[2*n-2*i])%MOD)*d[m][i])%MOD)+MOD)%MOD;
        }
    }   
    fo<<sol<<'\n';
}