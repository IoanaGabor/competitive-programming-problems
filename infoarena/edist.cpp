
#include <iostream>
#include <fstream>
#define NMAX 20000
#define MAXVAL 40005

using namespace std;

ifstream f("edist.in");
ofstream g("edist.out");

int n,m,k,dp[2][NMAX+5],ind;
char sir1[NMAX+5],sir2[NMAX+5];

int main(){
    f>>n>>m>>k;
    f>>(sir1+1);
    f>>(sir2+1);
    for(int i=1;i<=m;i++){
        dp[0][i]=1;
    }
    for(int i=1;i<=n;i++){
        ind=i%2;
        dp[ind][0]=i;
        if(i-k>1){
            dp[ind][i-k-1]=MAXVAL;
        }
        for(int j=max(1,i-k);j<=min(m,i+k);j++){
            dp[ind][j]=dp[1-ind][j]+1;
            dp[ind][j]=min(dp[ind][j],dp[ind][j-1]+1);
            dp[ind][j]=min(dp[ind][j],dp[1-ind][j-1]+(1-(sir1[i]==sir2[j])));
        }
    }
    g<<dp[n%2][m];
    f.close();
    g.close();
}
