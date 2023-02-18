
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,sir1[1025],sir2[1025],dp[1025][1025],maxim,rez[1025],lrez;

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>sir1[i];
    }
    for(int i=1;i<=m;i++){
        f>>sir2[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(sir1[i]==sir2[j]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    maxim=dp[n][m];
    int i=n,j=m;
    while(i&&j){
        if(sir1[i]==sir2[j]){
            rez[++lrez]=sir1[i];
            i--;
            j--;
        }else if(dp[i-1][j]<dp[i][j-1]){
            j--;
        }else{
            i--;
        }
    }
    g<<maxim<<'\n';
    for(int i=lrez;i>=1;i--){
        g<<rez[i]<<' ';
    }
    f.close();
    g.close();
}
