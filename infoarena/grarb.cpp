
#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream f("grarb.in");
ofstream g("grarb.out");

int n,m,nrm[NMAX+5],viz[NMAX+5],x,y,cntm,cntn,rez1,rez2=-1;
vector <int> G[NMAX+5];

void dfs(int nod){
    cntm+=nrm[nod];
    cntn++;
    viz[nod]=1;
    for(int i=0;i<G[nod].size();i++){
        if(viz[G[nod][i]]==0){
            dfs(G[nod][i]);
        }
    }
}

int main(){
    f>>n>>m;
    for(int i=1;i<=m;i++){
        f>>x>>y;
        nrm[x]++,nrm[y]++;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(viz[i]==0){
            cntm=0;
            cntn=0;
            dfs(i);
            cntm/=2;
            rez1+=(cntm-cntn+1);
            rez2++;
        }
    }
    g<<rez1<<'\n'<<rez2<<'\n';
    f.close();
    g.close();
}
