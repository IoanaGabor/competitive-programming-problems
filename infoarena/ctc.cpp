#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 100000

using namespace std;

ifstream f("ctc.in");
ofstream g("ctc.out");

int n,m,x,y;
vector <int> G[NMAX+1],GT[NMAX+1],rez[NMAX+1];
int viz[NMAX+1],ord[NMAX+1],k;

void citire(){
    f>>n>>m;
    for(int i=1;i<=m;i++){
        f>>x>>y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }
}

void dfs_tr(int s){
    viz[s]=1;
    for(int i=0;i<GT[s].size();i++){
        if(!viz[GT[s][i]]){
            dfs_tr(GT[s][i]);
        }
    }
    ord[++k]=s;
}
void dfs(int s){
    viz[s]=1;
    for(int i=0;i<G[s].size();i++){
        if(!viz[G[s][i]]){
            dfs(G[s][i]);
        }
    }
    rez[k].push_back(s);
}

int main() {
    citire();
    for(int i=1;i<=n;i++){
        if(!viz[i]){
            dfs_tr(i);
        }
    }
    k=0;
    for(int i=1;i<=n;i++){
        viz[i]=0;
    }
    for(int i=n;i>=1;i--){
        if(!viz[ord[i]]){
            k++;
            dfs(ord[i]);
        }
    }
    g<<k<<'\n';
    for(int i=1;i<=k;i++){
        for(int j=0;j<rez[i].size();j++){
            g<<rez[i][j]<<' ';
        }
        g<<'\n';
    }
    f.close();
    g.close();
}
