
#include <bits/stdc++.h>
#define NMAX 4000
#define VMAX 8000

using namespace std;

ifstream fi("euro3.in");
ofstream fo("euro3.out");

int t,n,vmax,sir[NMAX+5];
int dp[VMAX+5];
int sol[VMAX+5];

int main(){
    fi>>t;
    while(t--){
        fi>>n>>vmax;
        for(int i=1;i<=n;i++){
            fi>>sir[i];
        }
        sort(sir+1,sir+n+1);
        for(int i=1;i<=vmax;i++){
            dp[i]=-1;
            sol[i]=VMAX+5;
        }
        for(int i=1;i<=n;i++){
            for(int j=vmax;j>sir[i];j--){
                if(dp[j-sir[i]]!=-1){
                    dp[j]=max(dp[j],dp[j-sir[i]]);
                    sol[j]=min(sol[j],sir[i]-dp[j]);
                }
            }                        
            dp[sir[i]]=sir[i];
            sol[sir[i]]=0;
        }
        for(int i=1;i<=vmax;i++){
            if(sol[i]==VMAX+5){
                sol[i]=-1;
            }
            fo<<sol[i]<<' ';
        }
        fo<<'\n';
    }
    fi.close();
    fo.close();
}