
#include <bits/stdc++.h>
#define NMAX 100
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("pm2.in");
ofstream g("pm2.out");

int n,timp[NMAX+5],m,k,earliest[NMAX+5],latest[NMAX+5],sortat[NMAX+5],ls,ext[NMAX+5],interior[NMAX+5];
vector <int> G[NMAX+5],GT[NMAX+5];
queue <int> q;

void sortare_topologica(){
    q.push(0);
    while(!q.empty()){
        k=q.front();
        q.pop();
        sortat[++ls]=k;
        for(int i=0;i<G[k].size();i++){
            ext[G[k][i]]--;
            if(ext[G[k][i]]==0){
                q.push(G[k][i]);
            }
        }
    }
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>timp[i];
    }
    for(int i=1;i<=n;i++){
        f>>m;
        while(m--){
            f>>k;
            G[k].push_back(i);
            ext[i]++;
            GT[i].push_back(k);
            interior[k]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(ext[i]==0){
            G[0].push_back(i);
            GT[i].push_back(0);
            ext[i]++;
            interior[0]++;
        }
        if(interior[i]==0){
            G[i].push_back(n+1);
            GT[n+1].push_back(i);
            ext[n+1]++;
            interior[i]++;            
        }
        latest[i]=MAXVAL;
    }
    sortare_topologica();
    earliest[0]=0;
    latest[0]=0;
    for(int i=2;i<=ls;i++){
        k=sortat[i];
        for(int j=0;j<GT[k].size();j++){
            earliest[k]=max(earliest[GT[k][j]]+timp[GT[k][j]],earliest[k]);
        }
    }
    latest[n+1]=earliest[n+1];
    for(int i=ls-1;i>=0;i--){
        k=sortat[i];
        for(int j=0;j<G[k].size();j++){
            latest[k]=min(latest[G[k][j]]-timp[k],latest[k]);
        }
    }
    g<<latest[n+1]<<'\n';
    for(int i=1;i<=n;i++){
        g<<earliest[i]<<' '<<latest[i]<<'\n';
    }
    f.close();
    g.close();
}

































