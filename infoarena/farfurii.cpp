
#include <bits/stdc++.h>
#define NMAX 100000
#define LOG2 17

using namespace std;

ifstream f("farfurii.in");
ofstream g("farfurii.out");

int n,sir[NMAX+5],arb[(1<<(LOG2+1))+5];
long long k;

void modifica(int nod,int val,int l,int r){
    if(l==r){
        arb[nod]=1;
        return;
    }
    int mij=(l+r)/2;
    if(val<=mij){
        modifica(2*nod,val,l,mij);
    }else{
        modifica(2*nod+1,val,mij+1,r);
    }
    arb[nod]=arb[2*nod]+arb[2*nod+1];
}

int afla(int nod,int cnt,int l,int r){
    if(l==r){
        return l;
    }
    int mij=(l+r)/2;
    if(mij-l+1-arb[2*nod]>cnt){
        return afla(2*nod,cnt,l,mij);
    }else{
        return afla(2*nod+1,cnt-(mij-l+1-arb[2*nod]),mij+1,r);
    }
}

int main(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        if(k<=1LL*(n-i)*(n-i-1)/2){
            sir[i]=afla(1,0,1,n);
        }else{
            sir[i]=afla(1,k-1LL*(n-i)*(n-i-1)/2,1,n);
            k=1LL*(n-i)*(n-i-1)/2;
        }
        modifica(1,sir[i],1,n);
    }
    for(int i=1;i<=n;i++){
        g<<sir[i]<<' ';
    }
    f.close();
    g.close();
}
