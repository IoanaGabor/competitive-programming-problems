
#include <bits/stdc++.h>
#define NMAX 50000
#define MMAX 100000

using namespace std;

ifstream fi("fotbal2.in");
ofstream fo("fotbal2.out");

int n,m,mm,x,y;
vector<int> G[NMAX+5];
pair<int,int> edges[MMAX+5];
int used[MMAX+5];
int st[MMAX+5],top;
int rez[MMAX+5];
int fr[NMAX+5];
int viz[NMAX+5];

void euler(int start){
    st[++top]=start;
    int node,edge,next_node;
    while(top){
        node=st[top];
        viz[node]=1;
        if(G[node].size()){
            edge=G[node].back();
            G[node].pop_back();
            if(!used[edge]){
                used[edge]=1;
                rez[edge]=node;
                next_node=edges[edge].first^edges[edge].second^node;
                st[++top]=next_node;
            }
        }else{
            top--;
        }
    }
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>x>>y;
        edges[i]=make_pair(x,y);
        G[x].push_back(i);
        G[y].push_back(i);
    }
    mm=m;
    for(int x=1;x<=n;x++){
        if(G[x].size()%2==1){
            edges[++m]=make_pair(0,x);
            G[0].push_back(m);
            G[x].push_back(m);
        }
    }
    for(int i=1;i<=n;i++){
        if(!viz[i]){
            euler(i);
        }    
    }
    if(m!=mm){
        fo<<2<<'\n';
    }else{
        fo<<0<<'\n';
    }
    for(int i=1;i<=mm;i++){
        fo<<rez[i]<<'\n';
    }
    fi.close();
    fo.close();
}