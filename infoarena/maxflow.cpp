#include <bits/stdc++.h>
#define NMAX 1000
#define MAXVAL (1LL<<31)-1;

using namespace std;

ifstream fi("maxflow.in");
ofstream fo("maxflow.out");

int n,m,x,y,z;
int sol,minf;
int capacity[NMAX+5][NMAX+5],flow[NMAX+5][NMAX+5];
int viz[NMAX+5],p[NMAX+5];
vector<int> G[NMAX+5];
queue<int> q;

bool bfs(){
    while(!q.empty()){
        q.pop();
    }
    for(int i=1;i<=n;i++){
        viz[i]=0;
    }
    q.push(1);
    viz[1]=1;
    int node,node2;
    while(!q.empty()){
        node=q.front();
        q.pop();
        if(node!=n){
            for(int i=0;i<G[node].size();i++){
                node2=G[node][i];
                if(capacity[node][node2]-flow[node][node2]>0&&!viz[node2]){
                    viz[node2]=1;
                    p[node2]=node;
                    q.push(node2);
                }
            }
        }
    }
    return viz[n];
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>x>>y>>z;
        G[x].push_back(y);
        G[y].push_back(x);
        capacity[x][y]+=z;
    }
    while(bfs()){
        for(int j=0;j<G[n].size();j++){
            if(capacity[G[n][j]][n]-flow[G[n][j]][n]>0&&viz[G[n][j]]){
                p[n]=G[n][j];
                minf=MAXVAL;
                for(int i=n;i!=1;i=p[i]){
                    minf=min(minf,capacity[p[i]][i]-flow[p[i]][i]);
                }
                if(minf){
                    for(int i=n;i!=1;i=p[i]){
                        flow[p[i]][i]+=minf;
                        flow[i][p[i]]-=minf;
                    }
                    sol+=minf;
                }
            }
        }
    }
    fo<<sol<<'\n';
    fi.close();
    fo.close();
}