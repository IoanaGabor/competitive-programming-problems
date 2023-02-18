
#include <bits/stdc++.h>
#define NMAX 350
#define inf (1LL<<31)-1

using namespace std;

ifstream fi("fmcm.in");
ofstream fo("fmcm.out");

int n,m,s,d,x,y,c,z;
int cap[NMAX+5][NMAX+5],cst[NMAX+5][NMAX+5];
int inq[NMAX+5];
int old_d[NMAX+5],real_d[NMAX+5],dist[NMAX+5];
int p[NMAX+5];
vector<int> G[NMAX+5];
priority_queue <pair<int,int> > pq;
int sol;

bool dijkstra(){
    for(int i=1;i<=n;i++){
        dist[i]=inf;
    }    
    dist[s]=0;
    real_d[s]=0;
    pq.push({0,s});
    int new_dist;
    while(!pq.empty()){
        x=pq.top().second;
        z=-pq.top().first;
        pq.pop();
        if(dist[x]!=z){
            continue;
        }
        for(auto y:G[x]){
            if(cap[x][y]){
                new_dist=dist[x]+cst[x][y]+old_d[x]-old_d[y];
                if(new_dist<dist[y]){
                    dist[y]=new_dist;
                    real_d[y]=real_d[x]+cst[x][y];
                    p[y]=x;
                    pq.push({-dist[y],y});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        old_d[i]=real_d[i];
    }
    if(dist[d]==inf){
        return false;
    }
    int mini=inf;
    for(int nod=d;nod!=s;nod=p[nod]){
        mini=min(mini,cap[p[nod]][nod]);
    }
    for(int nod=d;nod!=s;nod=p[nod]){
        cap[nod][p[nod]]+=mini;
        cap[p[nod]][nod]-=mini;
    }
    sol+=mini*real_d[d];
    return true;
}

void bellmanford(){
    for(int i=1;i<=n;i++){
        old_d[i]=inf;
    }
    old_d[s]=0;
    queue <int> q;
    q.push(s),inq[s]=1;
    while(!q.empty()){
        x=q.front(),q.pop(),inq[x]=0;
        for(auto y: G[x]){
            if(cap[x][y]){
                if(old_d[x]+cst[x][y]<old_d[y]){
                   old_d[y]=old_d[x]+cst[x][y];
                   if(!inq[y]){
                       inq[y]=1;
                       q.push(y);
                   }
                }
            }
        }
    }
}

int main(){
    fi>>n>>m>>s>>d;
    for(int i=1;i<=m;i++){
        fi>>x>>y>>c>>z;        
        cap[x][y]=c;
        cst[x][y]=z,cst[y][x]=-z;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    bellmanford();
    while(dijkstra());
    fo<<sol<<'\n';
    fi.close();
    fo.close();
}
