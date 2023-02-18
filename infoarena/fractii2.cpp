
#include <bits/stdc++.h>
#define MOD 100003
#define NMAX 2000

using namespace std;

ifstream fi("fractii2.in");
ofstream fo("fractii2.out");

int p,n,dp[NMAX+5][NMAX+5],cnt;

int main(){
    fi>>p>>n;
    if(p==1){
        for(int i=1;i<n;i++){
            fo<<i<<' ';
        }
        fo<<n-1<<'\n';
    }else{
        dp[2][1]=1;
        for(int i=3;i<=n;i++){
            for(int j=1;2*j<=i;j++){
                dp[i][j]=(dp[i][j-1]+dp[i-j][(i-j)/2]-dp[i-j][(j-1)/2]+MOD)%MOD;
            }
        }
        fo<<dp[n][n/2];
    }
    fi.close();
    fo.close();
}