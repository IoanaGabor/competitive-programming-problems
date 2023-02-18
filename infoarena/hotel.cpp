
#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("hotel.in");
ofstream fo("hotel.out");

int n,q;
int p,x,y;
int arb[NMAX*4+5],lazy[NMAX*4+5];
int prefix[NMAX*4+5],sufix[NMAX*4+5],maxl[NMAX*4+5];

void update(int nod,int l,int r,int val){
    if(lazy[nod]){
        if(l!=r){
            lazy[nod*2]+=lazy[nod];
            lazy[nod*2+1]+=lazy[nod];
        }
        arb[nod]+=(r-l+1)*lazy[nod];
        prefix[nod]=sufix[nod]=maxl[nod]=((r-l+1)-arb[nod]);
        lazy[nod]=0;
    }
    if(r<x||y<l){
        return;
    }
    if(x<=l&&r<=y){
        arb[nod]+=(r-l+1)*val;
        prefix[nod]=sufix[nod]=maxl[nod]=((r-l+1)-arb[nod]);
        if(l!=r){
            lazy[nod*2]+=val;
            lazy[nod*2+1]+=val;
        }
        return;
    }
    int mij=(l+r)/2;
    update(nod*2,l,mij,val);
    update(nod*2+1,mij+1,r,val);
    arb[nod]=arb[nod*2]+arb[nod*2+1];
    prefix[nod]=prefix[nod*2];
    if(prefix[nod]==mij-l+1){
        prefix[nod]+=prefix[nod*2+1];
    }
    sufix[nod]=sufix[nod*2+1];
    if(sufix[nod]==r-mij){
        sufix[nod]+=sufix[nod*2];
    }
    maxl[nod]=max(max(maxl[nod*2],maxl[nod*2+1]),max(max(prefix[nod],sufix[nod]),prefix[2*nod+1]+sufix[2*nod]));
}

void create(int nod,int l,int r){
    prefix[nod]=sufix[nod]=maxl[nod]=(r-l+1);
    if(l!=r){
        int mij=(l+r)/2;
        create(nod*2,l,mij);
        create(nod*2+1,mij+1,r);
    }
}

int main(){
    fi>>n>>q;
    create(1,1,n);
    while(q--){
        fi>>p;
        if(p==1){
            fi>>x>>y;
            y=x+y-1;
            update(1,1,n,1);
        }
        if(p==2){
            fi>>x>>y;
            y=x+y-1;
            update(1,1,n,-1);
        }
        if(p==3){
            fo<<maxl[1]<<'\n';
        }
    }
    fi.close();
    fo.close();
}