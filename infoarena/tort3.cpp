
#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 500

using namespace std;

ifstream f("tort3.in");
ofstream g("tort3.out");

int n,m,matrice[NMAX+5][NMAX+5],dp[NMAX+5][NMAX+5];
char ch;

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>ch;
            matrice[i][j]=ch-'0';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1||j==1){
                dp[i][j]=1;
            }else{
                if(matrice[i][j]==matrice[i-1][j]&&matrice[i][j]==matrice[i][j-1]&&matrice[i][j]==matrice[i-1][j-1]){
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }else{
                    dp[i][j]=1;
                }
            }
        }
    }
    for(int lat=min(n,m);lat>=1;lat--){
        for(int i=lat;i<=n;i++){
            for(int j=lat;j<=m;j++){
                if(matrice[i][j]!=-1&&matrice[i-lat+1][j-lat+1]!=-1&&matrice[i-lat+1][j]!=-1&&matrice[i][j-lat+1]!=-1&&dp[i][j]>=lat){
                    g<<lat<<' '<<i<<' '<<j<<'\n';
                    for(int ii=i-lat+1;ii<=i;ii++){
                        for(int jj=j-lat+1;jj<=j;jj++){
                            matrice[ii][jj]=-1;
                        }
                    }
                }
            }
        }
    }
    f.close();
    g.close();
}
