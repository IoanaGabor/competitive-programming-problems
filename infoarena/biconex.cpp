
#include <bits/stdc++.h>
#define NMAX 100000
#define MMAX 200000

using namespace std;

ifstream fi("biconex.in");
ofstream fo("biconex.out");

int n,m,x,y;
vector<int> G[NMAX+5];
int ind[NMAX+5],low[NMAX+5],top;
pair<int,int> stiva[MMAX+5];
vector<vector<int>> rez;
vector<int> aux;

void biconex(int lx,int ly){
    aux.clear();
    x=stiva[top].first;
    y=stiva[top].second;
    top--;
    aux.push_back(y);
    while(lx!=x&&ly!=y){
        x=stiva[top].first;
        y=stiva[top].second;
        top--;
        aux.push_back(y);
    }
    aux.push_back(x);
    rez.push_back(aux);
}

void df(int node,int father,int nr){
    ind[node]=low[node]=nr;
    for(int i=0;i<G[node].size();i++){
        if(G[node][i]!=father){
            if(ind[G[node][i]]==-1){
                stiva[++top]=make_pair(node,G[node][i]);
                df(G[node][i],node,nr+1);
                low[node]=min(low[node],low[G[node][i]]);
                if(low[G[node][i]]>=ind[node]){
                    biconex(node,G[node][i]);
                }
            }else{
                low[node]=min(low[node],ind[G[node][i]]);
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
    for(int i=1;i<=n;i++){
        ind[i]=-1;
    }
    df(1,0,0);
    fo<<rez.size()<<'\n';
    for(int i=0;i<rez.size();i++){
        for(int j=0;j<rez[i].size();j++){
            fo<<rez[i][j]<<' ';
        }
        fo<<'\n';
    }
    fi.close();
    fo.close();
}