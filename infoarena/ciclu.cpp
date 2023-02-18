
#include <bits/stdc++.h>
#define NMAX 1000
#define MAXVAL (1LL<<50);

using namespace std;

ifstream fi("ciclu.in");
ofstream fo("ciclu.out");

int n,m,x,y,c;
vector<pair<int,long long> > G[NMAX+5];
queue<int> q;
long long dist[NMAX+5];
int viz[NMAX+5];
int inq[NMAX+5];
int viz2[NMAX+5];

bool ok(int val){
    for(int i=1;i<=n;i++){
        dist[i]=MAXVAL;        
        viz[i]=viz2[i]=0;
        inq[i]=0;
    }
    for(int nod=1;nod<=n;nod++){
        if(!viz2[nod]){
            dist[nod]=0;
            q.push(nod);
            inq[nod]=1;
            while(!q.empty()){
                x=q.front();
                q.pop();
                inq[x]=0;
                viz2[x]=1;
                for(int i=0;i<G[x].size();i++){
                    y=G[x][i].first;
                    c=G[x][i].second;
                    if(dist[y]>dist[x]+1LL*(c-val)){
                        dist[y]=dist[x]+1LL*(c-val);
                        if(!inq[y]){
                            viz[y]++;
                            if(viz[y]>n){
                                return false;
                            }
                            q.push(y);
                            inq[y]=1;
                        }
                    }
                }
            }
        }
    }
    return true;
}

void cauta(){
    long long pas=(1<<29),rez=0;
    while(pas){
        if(ok(rez+pas)){
            rez+=pas;
        }
        pas>>=1;
    }
    fo<<fixed<<setprecision(2)<<(rez*1.0/1000)<<'\n';
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>x>>y>>c;
        G[x].push_back({y,c*1000});
    }
    cauta();
    fi.close();
    fo.close();
}