
#include <iostream>
#include <fstream>
#define NMAX 1000
#define MOD 666013

using namespace std;

ifstream f("rege.in");
ofstream g("rege.out");

int l1,l2,c1,c2,n,m,dp[NMAX+1][NMAX+1];

int main(){
    f>>n>>m>>l1>>c1>>l2>>c2;
    if(max(l2,l1)-min(l1,l2)<max(c2,c1)-min(c1,c2)){
        swap(n,m);
        swap(l1,c1);
        swap(l2,c2);
    }
    if(l1>l2){
        swap(l1,l2);
    }
    dp[l1][c1]=1;
    for(int i=l1+1;i<=l2;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%MOD;
        }
    }
    g<<dp[l2][c2];
    f.close();
    g.close();
}
