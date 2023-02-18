
#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("pamant.in");
ofstream fo("pamant.out");

int n,m,x,y,top;
vector<int> G[NMAX+5];
int ind[NMAX+5],low[NMAX+5],viz[NMAX+5];
pair<int,int> st[NMAX+5];
vector<int> sol1;
int sol2[NMAX+5],l2;

void df(int nod,int parent, int nr){
    viz[nod]=1;
    low[nod]=ind[nod]=nr;
    int cnt=0;
    for(int i=0;i<G[nod].size();i++){
        if(G[nod][i]!=parent){
            if(ind[G[nod][i]]==-1){
                cnt++;
                st[++top]=make_pair(nod,G[nod][i]);
                df(G[nod][i],nod,nr+1);
                low[nod]=min(low[nod],low[G[nod][i]]);
                if(low[G[nod][i]]>=ind[nod]){
                    if(parent!=0||(parent==0&&cnt>=2)){
                        sol2[nod]=1;
                    }
                    do{
                        x=st[top].first;
                        y=st[top].second;
                        top--;
                    }while(x!=nod&&y!=G[nod][i]);
                }
            }else{
                low[nod]=min(low[nod],ind[G[nod][i]]);
            }
        }
    }
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        ind[i]=-1;
    }
    for(int i=1;i<=n;i++){
        if(!viz[i]){
            sol1.push_back(i);
            df(i,0,0);
        }
        if(sol2[i]){
            l2++;
        }
    }
    fo<<sol1.size()<<'\n';
    for(int i=0;i<sol1.size();i++){
        fo<<sol1[i]<<' ';
    }
    fo<<'\n';
    fo<<l2<<'\n';
    for(int i=1;i<=n;i++){
        if(sol2[i]==1){
            fo<<i<<' ';
        }
    }
    fo<<'\n';
    fi.close();
    fo.close();
}