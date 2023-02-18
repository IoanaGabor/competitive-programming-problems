
#include <iostream>
#include <fstream>
#define NMAX 100000

using namespace std;

ifstream f("hacker3.in");
ofstream g("hacker3.out");

int n,a,b;
long long dp[3][32],rez;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>a>>b;
        dp[i%2][0]=dp[(i-1)%2][0]+b;
        for(int j=1;j<32;j++){
            dp[i%2][j]=min(dp[(i-1)%2][j-1]+a*(1LL<<(j-1)),dp[(i-1)%2][j]+b*(1LL<<j));
        }
    }
    rez=dp[n%2][0];
    for(int i=1;i<32;i++){
        rez=min(rez,dp[n%2][i]);
    }
    g<<rez;
    f.close();
    g.close();
}
