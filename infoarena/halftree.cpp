
#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("halftree.in");
ofstream fo("halftree.out");

int n,par[NMAX+5],cost[NMAX+5];
vector<pair<int,int> > arb[NMAX+5];
long long dp[NMAX+5],sons[NMAX+5];
long long lantmax;
long long tot;

void dfs(int nod,int parent){
    sons[nod]=0;
    dp[nod]=0;
    long long max1=0,max2=0,val;
    for(int i=0;i<arb[nod].size();i++){
        if(arb[nod][i].first!=parent){
            dfs(arb[nod][i].first,nod);
            sons[nod]+=(sons[arb[nod][i].first]+1);
            val=dp[arb[nod][i].first]+1LL*(arb[nod][i].second/2)*(sons[arb[nod][i].first]+1)*(n-sons[arb[nod][i].first]-1);
            tot+=1LL*arb[nod][i].second*(sons[arb[nod][i].first]+1)*(n-sons[arb[nod][i].first]-1);
            dp[nod]=max(dp[nod],val);
            if(val>max1){
                max2=max1;
                max1=val;
            }else if(val>max2){
                max2=val;
            }
        }
    }
    lantmax=max(lantmax,max1+max2);
}

int main(){
    fi>>n;
    for(int i=2;i<=n;i++){
        fi>>par[i];
    }
    for(int i=2;i<=n;i++){
        fi>>cost[i];
    }
    for(int i=2;i<=n;i++){
        arb[i].push_back(make_pair(par[i],cost[i]));
        arb[par[i]].push_back(make_pair(i,cost[i]));
    }
    dfs(1,0);
    fo<<tot-lantmax;
    fi.close();
    fo.close();
}