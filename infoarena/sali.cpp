
#include <bits/stdc++.h>
#define NMAX 1000

using namespace std;

ifstream fi("sali.in");
ofstream fo("sali.out");

int n,m,a,b,nc;
vector<int> G[NMAX+5];
vector<int> ctc[NMAX+5];
queue<int> q;
int dist[NMAX+5];
int nodm,distm,d;
int sali;

void df(int nod){
    dist[nod]=1;
    ctc[nc].push_back(nod);
    for(int i=0;i<G[nod].size();i++){
        if(!dist[G[nod][i]]){
            df(G[nod][i]);
        }
    }
}

int distmax(int sn){
    q.push(sn);
    int nod,ret=1;
    dist[sn]=sali+1;
    while(!q.empty()){
        nod=q.front();
        q.pop();
        ret=max(ret,dist[nod]-dist[sn]+1);
        for(int i=0;i<G[nod].size();i++){
            if(dist[G[nod][i]]>dist[nod]+1){
                dist[G[nod][i]]=dist[nod]+1;
                q.push(G[nod][i]);
            }
        }
    }
    return ret;
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!dist[i]){
            nc++;
            df(i);
        }
    }
    for(int i=1;i<=nc;i++){
        distm=-1;
        for(int j=0;j<ctc[i].size();j++){
            for(int k=0;k<ctc[i].size();k++){
                dist[ctc[i][k]]=NMAX+5;
            }
            d=distmax(ctc[i][j]);
            if(distm<d){
                distm=d;
                nodm=ctc[i][j];
            }
        }
        for(int k=0;k<ctc[i].size();k++){
            dist[ctc[i][k]]=NMAX+5;
        }
        distmax(nodm);
        sali+=distm;   ///cum am putut scrie +d in loc de +distm??
    }
    fo<<sali<<'\n';
    for(int i=1;i<=n;i++){
        fo<<dist[i]<<' ';
    }
    fi.close();
    fo.close();
}