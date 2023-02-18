
#include <bits/stdc++.h>
#define MOD 666013
#define NMAX 100000

using namespace std;

ifstream fi("karb2.in");
ofstream fo("karb2.out");

int n,k,x,y;
vector<int> arb[NMAX+5];
int cart[NMAX+5];
int dp[NMAX+5][2];
long long ri[NMAX+5],le[NMAX+5];

void dfs(int nod,int parent){
    int dim=0;
    for(int i=0;i<arb[nod].size();i++){
        if(arb[nod][i]!=parent){
            dfs(arb[nod][i],nod);
        }
    }
    le[0]=1;
    for(int i=0;i<arb[nod].size();i++){
        if(arb[nod][i]!=parent){
            dim++;
            le[dim]=1LL*le[dim-1]*(dp[arb[nod][i]][0]+dp[arb[nod][i]][1])%MOD;
        }
    }
    int j=dim;
    ri[dim+1]=1;
    for(int i=arb[nod].size()-1;i>=0;i--){
        if(arb[nod][i]!=parent){
            ri[j]=1LL*ri[j+1]*(dp[arb[nod][i]][0]+dp[arb[nod][i]][1])%MOD;
            j--;
        }
    }
    if(cart[nod]){
        dp[nod][1]=0;
        dp[nod][0]=le[dim];
    }else{
        j=1;
        dp[nod][1]=le[dim];
        for(int i=0;i<arb[nod].size();i++){
            if(arb[nod][i]!=parent){
                dp[nod][0]=(dp[nod][0]+1LL*(((dp[arb[nod][i]][0]*le[j-1])%MOD)*ri[j+1])%MOD)%MOD;
                j++;
            }
        }
    }
}

int main(){
    fi>>n>>k;
    for(int i=1;i<=k;i++){
        fi>>x;
        cart[x]=1;
    }
    for(int i=1;i<n;i++){
        fi>>x>>y;
        arb[x].push_back(y);
        arb[y].push_back(x);
    }
    dfs(1,0);
    fo<<dp[1][0]<<'\n';
    fi.close();
    fo.close();
}