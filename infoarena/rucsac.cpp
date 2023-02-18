
#include <iostream>
#include <fstream>
#define GMAX 10000
#define NMAX 5000

using namespace std;

ifstream f("rucsac.in");
ofstream g("rucsac.out");

int n,G,w[NMAX+1],p[NMAX+1],dp[2][GMAX+1],acum,vechi;

int main(){
    f>>n>>G;
    for(int i=1;i<=n;i++){
        f>>w[i]>>p[i];
    }
    for(int i=1;i<=n;i++){
        acum=i%2;
        vechi=(i-1)%2;
        for(int j=0;j<=G;j++){
            dp[acum][j]=dp[vechi][j];
            if(w[i]<=j){
                dp[acum][j]=max(dp[acum][j],dp[vechi][j-w[i]]+p[i]);
            }
        }
    }
    g<<dp[n%2][G];
    f.close();
    g.close();
}
