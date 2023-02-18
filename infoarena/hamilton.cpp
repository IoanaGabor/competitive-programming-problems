
#include <iostream>
#include <fstream>
#define NMAX 18
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("hamilton.in");
ofstream g("hamilton.out");

int n,m,x,y,c,G[NMAX+5][NMAX+5],dp[(1<<NMAX)+5][NMAX+5],rez=MAXVAL;

int main(){
    f>>n>>m;
    for(int i=1;i<=m;i++){
        f>>x>>y>>c;
        G[x][y]=c;
    }
    for(int stare=1;stare<=(1<<n)-1;stare++){
        for(int i=0;i<n;i++){
            dp[stare][i]=MAXVAL;
        }
    }
    dp[1][0]=0;
    for(int stare=1;stare<=(1<<n)-1;stare++){
        for(int i=0;i<n;i++){
            if(((1<<i)&stare)>0&&dp[stare][i]!=MAXVAL){
                for(int k=0;k<n;k++){
                    if((!((1<<k)&stare))&&G[i][k]){
                        dp[stare+(1<<k)][k]=min(dp[stare+(1<<k)][k],dp[stare][i]+G[i][k]);
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dp[(1<<n)-1][i]!=MAXVAL&&G[i][0]){
            rez=min(rez,dp[(1<<n)-1][i]+G[i][0]);
        }
    }
    if(rez==MAXVAL){
        g<<"Nu exista solutie";
    }else{
        g<<rez;
    }
    f.close();
    g.close();
}
