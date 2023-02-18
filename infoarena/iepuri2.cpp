
#include <bits/stdc++.h>
#define NMAX 100
#define KMAX 100
#define MOD 30011

using namespace std;

ifstream f("iepuri2.in");
ofstream g("iepuri2.out");

int n,k,a,b,dp[NMAX+5][KMAX+5],sumedp[NMAX+5][KMAX+5],parent[NMAX+5],root;
vector <int> G[NMAX+5];

void dfs(int nod) {
    for(int i=0;i<G[nod].size();i++){
        dfs(G[nod][i]);
    }
    if(G[nod].size()==0){
        for(int i=k;i>=1;i--){
            dp[nod][i]=1;
            sumedp[nod][i]=(sumedp[nod][i+1]+dp[nod][i])%MOD;
        }
    }else{
        for(int i=k;i>=1;i--){
            dp[nod][i]=1;
            for(int j=0;j<G[nod].size();j++){
                dp[nod][i]=(1LL*dp[nod][i]*sumedp[G[nod][j]][i+1])%MOD;
            }
            sumedp[nod][i]=(sumedp[nod][i+1]+dp[nod][i])%MOD;
        }
    }
}

int main(){
    f>>n>>k;
    for(int i=1;i<n;i++){
        f>>a>>b;
        G[a].push_back(b);
        parent[b]=a;
    }
    for(int i=1;i<=n;i++){
        if(parent[i]==0){
            root=i;
        }
    }
    dfs(root);
    g<<sumedp[root][1];
    f.close();
    g.close();
}