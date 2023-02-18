
#include <bits/stdc++.h>
#define NMAX 50000

using namespace std;

ifstream fi("retele.in");
ofstream fo("retele.out");

int n,m,x,y;
vector<int> G[NMAX+5],GT[NMAX+5];
int ord[NMAX+5],lo;
int viz[NMAX+5];
vector<vector<int> > ctc;
vector<int> comp;

void dfst(int nod){
    viz[nod]=1;
    for(int i=0;i<GT[nod].size();i++){
        if(!viz[GT[nod][i]]){
            dfst(GT[nod][i]);
        }
    }
    ord[++lo]=nod;
}

void dfs(int nod){
    viz[nod]=0;
    comp.push_back(nod);
    for(int i=0;i<G[nod].size();i++){
        if(viz[G[nod][i]]){
            dfs(G[nod][i]);
        }
    }
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>x>>y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!viz[i]){
            dfst(i);
        }
    }
    for(int i=n;i>=1;i--){
        if(viz[ord[i]]){
            comp.clear();
            dfs(ord[i]);
            sort(comp.begin(),comp.end());
            ctc.push_back(comp);
        }
    }
    sort(ctc.begin(),ctc.end());
    fo<<ctc.size()<<'\n';
    for(int i=0;i<ctc.size();i++){
        fo<<ctc[i].size()<<' ';
        for(int j=0;j<ctc[i].size();j++){
            fo<<ctc[i][j]<<' ';
        }
        fo<<'\n';
    }
    fi.close();
    fo.close();
}