
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define KMAX 15
#define NMAX 2000
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("ubuntzei.in");
ofstream g("ubuntzei.out");

int n,m,k,c[NMAX+5],dist[NMAX+5],inq[NMAX+5],special[NMAX+5],G2[NMAX+5][NMAX+5],dp[1<<(KMAX+5)][KMAX+5],rez;
vector <pair<int,int> > G[NMAX+5];

struct criteriu{
    bool operator()(int x,int y){
        return dist[x]>dist[y];
    }
};
priority_queue <int,vector<int>,criteriu> q;

void citire(){
    int x,y,cost;
    f>>n>>m>>k;
    for(int i=1;i<=k;i++){
        f>>c[i];
        special[c[i]]=i+1;
    }
    special[1]=1;
    special[n]=k+2;
    for(int i=1;i<=m;i++){
        f>>x>>y>>cost;
        G[x].push_back(make_pair(y,cost));
        G[y].push_back(make_pair(x,cost));
    }
}

void dijkstra(int start,int ind){
    for(int i=1;i<=n;i++){
        dist[i]=MAXVAL;
    }
    dist[start]=0;
    inq[start]=1;
    q.push(start);
    int x,y,cost;
    while(!q.empty()){
        x=q.top();
        q.pop();
        inq[x]=0;
        for(size_t i=0;i<G[x].size();i++){
            y=G[x][i].first;
            cost=G[x][i].second;
            if(dist[y]>dist[x]+cost){
                dist[y]=dist[x]+cost;
                if(!inq[y]){
                    inq[y]=1;
                    q.push(y);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(special[i]&&i!=start){
            G2[ind][special[i]]=dist[i];
        }
    }
}

void constr(){
    dijkstra(1,1);
    dijkstra(n,k+2);
    for(int i=1;i<=k;i++){
        dijkstra(c[i],i+1);
    }
    k+=2;
}

void hamilton(){
    for(int stare=0;stare<(1<<k);stare++){
        for(int i=1;i<=k;i++){
            dp[stare][i]=MAXVAL;
        }
    }
    dp[1][1]=0;
    for(int stare=0;stare<(1<<k)-1;stare++){
        for(int i=1;i<=k;i++){
            if(stare&(1<<(i-1))&&dp[stare][i]!=MAXVAL){
                for(int j=1;j<=k;j++){
                    if(i!=j&&G2[i][j]!=0&& !(stare&(1<<(j-1)))){
                        dp[stare+(1<<(j-1))][j]=min(dp[stare+(1<<(j-1))][j],dp[stare][i]+G2[i][j]);
                    }
                }
            }
        }
    }
    rez=dp[(1<<k)-1][k];
}

int main(){
    citire();
    constr();
    hamilton();
    g<<rez;
    f.close();
    g.close();
}

