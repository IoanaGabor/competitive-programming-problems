
#include <bits/stdc++.h>
#define NMAX 1024
#define VMAX 512
#define VALMAX 100

using namespace std;

ifstream fi("note.in");
ofstream fo("note.out");

int v,n;
int mat[VMAX+5][NMAX+5];
int fv[VALMAX+5][NMAX+5];
int sir[NMAX+5];
int dp[NMAX+5][NMAX+5];
int ok[NMAX+5][NMAX+5];
int m;

int main(){
    fi>>v>>n;
    for(int i=1;i<=v;i++){
        for(int j=1;j<=n;j++){
            fi>>mat[i][j];
        }
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=v;i++){
            fv[mat[i][j]][j]=1;
        }
    }
    fi>>m;
    for(int i=1;i<=m;i++){
        fi>>sir[i];
        for(int j=1;j<=n;j++){
            if(fv[sir[i]][j]){
                ok[i][j]=1;

            }
        }
    }
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=n;j++){
        dp[0][j]=j;
    }
    int c;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(ok[i][j]){
                c=0;
            }else{
                c=1;
            }
            dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+c);
        }
    }
    fo<<dp[m][n];
}