
#include <bits/stdc++.h>
#define NMAX 255
#define MMAX 1500

using namespace std;

ifstream fi("plan.in");
ofstream fo("plan.out");

int n,m,lo;
int x,y,lc;
vector <int> G[NMAX+5],GT[NMAX+5];
int viz[NMAX+5],ord[NMAX+5];
int grad1[NMAX+5],grad2[NMAX+5];
int unnod[NMAX+5];
int st[NMAX+5],dr[NMAX+5],ls,ld;
int c[NMAX+5];

void dfs(int nod){
    viz[nod]=1;
    for(int i=0;i<G[nod].size();i++){
        if(!viz[G[nod][i]]){
            dfs(G[nod][i]);
        }
    }
    ord[++lo]=nod;
}

void dfst(int nod){
    c[nod]=lc;
    viz[nod]=1;
    for(int i=0;i<GT[nod].size();i++){
        if(!viz[GT[nod][i]]){
            dfst(GT[nod][i]);
        }
    }
}

void read(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>x>>y;
        if(x!=y){
            G[x].push_back(y);
            GT[y].push_back(x);
        }
    }
}

void components(){
    for(int i=1;i<=n;i++){
        if(!viz[i]){
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        viz[i]=0;
    }
    for(int i=n;i>=1;i--){
        if(!viz[ord[i]]){
            lc++;
            unnod[lc]=ord[i];
            dfst(ord[i]);
        }
    }
}

void solve(){
    components();
    if(lc==1){
        fo<<0<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<G[i].size();j++){
            if(c[i]!=c[G[i][j]]){
                grad1[c[i]]++;
                grad2[c[G[i][j]]]++;
            }
        }
    }
    for(int i=1;i<=lc;i++){
        if(grad1[i]==0){
            dr[++ld]=i;
        }
        if(grad2[i]==0){
            st[++ls]=i;
        }
    }
    fo<<max(ls,ld)<<'\n';
    for(int i=1;i<=max(ls,ld);i++){
        if(i>ld){
            fo<<unnod[dr[1]]<<' ';
        }else{
            fo<<unnod[dr[i]]<<' ';
        }
        if(i>=ls){
            fo<<unnod[st[1]]<<'\n';
        }else{
            fo<<unnod[st[i+1]]<<'\n';
        }
    }
}

int main(){
    read();
    solve();
    fi.close();
    fo.close();
}
