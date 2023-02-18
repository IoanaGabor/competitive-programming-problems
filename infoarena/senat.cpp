
#include <bits/stdc++.h>
#define NMAX 100
#define LMAX 10000
 
using namespace std;
 
ifstream fi("senat.in");
ofstream fo("senat.out");
 
int n,m;
char linie[LMAX+5];
vector<int> G[NMAX+5];
int viz[NMAX+5];
int cst[NMAX+5],cdr[NMAX+5];
 
void prelucrare_linie(int ind){
    int nr;
    int l=strlen(linie);
    for(int i=0;i<l;i++){
        nr=0;
        while(i<l&&isdigit(linie[i])){
            nr=nr*10+linie[i]-'0';
            i++;
        }
        if(nr){
            G[nr].push_back(ind);
        }
    }
}
 
void read(){
    fi>>n>>m;
    fi.get();
    for(int i=1;i<=m;i++){
        fi.getline(linie,LMAX);
        prelucrare_linie(i);
    }
}
 
void init(){
    for(int i=1;i<=n;i++){
        viz[i]=0;
    }
}
 
bool cuplaj(int nod){
    if(viz[nod]){
        return 0;
    }
    viz[nod]=1;
    for(int i=0;i<G[nod].size();i++){
        if(!cdr[G[nod][i]]){
            cdr[G[nod][i]]=nod;
            cst[nod]=G[nod][i];
            return true;
        }
    }
    for(int i=0;i<G[nod].size();i++){
        if(cdr[G[nod][i]]&&cuplaj(cdr[G[nod][i]])){
            cdr[G[nod][i]]=nod;
            cst[nod]=G[nod][i];
            return true;
        }
    }
    return false;
}
 
void solve(){
    int ok=1;
    while(ok){
        init();
        ok=0;
        for(int i=1;i<=n;i++){
            if(!cst[i]&&cuplaj(i)){
                ok=1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(!cdr[i]){
            fo<<0<<'\n';
            return;
        }
    }
    for(int i=1;i<=m;i++){
        fo<<cdr[i]<<'\n';
    }
}
 
int main()
{
    read();
    solve();
    fi.close();
    fo.close();
    return 0;
}