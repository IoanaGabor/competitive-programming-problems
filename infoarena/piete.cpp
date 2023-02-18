
#include <bits/stdc++.h>
#define NMAX 10
#define MMAX 10
#define PMAX 100

using namespace std;

ifstream fi("piete.in");
ofstream fo("piete.out");

int n,m,s,f;
int p[NMAX+5][MMAX+5];
int dp[PMAX+5];
int ok[PMAX+5];
int s1,s2,ind;
int dp2[PMAX+5],dp3[PMAX+5],zero=PMAX;

int main(){
    fi>>n>>m>>s>>f;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            fi>>p[i][j];
        }
    }
    ok[s]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            s1=s2=0;
            for(int i=0;i<=PMAX;i++){
                dp2[i]=dp3[i]=0;
            }
            for(int k=1;k<=m;k++){
                if(p[i][k]-p[j][k]>0){
                    for(int v=PMAX-p[j][k];v>=0;v--){
                        if(dp2[v]||v==0){
                            dp2[v+p[j][k]]=max(dp2[v+p[j][k]],dp2[v]+p[i][k]-p[j][k]);
                        }
                    }
                }
                if(p[j][k]-p[i][k]>0){
                    for(int v=PMAX-p[i][k];v>=0;v--){
                        if(dp3[v]||v==0){
                            dp3[v+p[j][k]]=max(dp3[v+p[j][k]],dp3[v]+p[j][k]-p[i][k]);
                        }
                    }
                }
            }        
            s1=s2=0;
            for(int v=0;v<=s;v++){
                s1=max(s1,dp2[v]);
                s2=max(s2,dp3[v]);
            } 
            for(int k=s;k<f;k++){
                if(ok[k]){
                    ind=min(k+s1,f);
                    if(!ok[ind]||dp[ind]>dp[k]+1){
                        ok[ind]=1;
                        dp[ind]=dp[k]+1;
                    }
                    ind=min(k+s2,f);
                    if(!ok[ind]||dp[ind]>dp[k]+1){
                        ok[ind]=1;
                        dp[ind]=dp[k]+1;
                    }
                }
                s1=max(s1,dp2[k]);
                s2=max(s2,dp3[k]);
            }    
        }
    }
    if(!ok[f]){
        fo<<-1;
    }else{
        fo<<dp[f];
    }
    fi.close();
    fo.close();
}