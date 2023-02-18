#include <bits/stdc++.h>
#define NMAX 100000
#define LOGN 18

using namespace std;

ifstream fi("pikachu.in");
ofstream fo("pikachu.out");

int n,k;
int sir[NMAX+5];
int ind[NMAX+5],p[NMAX+5];
long long sol,cost;

int frecv[(1<<LOGN)+5];
long long sum[(1<<LOGN)+5];

bool crit(int a,int b){
    return sir[a]<sir[b];
}

void add(int poz,int val, int nod,int st,int dr){
    if(st==dr){
        if(val>0){
            frecv[nod]++;
        }else{
            frecv[nod]--;
        }
        sum[nod]+=val;
    }else{
        int mij=(st+dr)/2;
        if(poz<=mij){
            add(poz,val,nod*2,st,mij);
        }else{
            add(poz,val,nod*2+1,mij+1,dr);
        }
        frecv[nod]=frecv[nod*2]+frecv[nod*2+1];
        sum[nod]=sum[nod*2]+sum[nod*2+1];
    }
}

int find_el(int poz,int nod,int st,int dr){
    if(st==dr){
        return ind[st];
    }
    int mij=(st+dr)/2;
    if(frecv[2*nod]>=poz){
        return find_el(poz,2*nod,st,mij);
    }else{
        return find_el(poz-frecv[2*nod],2*nod+1,mij+1,dr);
    }
}

long long get_sum(int le, int ri,int nod,int st,int dr){
    if(le<=st&&dr<=ri){
        return sum[nod];
    }else{
        long long sst,ddr;
        sst=ddr=0;
        int mij=(st+dr)/2;
        if(le<=mij){
            sst=get_sum(le,ri,2*nod,st,mij);
        }
        if(mij<ri){
            ddr=get_sum(le,ri,2*nod+1,mij+1,dr);
        }
        return sst+ddr;
    }
}

int main(){
    fi>>n>>k;
    for(int i=1;i<=n;i++){
        fi>>sir[i];
        ind[i]=i;
    }
    sort(ind+1,ind+n+1,crit);
    for(int i=1;i<=n;i++){
        p[ind[i]]=i;
    }
    for(int i=1;i<=k;i++){
        add(p[i],sir[i],1,1,n);       
    }
    int mij=find_el(k/2+1,1,1,n);
    long long sumst,sumdr;
    sumst=get_sum(1,p[mij],1,1,n);
    sumdr=get_sum(p[mij]+1,n,1,1,n);
    cost=1LL*(k/2+1)*sir[mij]-sumst+sumdr-1LL*(k-k/2-1)*sir[mij];
    sol=cost;
    for(int i=k+1;i<=n;i++){
        add(p[i-k],-sir[i-k],1,1,n);
        add(p[i],sir[i],1,1,n);
        mij=find_el(k/2+1,1,1,n);
        sumst=get_sum(1,p[mij],1,1,n);
        sumdr=get_sum(p[mij]+1,n,1,1,n);
        cost=1LL*(k/2+1)*sir[mij]-sumst+sumdr-1LL*(k-k/2-1)*sir[mij];
        sol=min(sol,cost);
    }
    fo<<sol;
    fi.close();
    fo.close();
}