
#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 1000
#define a first
#define b second

using namespace std;

ifstream f("checkin.in");
ofstream g("checkin.out");

int n,k,p,aux[NMAX+5],minim=1<<30;
pair <int,int> gh[NMAX+5];

bool crit(pair<int,int> aa,pair<int,int> bb){
    return (1000-aa.b)*bb.a>(1000-bb.b)*aa.a;
}

bool ok(int val){
    long long cnt=0;
    for(int i=1;i<=n;i++){
        if(val-gh[i].b>0){
            aux[i]=(val-gh[i].b)/gh[i].a;
        }else{
            aux[i]=0;
        }
    }
    if(n>k){
        sort(aux+1,aux+n+1);
    }
    for(int i=n;i>=1&&n-i+1<=k;i--){
        cnt+=aux[i];
    }
    if(cnt>=p){
        return false;
    }else{
        return true;
    }
}

int cauta(){
    int r=0;
    int pas=1<<30;
    while(pas){
        if(ok(r+pas)){
            r+=pas;
        }
        pas>>=1;
    }
    r++;
    return r;
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>gh[i].a>>gh[i].b;
        minim=min(minim,gh[i].b);
    }
    f>>k>>p;
    if(p==0){
        g<<minim;
    }else{
        g<<cauta();
    }
    f.close();
    g.close();
}
