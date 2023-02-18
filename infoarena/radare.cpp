
#include <bits/stdc++.h>
#define NMAX 3000
#define PMAX 3500
#define MOD 31333

using namespace std;

ifstream fi("radare.in");
ofstream fo("radare.out");

int n,p,x,y;
vector<int> arb[NMAX+5];
int cost[NMAX+5];
int lini[NMAX+5],l;
int sar[NMAX+5];
int cnt[NMAX+5];
int doi[NMAX+5];
int dp[NMAX+5][PMAX+5];

void dfs(int nod,int parent){
    lini[++l]=nod;
    for(int i=0;i<arb[nod].size();i++){
        if(arb[nod][i]!=parent){
            dfs(arb[nod][i],nod);
            cnt[nod]+=cnt[arb[nod][i]];
        }
    }
    cnt[nod]++;
    sar[nod]=l;
}

int main(){
    fi>>n>>p;
    for(int i=1;i<n;i++){
        fi>>x>>y;
        arb[x].push_back(y);
        arb[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        fi>>cost[i];
    }
    dfs(1,0);
    doi[0]=1;
    for(int i=1;i<=n;i++){
        doi[i]=doi[i-1]<<1;
        doi[i]%=MOD;
    }
    dp[1][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=p;j++){
            if(dp[i][j]>0){
                x=lini[i];
                if(j+cost[x]<=p){
                    dp[i+1][j+cost[x]]+=dp[i][j];
                    dp[i+1][j+cost[x]]%=MOD;
                }
                dp[sar[x]+1][j]+=dp[i][j]*(doi[cnt[x]-1]);
                dp[sar[x]+1][j]%=MOD;
            }
        }
    }
    fo<<dp[n+1][p]<<'\n';
    fi.close();
    fo.close();
}