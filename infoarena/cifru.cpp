
#include <iostream>
#include <fstream>
#define NMAX 2000
#define MOD 19997

using namespace std;

ifstream f("cifru.in");
ofstream g("cifru.out");

int n,k;
int dp[NMAX+5],aranj;

int main(){
    f>>n>>k;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        aranj=1;
        for(int j=1;j<=i;j++){
            if(j!=1){
                aranj=(aranj*(i-j+1))%MOD;
            }
            if(k%j==0){
                dp[i]=(dp[i]+aranj*dp[i-j])%MOD;
            }
        }
    }
    g<<dp[n];
}
