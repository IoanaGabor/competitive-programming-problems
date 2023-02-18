#include <iostream>
#include <fstream>
#define NMAX 100000
#define MOD 20173333

using namespace std;

ifstream f("sirul2.in");
ofstream g("sirul2.out");

long long cerinta,n,x,fact[NMAX+5],sol,dp[NMAX+5];

long long putere(long long b,long long e){
    long long rez=1;
    while(e){
        if(e%2==0){
            b=(b*b)%MOD;
            e=e/2;
        }else{
            rez=(rez*b)%MOD;
            e--;
        }
    }
    return rez;
}

int main() {
    f>>cerinta>>n>>x;
    if(cerinta==1){
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<=n-1;i++){
            fact[i]=(1LL*fact[i-1]*i)%MOD;
        }
        sol=(((1LL*fact[n-1]*putere(fact[x-1],MOD-2))%MOD)*putere(fact[n-x],MOD-2))%MOD;
        g<<sol;
    }else{
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=2*dp[i-1];
            if(i-x-1>=0){
                dp[i]-=dp[i-x-1];
            }
            if(dp[i]<0){
                dp[i]+=MOD;
            }
            dp[i]%=MOD;
        }
        g<<dp[n];
    }
    f.close();
    g.close();
    return 0;
}
