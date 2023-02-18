///salut si sper ca ii bine programul
#include <iostream>
#include <fstream>
#define NMAX 100000

using namespace std;

ifstream f("oo.in");
ofstream g("oo.out");

int sir[NMAX+5],n,dp[NMAX+5][3],rez;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    if(n==2){
        g<<sir[1]+sir[2];
    }else{
        ///luam primele 2 elemente
        dp[1][1]=dp[1][2]=dp[2][2]=0;
        dp[2][1]=sir[1]+sir[2];
        for(int i=3;i<n;i++){
            dp[i][1]=sir[i]+sir[i-1]+max(dp[i-3][1],dp[i-3][2]);
            dp[i][2]=max(dp[i-1][1],dp[i-1][2]);
        }
        rez=max(dp[n-1][1],dp[n-1][2]);
        ///luam primul element si ultimul
        dp[1][1]=sir[1]+sir[n];
        dp[1][2]=0;
        dp[2][1]=0;
        dp[2][2]=dp[1][1];
        for(int i=3;i<n;i++){
            dp[i][1]=sir[i]+sir[i-1]+max(dp[i-3][1],dp[i-3][2]);
            dp[i][2]=max(dp[i-1][1],dp[i-1][2]);
        }
        rez=max(rez,dp[n-1][2]);
        ///nu luam primul element
        dp[1][1]=dp[1][2]=dp[2][1]=dp[2][2]=0;
        for(int i=3;i<=n;i++){
            dp[i][1]=sir[i]+sir[i-1]+max(dp[i-3][1],dp[i-3][2]);
            dp[i][2]=max(dp[i-1][1],dp[i-1][2]);
        }
        rez=max(rez,max(dp[n][1],dp[n][2]));
        g<<rez;
    }
    f.close();
    g.close();
}
