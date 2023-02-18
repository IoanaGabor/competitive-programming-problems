
#include <bits/stdc++.h>
#define MOD 1000000007
#define NMAX 100
#define DMAX 10000

using namespace std;

ifstream fi("tairos.in");
ofstream fo("tairos.out");

int n,d,x,y;
vector<int> arb[NMAX+5];
vector<int> child[NMAX+5];
int dp[DMAX+5][NMAX+5];
bool viz[DMAX+5][NMAX+5];
int leaves[NMAX+5],ll;
int rez;

void dfs(int node,int father){
    for(int i=0;i<arb[node].size();i++){
        if(arb[node][i]!=father){
            child[node].push_back(arb[node][i]);
            dfs(arb[node][i],node);
        }
    }
}

int main(){
    fi>>n>>d;
    for(int i=1;i<n;i++){
        fi>>x>>y;
        arb[x].push_back(y);
        arb[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        if(arb[i].size()==1&&i!=1){
            child[i]=child[1];
        }
    }
    dp[0][1]=1;
    for(int i=0;i<d;i++){
        for(int j=1;j<=n;j++){
            if(dp[i][j]){
                for(int k=0;k<child[j].size();k++){
                    dp[i+1][child[j][k]]=(dp[i+1][child[j][k]]+dp[i][j])%MOD;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        rez+=dp[d][i];
        rez%=MOD;
    }
    fo<<rez;
    fi.close();
    fo.close();
}
