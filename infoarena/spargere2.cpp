
#include <iostream>
#include <fstream>
#define NMAX 100000

using namespace std;

ifstream f("spargere2.in");
ofstream g("spargere2.out");

int n,k;
long long sir[NMAX+5],dp[NMAX+5];

int main(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    for(int i=1;i<=n;i++){
        if(i<k){
            dp[i]=max(sir[i],dp[i-1]);
        }else{
            dp[i]=max(dp[i-1],dp[i-k]+sir[i]);
        }
    }
    g<<dp[n];
    f.close();
    g.close();
}
