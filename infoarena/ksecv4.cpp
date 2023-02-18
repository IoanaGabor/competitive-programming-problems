
#include <bits/stdc++.h>
#define MMAX 2048
#define NMAX 1000000

using namespace std;

ifstream fi("ksecv4.in");
ofstream fo("ksecv4.out");

struct ceva{
    long long mini,maxi;
} ARB[4*NMAX+5];

int n,k,m,pos;
long long a[MMAX+5],b[MMAX+5],sir[NMAX+5];
long long minii,maxii,nmini,nmaxi,val;

void constr(int nod,int l,int r){
    if(l==r){
        ARB[nod].maxi=ARB[nod].mini=sir[l];
        return;
    }
    int mij=(l+r)/2;
    constr(nod*2,l,mij);
    constr(nod*2+1,mij+1,r);
    ARB[nod].maxi=max(ARB[nod*2].maxi,ARB[nod*2+1].maxi);
    ARB[nod].mini=min(ARB[nod*2].mini,ARB[nod*2+1].mini);
}

int search_in_aint(int nod,int l,int r,int st,long long smechmax){
    if(r<st){
        return n+1;
    }
    if(st<=l){
        nmini=min(minii,ARB[nod].mini);
        nmaxi=max(maxii,ARB[nod].maxi);                
        if((nmaxi-nmini+1)/2<=smechmax){
            minii=nmini;
            maxii=nmaxi;
            return n+1;
        }           
    }
    if(l==r){
        return l;
    }
    int mij=(l+r)/2,aux;
    aux=search_in_aint(nod*2,l,mij,st,smechmax);
    if(aux!=n+1){
        return aux;
    }
    return search_in_aint(nod*2+1,mij+1,r,st,smechmax);
}

bool ok(long long smechmax){
    int nrs=0;
    int st=1;
    while(st<=n){
        minii=maxii=sir[st];
        st=search_in_aint(1,1,n,st,smechmax);
        nrs++;
        if(nrs>k){
           return true;
        }
    }
    return false;
}

long long search(){
    long long pas=1LL<<60,ret=0;
    while(pas){
        if(ok(ret+pas)){
            ret+=pas;
        }
        pas>>=1;
    }
    ret++;
    return ret;
}

int main(){
    fi>>n>>k>>m;
    for(int i=0;i<m;i++){
        fi>>a[i];
    }
    for(int i=0;i<m;i++){
        fi>>b[i];
    }
    for(int i=0;i<n;i++){
        sir[i+1]=a[i%m]^b[i/m];
    }
    constr(1,1,n);
    fo<<search();
    fi.close();
    fo.close();
}