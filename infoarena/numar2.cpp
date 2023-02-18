
#include <bits/stdc++.h>
#define NMAX 100

using namespace std;

ifstream f("numar2.in");
ofstream g("numar2.out");

int n,m,a[NMAX+5];
long long xmax;
vector <pair<long long,int> > prod;

void bkt(int ind,long long nr,int semn){
    if(ind==n+1){
        return;
    }
    if(1LL*nr*a[ind]<=xmax){
        prod.push_back(make_pair(1LL*nr*a[ind],semn*(-1)));
        bkt(ind+1,1LL*nr*a[ind],semn*(-1));
    }else{
        return;
    }
    bkt(ind+1,nr,semn);
}

int calculeaza(long long nr){
    int ret=0;
    for(int i=0;i<prod.size();i++){
        ret += (nr/prod[i].first)*prod[i].second;
    }
    return ret;
}

long long cauta(){
    long long pas=1LL<<40,ret=0;
    while(pas){
        if(ret+pas<=xmax&&calculeaza(ret+pas)<m){
            ret+=pas;
        }
        pas>>=1;
    }
    ret++;
    return ret;
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>a[i];
    }
    xmax=1LL*m*a[1];
    bkt(1,1,-1);
    g<<cauta();
    f.close();
    g.close();
}
