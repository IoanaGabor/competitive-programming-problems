
#include <iostream>
#include <fstream>
#define NMAX 10000
#define MOD 9001

using namespace std;

ifstream f("flori4.in");
ofstream g("flori4.out");

int n,dp[NMAX+5],s;

int main(){
    f>>n;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-2]+1+dp[i-1])%MOD;
    }
    g<<dp[n];
}
