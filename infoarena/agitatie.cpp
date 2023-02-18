
#include <iostream>
#include <fstream>
#include <cmath>
#define TMAX 6000

using namespace std;

ifstream f("agitatie.in");
ofstream g("agitatie.out");

int dp[2][TMAX+5],val[3005],s[3005],n,minim,rez;

int calculeaza(int i,int timp){
    return abs(val[i]+s[i]*timp);
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>val[i]>>s[i];
        rez+=val[i];
    }
    for(int i=1;i<=n;i++){
        dp[i%2][0]=dp[(i-1)%2][0]+val[i];
        minim=dp[(i-1)%2][0];
        for(int j=1;j<=TMAX;j++){
            minim=min(minim,dp[(i-1)%2][j]);
            dp[i%2][j]=minim+calculeaza(i,j);
            if(i==n){
                rez=min(rez,dp[i%2][j]);
            }
        }
    }
    g<<rez;
    f.close();
    g.close();
}
