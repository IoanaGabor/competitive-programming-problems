
#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 100000
 
using namespace std;
 
ifstream f("lca.in");
ofstream g("lca.out");
 
int n,q,u,v,euler[2*NMAX+5],le,L[2*NMAX+5],ap[NMAX+5],log2[2*NMAX+5],rmq[25][2*NMAX+5];
vector<int> G[NMAX+5];
 
void citire(){
    f>>n>>q;
    int x;
    for(int i=2;i<=n;i++){
        f>>x;
        G[x].push_back(i);
    }
}
 
void dfs(int nod,int parinte,int level){
    euler[++le]=nod;
    L[le]=level;
    ap[nod]=le;
    for(int i=0;i<G[nod].size();i++){
        if(G[nod][i]!=parinte){
            dfs(G[nod][i],nod,level+1);
            euler[++le]=nod;
            L[le]=level;
        }
    }
}
 
void RMQ(){
    rmq[0][1]=1;
    for(int i=2;i<=le;i++){
        log2[i]=log2[i>>1]+1;
        rmq[0][i]=i;
    }
    for(int j=1;(1<<j)<=le;j++){
        for(int i=1;i+(1<<j)-1<=le;i++){
            if(L[rmq[j-1][i]]<L[rmq[j-1][i+(1<<(j-1))]]){
                rmq[j][i]=rmq[j-1][i];
            }else{
                rmq[j][i]=rmq[j-1][i+(1<<(j-1))];
            }
        }
    }
}
 
int lca(){
    if(ap[u]>ap[v]){
        swap(u,v);
    }
    u=ap[u];
    v=ap[v];
    int l=log2[v-u+1];
    if(L[rmq[l][u]]<L[rmq[l][v-(1<<l)+1]]){
        return euler[rmq[l][u]];
    }else{
        return euler[rmq[l][v-(1<<l)+1]];
    }
}
 
void solve(){
    while(q--){
        f>>u>>v;
        g<<lca()<<'\n';
    }
}
 
int main(){
    citire();
    dfs(1,0,1);
    RMQ();
    solve();
    f.close();
    g.close();
}