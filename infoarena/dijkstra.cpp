
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define NMAX 50000
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("dijkstra.in");
ofstream g("dijkstra.out");

int dist[NMAX+5],n,m,x,y,cost,inq[NMAX+5];
vector <pair<int,int> > G[NMAX+5];
struct criteriu{
    bool operator()(int x,int y){
        return dist[x]>dist[y];
    }
};
priority_queue <int,vector<int>,criteriu> q;

int main(){
    f>>n>>m;
    for(int i=1;i<=m;i++){
        f>>x>>y>>cost;
        G[x].push_back(make_pair(y,cost));
    }
    for(int i=2;i<=n;i++){
        dist[i]=MAXVAL;
    }
    dist[1]=0;
    q.push(1);
    inq[1]=1;
    while(!q.empty()){
        x=q.top();
        q.pop();
        inq[x]=0;
        for(size_t i=0;i<G[x].size();i++){
            y=G[x][i].first;
            cost=G[x][i].second;
            if(dist[y]>dist[x]+cost){
                dist[y]=dist[x]+cost;
                if(inq[y]==0){
                    q.push(y);
                    inq[y]=1;
                }
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(dist[i]==MAXVAL){
            g<<0<<' ';
        }else{
            g<<dist[i]<<' ';
        }
    }
    f.close();
    g.close();
}
