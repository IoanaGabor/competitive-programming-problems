
#include <iostream>
#include <fstream>
#define HMAX 500
#define MAXVAL (1LL<<33)-1

using namespace std;

ifstream f("calatorie.in");
ofstream g("calatorie.out");

long long t,n,val,h,dp[3][HMAX+5];
long long rez;

int main(){
    f>>t;
    while(t--){
        f>>n;
        n--;
        for(int i=0;i<=1;i++){
            for(int j=0;j<=HMAX;j++){
                dp[i][j]=MAXVAL;
            }
        }
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            f>>val>>h;
            for(int j=0;j<=HMAX;j++){
                if(dp[(i-1)%2][j]!=MAXVAL){
                    dp[i%2][j]=dp[(i-1)%2][j]+val;
                }else{
                    dp[i%2][j]=MAXVAL;
                }
            }
            for(int j=HMAX-h;j>=0;j--){
                dp[i%2][j+h]=min(dp[i%2][j+h],dp[(i-1)%2][j]);
            }
        }
        rez=MAXVAL;
        for(int i=0;i<=HMAX;i++){
            if(dp[n%2][i]!=MAXVAL){
                rez=min(rez,dp[n%2][i]+1LL*i*i*i*i);
            }
        }
        g<<"Consumul minim = "<<rez<<".\n";
    }
    f.close();
    g.close();
}
