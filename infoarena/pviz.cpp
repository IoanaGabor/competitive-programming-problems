
#include <bits/stdc++.h>
#define NMAX 2000
#define MOD 10007

using namespace std;

ifstream fi("pviz.in");
ofstream fo("pviz.out");

int n,m,v[NMAX+5];
int dp[NMAX+5][NMAX+5];
int maxn[NMAX+5];

int main(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>v[i];
    }
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min(i,m);j++){
            if(i!=1||j!=1){
                if(v[j]>=i){
                    dp[i][j]=dp[i-1][j-1];
                    dp[i][j]+=(v[j]-i+1)*dp[i-1][j];
                    dp[i][j]%=MOD;
                }
            }
        }
    }
    fo<<dp[n][m];
    fi.close();
    fo.close();
}
