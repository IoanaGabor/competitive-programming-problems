
#include <bits/stdc++.h>
#define NMAX 1000000

using namespace std;

ifstream fi("berarii2.in");
ofstream fo("berarii2.out");

int n,m,p,x,y;
vector<int> G[NMAX+5];
int viz[NMAX+5];
int cnt;
queue <int> q;

void bfs(){
    while(!q.empty()){
        x=q.front();
        q.pop();
        for(int i=0;i<G[x].size();i++){
            if(!viz[G[x][i]]){
                viz[G[x][i]]=1;
                cnt--;
                q.push(G[x][i]);
            }
        }
    }
}

int main(){
    fi>>n>>m>>p;
    cnt=n;
    for(int i=1;i<=m;i++){
        fi>>x>>y;
        G[y].push_back(x);
    }
    for(int i=1;i<=p;i++){
        fi>>x;
        viz[x]=1;
        cnt--;
        q.push(x);
    }
    bfs();
    fo<<cnt<<'\n';
    for(int i=1;i<=n;i++){
        if(!viz[i]){
            fo<<i<<'\n';
        }
    }
    fi.close();
    fo.close();
}