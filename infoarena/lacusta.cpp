
#include <iostream>
#include <fstream>
#define NMAX 250
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("lacusta.in");
ofstream g("lacusta.out");

int n,m,matrice[NMAX+5][NMAX+5],dp[NMAX+5][NMAX+5],rez=MAXVAL;

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
            dp[i][j]=MAXVAL;
        }
    }
    for(int j=2;j<=m;j++){
        dp[2][j]=matrice[1][j]+matrice[1][1]+matrice[2][j];
    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int jj=1;jj<=m;jj++){
                if(j!=jj){
                    dp[i][j]=min(dp[i][j],dp[i-1][jj]);
                }
            }
            dp[i][j]+=matrice[i-1][j]+matrice[i][j];
        }
    }
    for(int j=1;j<=m-1;j++){
        rez=min(rez,dp[n][j]);
    }
    rez+=matrice[n][m];
    g<<rez;
    f.close();
    g.close();
}
