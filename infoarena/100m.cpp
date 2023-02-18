
#include <iostream>
#include <fstream>
#define NMAX 5000
#define MOD 666013

using namespace std;

ifstream f("100m.in");
ofstream g("100m.out");

long long dp[3][NMAX+5],n,rez;

int main(){
    f>>n;
    dp[1][1]=1;
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            dp[i%2][j+1]=(dp[i%2][j+1]+dp[(i-1)%2][j]*(j+1))%MOD;
            dp[i%2][j]=(dp[i%2][j]+dp[(i-1)%2][j]*j)%MOD;
        }
        for(int j=1;j<=i;j++){
            dp[(i-1)%2][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        rez=(rez+dp[n%2][i])%MOD;
    }
    g<<rez;
    f.close();
    g.close();
}
