
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define NMAX 36000
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("catun.in");
ofstream g("catun.out");

int n,m,k,fortarete[NMAX+5],x,y,z,dist[NMAX+5],rez[NMAX+5],inq[NMAX+5];
vector <pair<int,int>> G[NMAX+5];

struct criteriu{
    bool operator()(int a,int b){
        return dist[a]>dist[b];
    }
};

priority_queue<int,vector<int>,criteriu> q;

void dijkstra(){
    for(int i=1;i<=n;i++){
        dist[i]=MAXVAL;
    }
    for(int i=1;i<=k;i++){
        dist[fortarete[i]]=0;
        q.push(fortarete[i]);
        inq[fortarete[i]]=1;
    }
    while(!q.empty()){
        x=q.top();
        q.pop();
        inq[x]=0;
        for(size_t i=0;i<G[x].size();i++){
            if(dist[x]+G[x][i].second<dist[G[x][i].first]){
                dist[G[x][i].first]=dist[x]+G[x][i].second;
                rez[G[x][i].first]=rez[x];
                if(!inq[G[x][i].first]){
                    inq[G[x][i].first]=1;
                    q.push(G[x][i].first);
                }
            }else if(dist[x]+G[x][i].second==dist[G[x][i].first]){
                if(rez[G[x][i].first]>rez[x]){
                    rez[G[x][i].first]=rez[x];
                    if(!inq[G[x][i].first]){
                        inq[G[x][i].first]=1;
                        q.push(G[x][i].first);
                    }
                }
            }
        }
    }
    for(int i=1;i<=k;i++){
        rez[fortarete[i]]=0;
    }
}

int main(){
    f>>n>>m>>k;
    for(int i=1;i<=k;i++){
        f>>fortarete[i];
        rez[fortarete[i]]=fortarete[i];
    }
    for(int i=1;i<=m;i++){
        f>>x>>y>>z;
        G[x].push_back(make_pair(y,z));
        G[y].push_back(make_pair(x,z));
    }
    dijkstra();
    for(int i=1;i<=n;i++){
        g<<rez[i]<<' ';
    }
    f.close();
    g.close();
}
