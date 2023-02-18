#include <bits/stdc++.h>
#define NMAX 100000
#define BASE 26
#define MOD1 666013
#define MOD2 1000009

using namespace std;

ifstream fi("aiacupalindroame.in");
ofstream fo("aiacupalindroame.out");

vector<int> G[NMAX+5]; 
int n,q,x,y;
char et[NMAX+5];
int h1[NMAX+5],h2[NMAX+5],lev[NMAX+5];

void dfs(int nod,int parent){
    h1[nod]=(h1[parent]*BASE+et[nod])%MOD1;
    h2[nod]=(h2[parent]*BASE+et[nod])%MOD2;
    lev[nod]=lev[parent]+1;
    for(int i=0;i<G[nod].size();i++){
        dfs(G[nod][i],nod);
    }
}

int main(){
    fi>>n>>q;
    for(int i=2;i<=n;i++){
        fi>>y;
        G[y].push_back(i);
    }
    fi>>(et+2);
    dfs(1,0);
    while(q--){
        fi>>x>>y;
        if(lev[x]==lev[y]&&h1[x]==h1[y]&&h2[x]==h2[y]){
            fo<<1<<'\n';
        }else{
            fo<<0<<'\n';
        }
    }
}