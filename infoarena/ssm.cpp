
#include <iostream>
#include <fstream>
#define nmax 6000005

using namespace std;

ifstream f("ssm.in");
ofstream g("ssm.out");

int n,dp[nmax],start[nmax],i_max,x;

int main(){
    f>>n>>x;
    dp[1]=x;
    start[1]=1;
    i_max=1;
    for(int i=2;i<=n;i++){
        f>>x;
        if(dp[i-1]>=0){
            dp[i]=dp[i-1]+x;
            start[i]=start[i-1];
        }else{
            dp[i]=x;
            start[i]=i;
        }
        if(dp[i]>dp[i_max]||(dp[i]==dp[i_max]&&start[i]<start[i_max])||(dp[i]==dp[i_max]&&start[i]==start[i_max]&&i_max-start[i_max]>i-start[i])){
            i_max=i;
        }
    }
    g<<dp[i_max]<<' '<<start[i_max]<<' '<<i_max;
    f.close();
    g.close();
}
