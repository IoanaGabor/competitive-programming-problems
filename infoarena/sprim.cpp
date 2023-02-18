
#include <bits/stdc++.h>
#define NMAX 100000
#define VMAX 1000000

using namespace std;

ifstream fi("sprim.in");
ofstream fo("sprim.out");

int n,sir[NMAX+5];
int ciur[VMAX+5];
int last[VMAX+5];
int capat;

void read(){
    fi>>n;
    for(int i=1;i<=n;i++){
        fi>>sir[i];
    }
}

void constr_ciur(){
    for(int i=2;i<=VMAX;i++){
        if(ciur[i]==0){
            ciur[i]=1;
            if(i<=VMAX/i){
                for(int j=i*i;j<=VMAX;j+=i){
                    if(ciur[j]==0){
                        ciur[j]=i;
                    }
                }
            }
        }
    }
    ciur[1]=1;
}

void desc(int nr,int ind){
    int d;
    while(ciur[nr]!=1){
        capat=max(capat,last[ciur[nr]]+1);
        last[ciur[nr]]=ind;
        d=ciur[nr];
        while(nr%d==0){
            nr/=d;
        }
    }
    if(nr!=1){
        capat=max(capat,last[nr]+1);
        last[nr]=ind;
    }
}

void solve(){
    constr_ciur();
    desc(sir[1],1);
    capat=1;
    int sol=0;
    for(int i=2;i<=n;i++){
        desc(sir[i],i);
        sol+=i-capat;
    }
    fo<<sol<<'\n';
}

int main(){
    read();
    solve();
    fi.close();
    fo.close();
}