
#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("reinvent.in");
ofstream fo("reinvent.out");

int n,m,k,x,y;
vector<int> G[NMAX+5];
int cart[NMAX+5],dist[NMAX+5],p[NMAX+5];
queue<int> q;

void bfs(){
    while(!q.empty()){
        x=q.front();
        q.pop();
        for(int i=0;i<G[x].size();i++){
            y=G[x][i];
            if(dist[y]==0&&p[x]!=p[y]){
                dist[y]=dist[x]+1;
                p[y]=p[x];
                q.push(y);
            }else if(dist[y]&&p[x]!=p[y]){
                fo<<dist[x]+dist[y]+1<<'\n';
                return;
            }
        }
    }
}

int main(){
    fi>>n>>m>>k;
    for(int i=1;i<=m;i++){
        fi>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=k;i++){
        fi>>x;
        cart[x]=1;
        p[x]=x;
        q.push(x);
    }
    bfs();
    fi.close();
    fo.close();
}
