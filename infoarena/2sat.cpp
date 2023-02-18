#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("2sat.in");
ofstream fo("2sat.out");

int n,m,x,y;
vector<int> G[2*NMAX+5],GT[2*NMAX+5];
int viz[2*NMAX+5];
int ord[2*NMAX+5],k;
vector<int> ctc[2*NMAX+5];
int comp[2*NMAX+5],nrc;

int codif(int val){
    if(val<0){
        return 2*(-val);
    }
    return 2*val+1;
}

int inv(int val){
    return codif(-val);
}

void dfst(int nod){
    viz[nod]=1;
    for(int i=0;i<GT[nod].size();i++){
        if(!viz[GT[nod][i]]){
            dfst(GT[nod][i]);
        }
    }
    ord[++k]=nod;
}

void dfs(int nod){
    viz[nod]=1;
    for(int i=0;i<G[nod].size();i++){
        if(!viz[G[nod][i]]){
            dfs(G[nod][i]);
        }
    }
    ctc[nrc].push_back(nod);
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>x>>y;
        G[inv(x)].push_back(codif(y));
        G[inv(y)].push_back(codif(x));
        GT[codif(y)].push_back(inv(x));
        GT[codif(x)].push_back(inv(y));
    }
    for(int i=2;i<=2*n+1;i++){
        if(!viz[i]){
            dfst(i);
        }
    }
    for(int i=2;i<=2*n+1;i++){
        viz[i]=0;
    }
    for(int i=2*n+1;i>=1;i--){
        if(!viz[ord[i]]){
            ++nrc;
            dfs(ord[i]);
        }
    }
    for(int i=1;i<=nrc;i++){
        for(int j=0;j<ctc[i].size();j++){
            comp[ctc[i][j]]=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(comp[2*i]==comp[2*i+1]){
            fo<<-1;
            fi.close();
            fo.close();
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(comp[2*i]<comp[2*i+1]){
            fo<<0<<' ';
        }else{
            fo<<1<<' ';
        }
    }    
}