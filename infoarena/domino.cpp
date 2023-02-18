
#include <bits/stdc++.h>
#define MMAX 50000
#define NMAX 9

using namespace std;

ifstream fi("domino.in");
ofstream fo("domino.out");

int m;
pair<int,int> edges[MMAX+5];
int used[MMAX+5];
vector<pair<int,int> > G[NMAX+2];
pair<int,int> st[MMAX+5];
pair<int,int> ans[MMAX+5];
int top,la;
int exista[NMAX+5],viz[NMAX+5];

bool verif(){
    int i1=-1,i2=-1;
    for(int i=0;i<=9;i++){
        if(G[i].size()%2==1){
            if(i1==-1){
                i1=i;
            }else if(i2==-1){
                i2=i;
            }else{
                return false;
            }
        }
    }
    if(i1!=-1){
        if(i2!=-1){
            G[i1].push_back({m+1,-1});
            G[10].push_back({m+1,1});
            G[i2].push_back({m+2,-1});
            G[10].push_back({m+2,1});
            edges[m+1]=make_pair(i1,10);
            edges[m+2]=make_pair(i2,10);
        }else{
            return false;
        }
    }
    return true;
}

void dfs(int nod){
    viz[nod]=1;
    int nnod,ed;
    for(int i=0;i<G[nod].size();i++){
        ed=G[nod][i].first;
        nnod=nod^edges[ed].first^edges[ed].second;
        if(!viz[nnod]){
            dfs(nnod);
        }
    }
}

bool conex(){
    dfs(edges[1].first);
    for(int i=0;i<10;i++){
        if(exista[i]&&(!viz[i])){
            return false;
        }
    }
    return true;
}

void euler(int snod){
    st[++top]={snod,0};
    int nod,nnod;
    pair<int,int> ed;
    while(top){
        nod=st[top].first;
        if(G[nod].size()!=0){
            ed=G[nod].back();
            G[nod].pop_back();
            if(!used[ed.first]){
                nnod=nod^edges[ed.first].first^edges[ed.first].second;
                used[ed.first]=1;
                st[++top]={nnod,ed.first*ed.second};
            }
        }else{
            ans[++la]=st[top];
            top--;
        }
    }
    fo<<1<<'\n';
    if(ans[1].first==10){
        for(int i=la-2;i>=2;i--){
            if(ans[i].second<0){
                fo<<-ans[i].second<<' '<<0<<'\n';
            }else{
                fo<<ans[i].second<<' '<<1<<'\n';
            }
        }
    }else{
        for(int i=la-1;i>=1;i--){
            if(ans[i].second<0){
                fo<<-ans[i].second<<' '<<0<<'\n';
            }else{
                fo<<ans[i].second<<' '<<1<<'\n';
            }
        }
    }
}

int main(){
    fi>>m;
    for(int i=1;i<=m;i++){
        fi>>edges[i].first>>edges[i].second;
        exista[edges[i].first]=exista[edges[i].second]=1;
        G[edges[i].first].push_back({i,-1});
        G[edges[i].second].push_back({i,1});
    }
    if((!verif())||(!conex())){
        fo<<0<<'\n';
        fi.close();
        fo.close();
        return 0;
    }
    if(G[10].size()){
        euler(10);
    }else{
        euler(edges[1].first);
    }
    fi.close();
    fo.close();
}