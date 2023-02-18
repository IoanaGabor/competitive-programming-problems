
#include <bits/stdc++.h>
#define NMAX 800
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream fi("dragoni.in");
ofstream fo("dragoni.out");

int p,n,m;
int dmax[NMAX+5],inq[NMAX+5];
vector <pair<int,int> > G[NMAX+5];
struct crit{
    bool operator()(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
        return a.first>b.first;
    }
};
priority_queue <pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,crit>  pq;
pair<int,int> comp[NMAX+5];

void read(){
    int a,b,d;
    fi>>p>>n>>m;
    for(int i=1;i<=n;i++){
        fi>>dmax[i];
        comp[i].first=MAXVAL;
        comp[i].second=i;
    }
    comp[1].first=0;
    for(int i=1;i<=m;i++){
        fi>>a>>b>>d;
        G[a].push_back(make_pair(b,d));
        G[b].push_back(make_pair(a,d));
    }
}

void one(){
    queue <int> q;
    q.push(1);
    int dmaxi=dmax[1],x;
    inq[1]=1;
    while(!q.empty()){
        x=q.front();
        q.pop();
        dmaxi=max(dmaxi,dmax[x]);
        for(int i=0;i<G[x].size();i++){
            if(G[x][i].second<=dmax[1]&&!inq[G[x][i].first]){
                q.push(G[x][i].first);
                inq[G[x][i].first]=1;
            }
        }
    }
    fo<<dmaxi;
}

void two(){
    pq.push(make_pair(0,make_pair(1,1)));
    pair<int,pair<int,int>> x,newx;
    while(!pq.empty()){
        x=pq.top();
        pq.pop();
        if(x.second.first==n){
            fo<<x.first;
            return;            
        }
        for(int i=0;i<G[x.second.first].size();i++){
            if(G[x.second.first][i].second<=dmax[x.second.second]){
                newx=x;
                if(dmax[G[x.second.first][i].first]>dmax[x.second.second]){
                    newx.second.second=G[x.second.first][i].first;
                }                
                newx.first+=G[x.second.first][i].second;
                newx.second.first=G[x.second.first][i].first;
                if(newx.first<comp[newx.second.first].first||dmax[newx.second.second]>dmax[comp[newx.second.first].second]){
                    comp[newx.second.first].first=newx.first;
                    comp[newx.second.first].second=newx.second.second;
                    pq.push(newx);
                }
            }
        }
    }
}

void solve(){
    if(p==1){
        one();
    }else{
        two();
    }
}

int main(){
    read();
    solve();
    fi.close();
    fo.close();
}