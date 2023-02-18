#include <iostream>
#include <fstream>
#define NMAX 250
#define MOD 31607

using namespace std;

ifstream f("drumuri1.in");
ofstream g("drumuri1.out");

int n,m,k,l,x,y,dp[3][NMAX+3][NMAX+3],matrice[NMAX+3][NMAX+3],rez,t;

int main(){
    f>>n>>m>>k>>l;
    while(m--){
        f>>x>>y;
        matrice[x][y]=1;
    }
    dp[1][1][matrice[1][1]]=1;
    t=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=1||j!=1){
                if(matrice[i][j]==1){
                    for(int ii=1;ii<=k;ii++){
                        dp[t][j][ii]=(dp[1-t][j][ii-1]+dp[t][j-1][ii-1])%MOD;
                    }
                    dp[t][j][0]=0;
                }else{
                    for(int ii=0;ii<=k;ii++){
                        dp[t][j][ii]=(dp[1-t][j][ii]+dp[t][j-1][ii])%MOD;
                    }
                }
            }
            if(i+j-1==l){
                rez=(rez+dp[t][j][k])%MOD;
            }
        }
        t=1-t;
    }
    g<<rez<<'\n';
    f.close();
    g.close();
}
