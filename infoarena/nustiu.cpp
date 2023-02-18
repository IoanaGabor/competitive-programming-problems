#include <bits/stdc++.h>
#define NMAX 10000

using namespace std;

ifstream fi("nustiu.in");
ofstream fo("nustiu.out");

int t,n,x,y;
vector<int> arb[NMAX+5];
int nrnodsub[NMAX+5];
int sol[NMAX+5],ls;

void calc_sub(int nod,int parent){
    nrnodsub[nod]=1;
    for(int i=0;i<arb[nod].size();i++){
        if(arb[nod][i]!=parent){
            calc_sub(arb[nod][i],nod);
            nrnodsub[nod]+=nrnodsub[arb[nod][i]];
        }
    }
}

void calc_sol(int nod,int parent){
    bool ok=true;
    for(int i=0;i<arb[nod].size()&&ok;i++){
        if(arb[nod][i]!=parent){
            if(nrnodsub[arb[nod][i]]>(n/2)){
                ok=false;
            }
        }
    }    
    if(ok==true&&(n-nrnodsub[nod])<=(n/2)){
        sol[++ls]=nod;
    }
    for(int i=0;i<arb[nod].size();i++){
        if(arb[nod][i]!=parent){
            calc_sol(arb[nod][i],nod);
        }
    }    
}

void init(){
    ls=0;
    for(int i=1;i<=n;i++){
        arb[i].clear();
    }
}

int main(){
    fi>>t;
    while(t--){
        fi>>n;
        init();
        for(int i=1;i<n;i++){
            fi>>x>>y;
            arb[x].push_back(y);
            arb[y].push_back(x);
        }
        calc_sub(1,0);
        calc_sol(1,0);
        if(ls==0){
            fo<<"NIMIC"<<'\n';
        }else{
            sort(sol+1,sol+ls+1);
            for(int i=1;i<=ls;i++){
                fo<<sol[i]<<'\n';
            }
        }
    }
}