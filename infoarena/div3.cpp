
#include <iostream>
#include <fstream>
#define NMAX 9
#define KMAX 1000
#define MOD 4001

using namespace std;

ifstream f("div3.in");
ofstream g("div3.out");

int dp[KMAX+3][3],sir[NMAX+3],n,k;

int main(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        dp[1][sir[i]%3]++;
    }
    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            for(int ij=0;ij<=2;ij++){
                dp[i][(ij+sir[j])%3]=(dp[i][(ij+sir[j])%3]+dp[i-1][ij])%MOD;
            }
        }
    }
    g<<dp[k][0];
    f.close();
    g.close();
}
