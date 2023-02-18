
#include <iostream>
#include <fstream>
#define NMAX 500
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("caibicol.in");
ofstream g("caibicol.out");

int n,k,sir[NMAX+5],cnt[3][NMAX+5],dp[NMAX+5][NMAX+5];

int main(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        cnt[0][i]=cnt[0][i-1];
        cnt[1][i]=cnt[1][i-1];
        cnt[sir[i]][i]++;
    }
    for(int i=1;i<=n;i++){
        dp[i][1]=cnt[0][i]*cnt[1][i];
    }
    for(int j=2;j<=k;j++){
        for(int i=j;i<=n;i++){
            dp[i][j]=MAXVAL;
            for(int ii=j;ii<=i;ii++){
                dp[i][j]=min(dp[i][j],dp[ii-1][j-1]+(cnt[0][i]-cnt[0][ii-1])*(cnt[1][i]-cnt[1][ii-1]));
            }
        }
    }
    g<<dp[n][k];
}
