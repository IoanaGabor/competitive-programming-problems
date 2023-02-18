#include <iostream>
#include <fstream>
#define NMAX 500
#define INF (1LL<<60)-1

using namespace std;

ifstream f("podm.in");
ofstream g("podm.out");

int n;
unsigned long long l[NMAX+5],c[NMAX+5];
unsigned long long dp[NMAX+5][NMAX+5];

int main()
{
    f>>n>>l[1];
    for(int i=2;i<=n+1;i++){
        f>>l[i];
        c[i-1]=l[i];
    }
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            dp[i][j]=INF;
            for(int k=i;k<=j-1;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+l[i]*c[k]*c[j]);
            }
        }
    }
    g<<dp[1][n];
    return 0;
}
