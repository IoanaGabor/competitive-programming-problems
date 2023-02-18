
#include <iostream>
#include <fstream>
#define NMAX 1000

using namespace std;

ifstream f("acces.in");
ofstream g("acces.out");

int n,m,matrice[NMAX+5][NMAX+5],dp[NMAX+5][NMAX+5],q,x,y;
bool unu;

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(matrice[i][1]==1){
            dp[i][1]=0;
        }else{
            dp[i][1]=dp[i-1][1]+1;
        }
    }
    for(int i=1;i<=m;i++){
        if(matrice[1][i]==1){
            dp[1][i]=0;
        }else{
            dp[1][i]=dp[1][i-1]+1;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(matrice[i][j]==0){
                dp[i][j]=1;
                if(matrice[i-1][j]==0&&matrice[i][j-1]!=0){
                    dp[i][j]+=dp[i-1][j];
                }
                if(matrice[i-1][j]!=0&&matrice[i][j-1]==0){
                    dp[i][j]+=dp[i][j-1];
                }
                if(matrice[i-1][j]==0&&matrice[i][j-1]==0){
                    dp[i][j]+=dp[i-1][j]+dp[i][j-1];
                    if(dp[i-1][j-1]>=0){
                        dp[i][j]-=dp[i-1][j-1];
                    }else{
                        dp[i][j]+=dp[i-1][j-1];
                    }
                }
            }else{
                if(matrice[i-1][j]==0&&matrice[i][j-1]==0){
                    dp[i][j]=-dp[i-1][j-1];
                }else{
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    f>>q;
    while(q--){
        f>>x>>y;
        g<<dp[x][y]<<'\n';
    }
}
