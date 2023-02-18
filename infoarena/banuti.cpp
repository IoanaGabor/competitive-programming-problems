#include <bits/stdc++.h>
#define NMAX 50000
#define VMIN 5000
#define VMAX 1000005000
 
using namespace std;
 
ifstream fi("banuti.in");
ofstream fo("banuti.out");
 
int n,nod,newnod,minim;
int v[NMAX+5];
long long dist[VMIN+5];
bool viz[VMIN+5];
long long sol;
priority_queue<long long> pq;
int edges[NMAX+5],le;

int main(){
    fi>>n;
    for(int i=1;i<=n;i++){
        fi>>v[i];
    }
    sort(v+1,v+n+1); 
    minim=v[1];
    for(int i=0;i<minim;i++){
        dist[i]=VMAX;
    }
    for(int i=1;i<=n;i++){
        if(!viz[v[i]%minim]){
            viz[v[i]%minim]=1;
            edges[++le]=v[i];
        }
    }
    pq.push(0);
    while(!pq.empty()){
        nod=-pq.top();
        pq.pop();
        if(dist[nod%minim]==VMAX){
            dist[nod%minim]=nod;
            for(int i=1;i<=le;i++){
                if(dist[(nod+edges[i])%minim]==VMAX){
                    pq.push(-(nod+edges[i]));
                }
            }
        }
    }
    for(int i=0;i<minim;i++){
        if(dist[i]==VMAX){
            fo<<-1<<'\n';
            fi.close();
            fo.close();
            return 0;
        }
        sol=max(sol,dist[i]);
    }
    fo<<sol-minim;
    fi.close();
    fo.close();
}