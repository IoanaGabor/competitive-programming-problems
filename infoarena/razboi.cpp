
#include <bits/stdc++.h>
#define NMAX 16000

using namespace std;

ifstream fi("razboi.in");
ofstream fo("razboi.out");

struct HeapNode{
    int nod,costl;
    bool operator <(const HeapNode &other) const{
        return costl> other.costl;
    }
};

int t,n,x,y,c;
vector<pair<int,int> > arb[NMAX+5];
int grad[NMAX+5];
priority_queue <HeapNode> pq;
int sters[NMAX+5];
int maxlant[NMAX+5];

int main(){
    fi>>t;
    for(int test=1;test<=t;test++){
        fi>>n;
        for(int i=1;i<n;i++){
            fi>>x>>y>>c;
            arb[x].push_back({y,c});
            arb[y].push_back({x,c});
            grad[x]++;
            grad[y]++;   
        }
        for(int i=1;i<=n;i++){
            if(grad[i]==1){
                pq.push({i,arb[i][0].second});
            }
        }
        for(int i=1;i<=n-2;i++){
            x=pq.top().nod;
            c=pq.top().costl;
            pq.pop();
            sters[x]=1;
            for(int j=0;j<arb[x].size();j++){
                y=arb[x][j].first;
                if(!sters[y]){
                    maxlant[y]=max(maxlant[y],c);
                    grad[y]--;
                    if(grad[y]==1){
                        for(int k=0;k<arb[y].size();k++){
                            if(!sters[arb[y][k].first]){
                                pq.push({y,arb[y][k].second+c});
                                break;
                            }
                        }
                    }
                }
            }
        }
        x=y=0;
        for(int i=1;i<=n;i++){
            if(!sters[i]){
                if(!x){
                    x=i;
                }else{
                    y=i;
                }
            }
        }
        while(!pq.empty()){
            pq.pop();
        }
        fo<<"Testul nr #"<<test<<'\n';
        if(maxlant[x]==maxlant[y]){
            fo<<x<<'\n'<<y<<'\n';
        }else if(maxlant[x]<maxlant[y]){
            fo<<y<<'\n';
        }else{
            fo<<x<<'\n';
        }
        for(int i=1;i<=n;i++){
            arb[i].clear();
            sters[i]=0;
            grad[i]=0;
            maxlant[i]=0;
        }
    }
    fi.close();
    fo.close();
}