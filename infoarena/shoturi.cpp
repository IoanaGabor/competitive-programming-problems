
#include <iostream>
#include <fstream>
#define NMAX 5000
#define MOD 269696969

using namespace std;

ifstream f("shoturi.in");
ofstream g("shoturi.out");

int n,k,hazard[NMAX+5],dp[3][NMAX+5],s1,s2;

int main(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>hazard[i];
    }
    for(int i=1;i<=k;i++){
        dp[1][i]=(1LL*i*hazard[1])%MOD;
    }
    for(int i=2;i<=n;i++){
        s1=1;
        s2=1;
        for(int j=1;j<=k;j++){
            dp[i%2][j]=(1LL*s2*hazard[i]+dp[(i-1)%2][j])%MOD;
            s1=1LL*(s1+dp[(i-1)%2][j])%MOD;
            s2=1LL*(s2+s1)%MOD;
        }
    }
    g<<dp[n%2][k]<<'\n';
    f.close();
    g.close();
}
