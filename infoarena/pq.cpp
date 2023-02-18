
#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("pq.in");
ofstream fo("pq.out");

int n;
int sir[NMAX+5];
int urm[NMAX+5];
int ant[NMAX+5];
int aint[4*NMAX+5];
int per[NMAX+5];
int ap[NMAX+5];
int nrq;
struct query{
    int x,y,ind,sol;
} q[NMAX+5];
int sol;

bool crit(query a,query b){
    if(a.x==b.x){
        return a.y<b.y;
    }
    return a.x<b.x;
}

bool crit2(query a,query b){
    return a.ind<b.ind;
}

void create(int nod,int st,int dr){
    if(st==dr){
        aint[nod]=per[st];
        return;
    }
    int mij=(st+dr)/2;
    create(2*nod,st,mij);
    create(2*nod+1,mij+1,dr);
    aint[nod]=max(aint[2*nod],aint[2*nod+1]);
}

void update(int nod,int st,int dr,int poz,int val){
    if(st==dr){
        per[poz]=val;
        aint[nod]=val;
        return;
    }
    int mij=(st+dr)/2;
    if(poz<=mij){
        update(2*nod,st,mij,poz,val);
    }else{
        update(2*nod+1,mij+1,dr,poz,val);
    }
    aint[nod]=max(aint[2*nod],aint[2*nod+1]);
}

void maxim(int nod,int st,int dr,int poz){
    if(dr<=poz){
        sol=max(sol,aint[nod]);
        return;
    }
    int mij=(st+dr)/2;
    if(poz<=mij){
        maxim(2*nod,st,mij,poz);
    }else{
        maxim(2*nod,st,mij,poz);
        maxim(2*nod+1,mij+1,dr,poz);
    }
}

void init(){
    fi>>n>>nrq;
    for(int i=1;i<=n;i++){
        fi>>sir[i];
        if(ap[sir[i]]==0){
            ant[i]=-1;
        }else{
            ant[i]=ap[sir[i]];
        }
        ap[sir[i]]=i;
    }
    for(int i=0;i<=NMAX;i++){
        ap[i]=0;
    }
    for(int i=n;i>=1;i--){
        if(ap[sir[i]]==0){
            urm[i]=-1;
        }else{
            urm[i]=ap[sir[i]];
            ap[sir[i]]=i;
        }
        ap[sir[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(ant[i]==-1){
            per[i]=-1;
        }else{
            per[i]=i-ant[i];
        }
    }
    create(1,1,n);
    for(int i=1;i<=nrq;i++){
        fi>>q[i].x>>q[i].y;
        q[i].ind=i;
    }
    sort(q+1,q+nrq+1,crit);
}

void solve(){
    int st=1;
    for(int i=1;i<=nrq;i++){
        while(st<q[i].x){
            if(urm[st]!=-1){
                update(1,1,n,urm[st],-1);
            }
            update(1,1,n,st,-1);
            st++;
        }
        sol=-1;
        maxim(1,1,n,q[i].y);
        q[i].sol=sol;
    }
    sort(q+1,q+nrq+1,crit2);
    for(int i=1;i<=nrq;i++){
        fo<<q[i].sol<<'\n';
    }
}

int main(){   
    init();
    solve();
    fi.close();
    fo.close();
}