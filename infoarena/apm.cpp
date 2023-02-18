
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define NMAX 200000
#define pii pair<int,pair<int,int> >

using namespace std;

ifstream f("apm.in");
ofstream g("apm.out");

int n,m,x,y,cost,arb[NMAX+5],lrez,suma;
vector <pair<int,int> > G[NMAX+5];
priority_queue <pii,vector<pii>,greater<pii>> pq;
pii aux;
pair <int,int> rez[NMAX+5];

int main(){
    f>>n>>m;
    for(int i=1;i<=m;i++){
        f>>x>>y>>cost;
        G[x].push_back(make_pair(y,cost));
        G[y].push_back(make_pair(x,cost));
    }
    x=1;
    arb[x]=1;
    for(int i=0;i<G[x].size();i++){
        pq.push(make_pair(G[x][i].second,make_pair(x,G[x][i].first)));
    }
    while(!pq.empty()){
        aux=pq.top();
        pq.pop();
        x=aux.second.first;
        y=aux.second.second;
        cost=aux.first;
        if(arb[y]==0){
            rez[++lrez].first=x;
            rez[lrez].second=y;
            suma+=cost;
            arb[y]=1;
            for(int i=0;i<G[y].size();i++){
                if(arb[G[y][i].first]==0){
                    pq.push(make_pair(G[y][i].second,make_pair(y,G[y][i].first)));
                }
            }
        }
    }
    g<<suma<<'\n'<<lrez<<'\n';
    for(int i=1;i<=lrez;i++){
        g<<rez[i].first<<' '<<rez[i].second<<'\n';
    }
    f.close();
    g.close();
}
