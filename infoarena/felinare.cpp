
#include<bits/stdc++.h>
#define NMAX 8191

using namespace std;

ifstream fi("felinare.in");
ofstream fo("felinare.out");

int n,m,x,y;
vector<int> v[NMAX+5];
int st[NMAX+5],dr[NMAX+5],viz[NMAX+5];
int supst[NMAX+5],supdr[NMAX+5];
bool gata;
int cnt;

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

void suport(int nod){
    for(int i=0;i<v[nod].size();i++){
        if(!supdr[v[nod][i]]){
            supdr[v[nod][i]]=1;
            supst[dr[v[nod][i]]]=0;
            suport(dr[v[nod][i]]);
        }
    }
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
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
            supst[i]=1;
            cnt++;
        }

    }
    for(int i=1;i<=n;i++){
        if(!supst[i]){
            suport(i);
        }
    }
    fo<<2*n-cnt<<'\n';
    for(int i=1;i<=n;i++){
        fo<<(1-supst[i])+2*(1-supdr[i])<<'\n';
    }
}