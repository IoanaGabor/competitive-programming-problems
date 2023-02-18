
#include <bits/stdc++.h>
#define NMAX 21000

using namespace std;

ifstream fi("amici2.in");
ofstream fo("amici2.out");

int t,n,m,x,y;
vector<int> G[NMAX+5];
int d[NMAX+5],maxd;
queue<int> q;
int rez,p;

void bfs(int start){
    q.push(start);
    d[start]=0;
    int nod;
    while(!q.empty()){
        nod=q.front();
        q.pop();
        maxd=max(maxd,d[nod]);
        for(int i=0;i<G[nod].size();i++){
            if(d[G[nod][i]]==-1){
                d[G[nod][i]]=d[nod]+1;
                q.push(G[nod][i]);
            }
        }
    }
}

int main(){
    fi>>t;
    while(t--){
        fi>>n>>m;
        for(int i=1;i<=n;i++){
            G[i].clear();
            d[i]=-1;
        }
        maxd=0;
        for(int i=1;i<=m;i++){
            fi>>x>>y;
            if(x!=y){
                G[x].push_back(y);
                G[y].push_back(x);
            }
        }
        bfs(y);
        rez=0;
        p=1;
        while(p<maxd){
            p<<=1;
            rez++;
        }
        fo<<rez<<'\n';
    }
    fi.close();
    fo.close();
}