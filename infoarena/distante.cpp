
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define NMAX 50000
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("distante.in");
ofstream g("distante.out");

int t,n,m,s,db[NMAX+5],dist[NMAX+5],inq[NMAX+5],a,b,c;
vector <pair<int,int>> G[NMAX+5];
struct criteriu{
    bool operator()(int x,int y){
        return dist[x]>dist[y];
    }
};
priority_queue<int,vector<int>,criteriu> pq;

bool dijkstra(){
    for(int i=1;i<=n;i++){
        dist[i]=MAXVAL;
        inq[s]=0;
    }
    dist[s]=0;
    pq.push(s);
    inq[s]=1;
    int aux;
    while(!pq.empty()){
        aux=pq.top();
        pq.pop();
        inq[aux]=0;
        for(size_t i=0;i<G[aux].size();i++){
            if(dist[aux]+G[aux][i].second<dist[G[aux][i].first]){
                dist[G[aux][i].first]=dist[aux]+G[aux][i].second;
                if(!inq[G[aux][i].first]){
                    inq[G[aux][i].first]=1;
                    pq.push(G[aux][i].first);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i]!=db[i]){
            return false;
        }
    }
    return true;
}

int main(){
    f>>t;
    while(t--){
        f>>n>>m>>s;
        for(int i=1;i<=n;i++){
            f>>db[i];
            G[i].clear();
        }
        for(int i=1;i<=m;i++){
            f>>a>>b>>c;
            G[a].push_back(make_pair(b,c));
            G[b].push_back(make_pair(a,c));
        }
        if(dijkstra()){
            g<<"DA"<<'\n';
        }else{
            g<<"NU"<<'\n';
        }
    }
    f.close();
    g.close();
}
