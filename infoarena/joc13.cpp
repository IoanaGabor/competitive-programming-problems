
#include <iostream>
#include <fstream>
#define NMAX 5000
#define MINVAL -50000000

using namespace std;

ifstream f("joc13.in");
ofstream g("joc13.out");

int n,k,mat[3][NMAX+5],dp[3][NMAX+5][3],suma[3][NMAX+5];

int main(){
    f>>n>>k;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            f>>mat[i][j];
            suma[i][j]=mat[i][j]+suma[i][j-1];
            dp[i][j][1]=dp[i][j][2]=MINVAL;
        }
    }
    //dp[1][0][1]=dp[1][0][2]=dp[2][0][1]=dp[2][0][2]=MINVAL;
    dp[1][1][1]=mat[1][1];
    dp[1][1][2]=MINVAL;
    dp[2][1][1]=mat[1][1]+mat[2][1];
    dp[2][1][2]=MINVAL;
    //cout<<dp[1][1][1]<<' '<<dp[1][1][2]<<"     "<<dp[2][1][1]<<' '<<dp[2][1][2]<<'\n';
    for(int i=2;i<=n;i++){
        if(i<=k){
            dp[1][i][1]=max(mat[1][i]+max(dp[1][i-1][1],dp[1][i-1][2]),dp[1][i][1]);
            dp[2][i][2]=max(mat[2][i]+max(dp[2][i-1][1],dp[2][i-1][2]),dp[2][i][2]);
            dp[2][i][1]=max(dp[2][i][1],mat[2][i]+dp[1][i][1]);
            dp[1][i][2]=max(dp[1][i][2],mat[1][i]+dp[2][i][2]);
        }else{
            for(int j=i-1;j>=i-k+1;j--){
                dp[1][i][1]=max(suma[1][i]-suma[1][j-1]+dp[2][j][2],dp[1][i][1]);
                dp[2][i][2]=max(suma[2][i]-suma[2][j-1]+dp[1][j][1],dp[2][i][2]);
            }
            dp[1][i][2]=max(dp[1][i][2],mat[1][i]+dp[2][i][2]);
            dp[2][i][1]=max(dp[2][i][1],mat[2][i]+dp[1][i][1]);
        }
        //cout<<dp[1][i][1]<<' '<<dp[1][i][2]<<"     "<<dp[2][i][1]<<' '<<dp[2][i][2]<<'\n';
    }
    g<<max(dp[2][n][1],dp[2][n][2]);
    f.close();
    g.close();
}
