
#include <bits/stdc++.h>
#define NMAX 10000

using namespace std;

ifstream fi("cuplaj.in");
ofstream fo("cuplaj.out");

int n,m,e,x,y;
vector<int> v[NMAX+5];
int st[NMAX+5],dr[NMAX+5],viz[NMAX+5];
bool gata;
int sol;

void init(){
    for(int i=1;i<=n;i++){
        viz[i]=0;
    }
}

bool cuplaj(int nod){
    if(viz[nod]){
        return false;
    }
    viz[nod]=1;
    for(int i=0;i<v[nod].size();i++){
        if(dr[v[nod][i]]==0){
            dr[v[nod][i]]=nod;
            st[nod]=v[nod][i];
            return true;
        }
    }
    for(int i=0;i<v[nod].size();i++){
        if(dr[v[nod][i]]!=0&&cuplaj(dr[v[nod][i]])){
            dr[v[nod][i]]=nod;
            st[nod]=v[nod][i];
            return true;
        }
    }
    return false;
}

int main(){
    fi>>n>>m>>e;
    for(int i=1;i<=e;i++){
        fi>>x>>y;
        v[x].push_back(y);
    }
    gata=false;
    while(!gata){
        gata=true;
        init();
        for(int i=1;i<=n;i++){
            if(!st[i]&&cuplaj(i)){
                gata=false;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(st[i]){
            sol++;
        }
    }
    fo<<sol<<'\n';
    for(int i=1;i<=n;i++){
        if(st[i]!=0){
            fo<<i<<' '<<st[i]<<'\n';
        }
    }
    fi.close();
    fo.close();
}