#include <bits/stdc++.h>
#define NMAX 500

using namespace std;

ifstream fi("sume3.in");
ofstream fo("sume3.out");

int n,k,sir[NMAX+5],sum[NMAX+5];
int dp[NMAX+5][NMAX+5];
int test;

int main() {
    while(fi>>n){
        if(n==0){
            break;
        }
        fi>>k;
        sum[0]=0;
        for(int i=1;i<=n;i++){
            fi>>sir[i];
            sum[i]=sum[i-1]+sir[i];
            dp[i][1]=sum[i];
        }
        for(int j=2;j<=k;j++){
            for(int i=j;i<=n;i++){
                dp[i][j]=max(dp[i-1][j-1],sir[i]);
                for(int ii=j-1;ii<=i-1;ii++){
                    dp[i][j]=min(dp[i][j],max(dp[ii][j-1],sum[i]-sum[ii]));
                }
            }
        }
        test++;
        fo<<test<<":"<<dp[n][k]<<'\n';
    }
    fi.close();
    fo.close();
}
