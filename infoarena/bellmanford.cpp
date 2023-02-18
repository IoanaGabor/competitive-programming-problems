
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define NMAX 50000
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("bellmanford.in");
ofstream g("bellmanford.out");

int n,m,x,y,cost,dist[NMAX+5],viz[NMAX+5],inq[NMAX+5];
vector <pair<int,int>> G[NMAX+5];
queue <int> q;
void citire(){
    f>>n>>m;
    for(int i=1;i<=m;i++){
        f>>x>>y>>cost;
        G[x].push_back(make_pair(y,cost));
    }
}

bool bellmanford(int start){
    for(int i=2;i<=n;i++){
        dist[i]=MAXVAL;
    }
    inq[start]=1;
    q.push(start);
    while(!q.empty()){
        start=q.front();
        q.pop();
        inq[start]=0;
        viz[start]++;
        if(viz[start]>=n){
            return false;
        }
        for(size_t i=0;i<G[start].size();i++){
            y=G[start][i].first;
            cost=G[start][i].second;
            if(dist[start]+cost<dist[y]){
                dist[y]=dist[start]+cost;
                if(inq[y]==0){
                    inq[y]=1;
                    q.push(y);
                }
            }
        }
    }
    return true;
}

int main(){
    citire();
    if(bellmanford(1)){
        for(int i=2;i<=n;i++){
            g<<dist[i]<<' ';
        }
    }else{
        g<<"Ciclu negativ!";
    }
    f.close();
    g.close();
}
