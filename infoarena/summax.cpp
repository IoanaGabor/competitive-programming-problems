
#include <bits/stdc++.h>
#define NMAX 2000
#define MAXVAL 2000000000

using namespace std;

ifstream fi("summax.in");
ofstream fo("summax.out");

int v,n,st,dr;
int dp[NMAX+1][NMAX+1];
int sir[NMAX+1];

void solve(int i,int j,int s,int d){
    sir[i]=j;
    if(i==n){
        for(int ii=1;ii<=n;ii++){
            fo<<sir[ii]<<' ';
        }
        fo<<'\n';
        return;
    }
    if(dp[n-(i+1)][n+1-j]==dp[n-(i+1)][n+1-(j+1)]){
        if(d<=dp[i+1][j]){
            solve(i+1,j,s,d);
        }else if(s>dp[i+1][j]){
            solve(i+1,j+1,s-dp[i+1][j],d-dp[i+1][j]);
        }else{
            solve(i+1,j,s,dp[i+1][j]);
            solve(i+1,j+1,1,d-dp[i+1][j]);
        }
    }else if(dp[n-(i+1)][n+1-j]<dp[n-(i+1)][n+1-(j+1)]){
        solve(i+1,j+1,s,d);
    }else{
        solve(i+1,j,s,d);
    }
}

int main(){
    fi>>v>>n>>st>>dr;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            fi>>dp[n-i][n+1-j];
        }
        dp[n][i]=1;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(dp[n-(i+1)][n+1-j]==dp[n-(i+1)][n+1-(j+1)]){
                dp[n-i][n+1-j]+=dp[n-(i+1)][n+1-j];
                if(dp[i+1][j]>MAXVAL-dp[i+1][j+1]){
                    dp[i][j]=MAXVAL+1;
                }else{
                    dp[i][j]=dp[i+1][j]+dp[i+1][j+1];
                }
            }else if(dp[n-(i+1)][n+1-j]<dp[n-(i+1)][n+1-(j+1)]){
                dp[n-i][n+1-j]+=dp[n-(i+1)][n+1-(j+1)];
                dp[i][j]=dp[i+1][j+1];
            }else{
                dp[n-i][n+1-j]+=dp[n-(i+1)][n+1-j];
                dp[i][j]=dp[i+1][j];
            }
        }
    }
    if(v==1){
        fo<<dp[1][1]<<'\n';
    }else{
        solve(1,1,st,dr);
    }
    fi.close();
    fo.close();
}
