
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#define NMAX 7500
#define MMAX 14000

using namespace std;

ifstream f("graf.in");
ofstream g("graf.out");

int n,m,x,y,a,b,l;
int lx[NMAX+5],dx[NMAX+5],ly[NMAX+5],dy[NMAX+5];
vector<int> adj[NMAX+5];
queue <int> q;

void bfs(int start,int lg[],int d[]){
    q.push(start);
    lg[start]=0;
    d[start]=1;
    while(!q.empty()){
        start=q.front();
        q.pop();
        l=adj[start].size();
        for(int i=0;i<l;i++){
            if(lg[adj[start][i]]==lg[start]+1){
                d[adj[start][i]]+=d[start];
            }
            if(lg[adj[start][i]]==-1){
                lg[adj[start][i]]=lg[start]+1;
                d[adj[start][i]]=d[start];
                q.push(adj[start][i]);
            }
        }
    }
}

int main(){
    f>>n>>m>>x>>y;
    for(int i=1;i<=m;i++){
        f>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        lx[i]=ly[i]=-1;
    }
    bfs(x,lx,dx);
    bfs(y,ly,dy);
    l=0;
    for(int i=1;i<=n;i++){
        if(lx[i]+ly[i]==lx[y]&&dx[i]*dy[i]==dx[y]){
            l++;
        }
    }
    g<<l<<'\n';
    for(int i=1;i<=n;i++){
        if(lx[i]+ly[i]==lx[y]&&dx[i]*dy[i]==dx[y]){
            g<<i<<' ';
        }
    }
    f.close();
    g.close();
}
