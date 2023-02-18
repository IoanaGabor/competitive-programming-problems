
#include <iostream>
#include <fstream>
#define NMAX 50000

using namespace std;

ifstream f("rogvaiv.in");
ofstream g("rogvaiv.out");

int c,n,m;
int dp[NMAX+5][8][2],rez;

int main(){
    f>>c>>n>>m;
    if(c==1){
        for(int i=1;i<=7;i++){
            dp[1][i][0]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=7;j++){
                dp[i][j][0]=dp[i][j][1]=0;
                for(int jj=1;jj<=7;jj++){
                    dp[i][j][0]=(dp[i][j][0]+dp[i-1][jj][0])%m;
                    dp[i][j][1]=(dp[i][j][1]+dp[i-1][jj][1])%m;
                }
                if(j==7){
                    dp[i][j][0]=(dp[i][j][0]+m-dp[max(i-6,0)][1][0])%m;
                    dp[i][j][1]=(dp[i][j][1]+dp[max(i-6,0)][1][0])%m;
                }
                if(i==n){
                    rez=(rez+dp[i][j][1])%m;
                }
            }
        }
        g<<rez;
    }else{
        for(int i=1;i<=7;i++){
            dp[1][i][0]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=7;j++){
                dp[i][j][0]=dp[i][j][1]=0;
                for(int jj=1;jj<=7;jj++){
                    dp[i][j][0]=(dp[i][j][0]+dp[i-1][jj][0])%m;
                    dp[i][j][1]=(dp[i][j][1]+dp[i-1][jj][1])%m;
                }
                if(j==7||j==1){
                    dp[i][j][0]=(dp[i][j][0]+m-dp[max(i-6,0)][1][0])%m;
                    dp[i][j][1]=(dp[i][j][1]+dp[max(i-6,0)][1][0])%m;

                }
                if(i==n){
                    rez=(rez+dp[i][j][1])%m;
                }
            }
        }
        g<<rez;
    }
    f.close();
    g.close();
}
