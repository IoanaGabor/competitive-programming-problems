
#include <bits/stdc++.h>
#define NMAX 100000
#define MMAX 500000

using namespace std;

ifstream fi("ciclueuler.in");
ofstream fo("ciclueuler.out");

int n,m,x,y;
vector <int> G[NMAX+5];
pair<int,int> edges[MMAX+5];
bool used[MMAX+5];
int st[MMAX+5],top;
int ans[MMAX+5],lans;

void read(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>x>>y;
        G[x].push_back(i);
        G[y].push_back(i);
        edges[i]=make_pair(x,y);
    }
}

bool check(){
    for(int i=1;i<=n;i++){
        if(G[i].size()%2==1){
            return false;
        }
    }
    return true;
}

void euler(){
    st[++top]=1;
    int node,edge,next_node;
    while(top){
        node=st[top];
        if(G[node].size()){
            edge=G[node].back();
            G[node].pop_back();
            if(!used[edge]){
                used[edge]=true;
                next_node=node^edges[edge].first^edges[edge].second;
                st[++top]=next_node;
            }
        }else{
            ans[++lans]=node;
            top--;
        }
    }
    for(int i=1;i<lans;i++){
        fo<<ans[i]<<' ';
    }
}

int main(){
    read();
    if(!check()){
        fo<<-1<<'\n';
    }else{
        euler();
    }
    fi.close();
    fo.close();
}
