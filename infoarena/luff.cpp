
#include <bits/stdc++.h>
#define NMAX 200000
#define QMAX 100000
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream fi("luff.in");
ofstream fo("luff.out");

struct query{
    int nod;
    int k;
    int ind;
    int rez;
} q[QMAX+5],aux1[QMAX+5],aux2[QMAX+5];

struct muchie{
    int x,y,c;
} edges[NMAX+5];

int n,m,nrq,la1,la2;
int et[NMAX+5],sz[NMAX+5];

bool crit(muchie a,muchie b){
    return a.c>b.c;
}

bool crit2(query a,query b){
    return a.rez>b.rez;
}

bool crit3(query a,query b){
    return a.ind<b.ind;
}

void reset_dsu(){
    for(int i=1;i<=n;i++){
        et[i]=i;
        sz[i]=1;
    }
}

int get_parent(int val){
    if(val!=et[val]){
        et[val]=get_parent(et[val]);
    }
    return et[val];
}

void join(int a,int b){
    int aa=get_parent(a);
    int bb=get_parent(b);
    if(aa!=bb){
        if(sz[aa]<sz[bb]){
            et[aa]=bb;
            sz[bb]+=sz[aa];
        }else{
            et[bb]=aa;
            sz[aa]+=sz[bb];
        }
    }
}

void citire(){
    fi>>n>>m>>nrq;
    for(int i=1;i<=m;i++){
        fi>>edges[i].x>>edges[i].y>>edges[i].c;
    }
    sort(edges+1,edges+m+1,crit);
    for(int i=1;i<=nrq;i++){
        fi>>q[i].nod>>q[i].k;
        q[i].ind=i,q[i].rez=-1;
    }
}

void cauta(){            /// cautare binara in paralel
    int pas=(1<<29),poz,par;
    while(pas){
        reset_dsu();
        poz=1;
        la1=la2=0;
        for(int i=1;i<=nrq;i++){
            while(poz<=m&&edges[poz].c>=q[i].rez+pas){           /// sirul q e sortat descrescator dupa .rez
                join(edges[poz].x,edges[poz].y);
                poz++;
            }
            par=get_parent(q[i].nod);
            if(sz[par]>=q[i].k){                         /// daca bitul se afla in solutia i, il adaugam
                q[i].rez+=pas;
                aux1[++la1]=q[i];
            }else{
                aux2[++la2]=q[i];
            }
        }
        merge(aux1+1,aux1+la1+1,aux2+1,aux2+la2+1,q+1,crit2);
        pas>>=1;
    }
}

void afiseaza(){
    sort(q+1,q+nrq+1,crit3);
    for(int i=1;i<=nrq;i++){
        fo<<q[i].rez<<'\n';
    }
}

int main(){
    citire();
    cauta();
    afiseaza();
    fi.close();
    fo.close();
}