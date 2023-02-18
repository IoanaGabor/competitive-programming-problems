
#include <bits/stdc++.h>
#define NMAX 200002
#define MOD 666013

using namespace std;

ifstream fi("clepsidra.in");
ofstream fo("clepsidra.out");

int n,m,x,y,top;
vector <int> G[NMAX+5];
int low[NMAX+5],ind[NMAX+5],c[NMAX+5],art[NMAX+5];
int twotothepowerof[NMAX+5];
int rez;

void dfs(int nod,int parent,int lev){
    int cnt=0;
    low[nod]=ind[nod]=lev;
    for(int i=0;i<G[nod].size();i++){
        if(G[nod][i]!=parent){
            if(ind[G[nod][i]]!=-1){
                low[nod]=min(low[nod],ind[G[nod][i]]);
            }else{
                dfs(G[nod][i],nod,lev+1);
                low[nod]=min(low[nod],low[G[nod][i]]);
                if(low[G[nod][i]]>=ind[nod]){
                    art[nod]=1;
                    c[nod]++;
                }
            }
        }
    }
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    twotothepowerof[0]=1;
    for(int i=1;i<=n;i++){
        low[i]=ind[i]=-1;
        twotothepowerof[i]=(twotothepowerof[i-1]*2)%MOD;
    }
    dfs(1,0,0);
    for(int i=1;i<=n;i++){
        rez=0;
        if(i==1){
            rez+=twotothepowerof[c[i]]-2+MOD;
        }else if(art[i]){
            rez+=twotothepowerof[c[i]+1]-2+MOD;
        }
        rez%=MOD;
        fo<<rez<<' '<<'\n';
    }
    fi.close();
    fo.close();
}