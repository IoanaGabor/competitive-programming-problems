
#include <bits/stdc++.h>
#define NMAX 15000
#define MMAX 30000

using namespace std;

ifstream fi("radiatie.in");
ofstream fo("radiatie.out");

struct edge{
    int x,y,c;
    bool operator< (const edge &other) const{
        return c<other.c;
    }
} mch[MMAX+5];

struct query{
    int x,y,sol,ind;
} q[NMAX+5],aux1[NMAX+5],aux2[NMAX+5];

int n,m,k,la1,la2;
int parent[NMAX+5],sz[NMAX+5];

void init_dsu(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
}

int get_parent(int val){
    if(parent[val]!=val){
        parent[val]=get_parent(parent[val]);
    }
    return parent[val];
}

void join(int i){
    int p1=get_parent(mch[i].x);
    int p2=get_parent(mch[i].y);
    if(sz[p1]<sz[p2]){
        parent[p1]=p2;
        sz[p2]+=sz[p1];
    }else{
        parent[p2]=p1;
        sz[p1]+=sz[p2];
    }
}

bool connected(int a,int b){
    int p1=get_parent(a);
    int p2=get_parent(b);
    if(p1==p2){
        return true;
    }
    return false;
}

bool cmp1(query a,query b){
    return a.sol<b.sol;
}

bool cmp2(query a,query b){
    return a.ind<b.ind;
}

void cauta(){
    int pas=1<<29,poz;
    while(pas){
        poz=1;
        la1=la2=0;
        init_dsu();
        for(int i=1;i<=k;i++){
            while(poz<=m&&mch[poz].c<=q[i].sol+pas){
                join(poz);
                poz++;
            }
            if(!connected(q[i].x,q[i].y)){
                q[i].sol+=pas;            
                aux1[++la1]=q[i];
            }else{
                aux2[++la2]=q[i];
            }
        }
        merge(aux1+1,aux1+la1+1,aux2+1,aux2+la2+1,q+1,cmp1);
        pas>>=1;
    }
    sort(q+1,q+k+1,cmp2);
    for(int i=1;i<=k;i++){
        fo<<q[i].sol+1<<'\n';
    }
}

int main(){
    fi>>n>>m>>k;
    for(int i=1;i<=m;i++){
        fi>>mch[i].x>>mch[i].y>>mch[i].c;
    }
    sort(mch+1,mch+m+1);
    for(int i=1;i<=k;i++){
        fi>>q[i].x>>q[i].y;
        q[i].ind=i;
        q[i].sol=0;
    }
    cauta();
    fi.close();
    fo.close();
}