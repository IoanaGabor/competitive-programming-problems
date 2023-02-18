
#include <bits/stdc++.h>
#define NMAX 32000
#define MMAX 500000

using namespace std;

ifstream fi("concurs.in");
ofstream fo("concurs.out");

int n,m,x,y;
int pcte[NMAX+5];
vector<int> arb[NMAX+5];
pair<int,int> part[MMAX+5];
int eul[2*NMAX+5],le;
int L[NMAX+5];
int ap[NMAX+5];
int doi[2*NMAX+5];
int rmq[20][2*NMAX+5];
int st;
int rez;
int gr[NMAX+5];

void dfs(int nod,int parent){
    eul[++le]=nod;
    L[nod]=L[parent]+1;
    for(int i=0;i<arb[nod].size();i++){
        if(arb[nod][i]!=parent){
            dfs(arb[nod][i],nod);
            eul[++le]=nod;
        }
    }
}

void constr_rmq(){
    doi[1]=0;
    for(int i=2;i<=le;i++){
        doi[i]=doi[i>>1]+1;
    }
    for(int p=1;p<=doi[le];p++){
        for(int i=1;i+(1<<p)-1<=le;i++){
            if(L[rmq[p-1][i]]<L[rmq[p-1][i+(1<<(p-1))]]){
                rmq[p][i]=rmq[p-1][i];
            }else{
                rmq[p][i]=rmq[p-1][i+(1<<(p-1))];
            }
        }
    }
}

int lca(int a,int b){
    if(ap[a]>ap[b]){
        swap(a,b);
    }
    int p=doi[ap[b]-ap[a]+1];
    if(L[rmq[p][ap[a]]]<L[rmq[p][ap[b]-(1<<p)+1]]){
        return rmq[p][ap[a]];
    }else{
        return rmq[p][ap[b]-(1<<p)+1];
    }
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=n;i++){
        fi>>pcte[i];
    }
    for(int i=1;i<n;i++){
        fi>>x>>y;
        arb[x].push_back(y);
        gr[y]++;
    }
    for(int i=1;i<=m;i++){
        fi>>part[i].first>>part[i].second;
    }
    sort(part+1,part+m+1);
    for(int i=1;i<=n;i++){
        if(gr[i]==0){
            dfs(i,0);
            break;
        }
    }
    for(int i=1;i<=le;i++){
        if(!ap[eul[i]]){
            ap[eul[i]]=i;
        }
        rmq[0][i]=eul[i];
    }
    constr_rmq();
    for(int i=1;i<=m;i++){
        st=lca(part[i].first,part[i].second);
        if(pcte[st]>rez){
            rez=pcte[st];
            x=part[i].first;
            y=part[i].second;
        }
    }
    fo<<rez<<' '<<x<<' '<<y<<'\n';
}