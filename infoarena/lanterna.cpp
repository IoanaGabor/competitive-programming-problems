
#include <bits/stdc++.h>
#define NMAX 50
#define KMAX 1000
#define inf (1LL<<31)-1

using namespace std;

ifstream fi("lanterna.in");
ofstream fo("lanterna.out");

struct edge{
    int to,t,w;
};

int n,m,k,x,y,t,w,ww;
int baza[NMAX+5];
vector<edge> G[NMAX+5];
int dp[NMAX+5][KMAX+5]; ///dp[i][j] timpul minim ca sa ajung in i cu cost j
int inq[NMAX+5][KMAX+5];
queue<pair<int,int>> q;
int tmin,lanterna;

void update(int kk){
    if(baza[y]){
        w=0;
    }
    if(dp[y][w]>t){
        dp[y][w]=t;
        if(!inq[y][w]){
            inq[y][w]=1;
            q.push({y,w});
        }
    }
}

int bellman_ford(int kk){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=inf;
            inq[i][j]=0;
        }
    }
    dp[1][0]=0;
    q.push({1,0});
    inq[1][0]=1;
    while(!q.empty()){
        x=q.front().first;
        ww=q.front().second;
        q.pop();
        inq[x][ww]=0;
        for(int i=0;i<G[x].size();i++){
            y=G[x][i].to;
            t=G[x][i].t+dp[x][ww];
            w=G[x][i].w+ww;
            if(w<=kk){
                update(kk);
            }
        }
    }
    int ret=dp[n][0];
    for(int i=1;i<=kk;i++){
        ret=min(ret,dp[n][i]);
    }
    return ret;
}

int cauta_lanterna(){
    int pas=1<<9,ret=0;
    while(pas){
        if(bellman_ford(ret+pas)>tmin){
            ret+=pas;
        }
        pas>>=1;
    }
    ret++;
    return ret;
}

int main(){
    fi>>n>>k;
    for(int i=1;i<=n;i++){
        fi>>baza[i];
    }
    fi>>m;
    for(int i=1;i<=m;i++){
        fi>>x>>y>>t>>w;
        G[x].push_back({y,t,w});
        G[y].push_back({x,t,w});
    }
    tmin=bellman_ford(k);
    lanterna=cauta_lanterna();
    fo<<tmin<<' '<<lanterna;
    fi.close();
    fo.close();
}