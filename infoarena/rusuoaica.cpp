
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define NMAX 100000
#define MMAX 400000

using namespace std;

ifstream f("rusuoaica.in");
ofstream g("rusuoaica.out");

struct ceva{
    int x,y,c;
} muchii[MMAX+5];

int n,m,a,rez,p[NMAX+5],card[NMAX+5],xx,yy;

bool crit(ceva aa,ceva bb){
    return (aa.c<bb.c);
}

int parinte(int x){
    if(p[x]!=x){
        p[x]=parinte(p[x]);
    }
    return p[x];
}

int main(){
    f>>n>>m>>a;
    for(int i=1;i<=m;i++){
        f>>muchii[i].x>>muchii[i].y>>muchii[i].c;
    }
    sort(muchii+1,muchii+m+1,crit);
    while(m&&muchii[m].c>a){
        rez-=muchii[m].c;
        m--;
    }
    for(int i=1;i<=n;i++){
        p[i]=i;
        card[i]=1;
    }
    for(int i=1;i<=m;i++){
        xx=muchii[i].x;
        yy=muchii[i].y;
        p[xx]=parinte(xx);
        p[yy]=parinte(yy);
        if(p[xx]!=p[yy]){
            rez+=muchii[i].c;
            if(card[p[xx]]<card[p[yy]]){
                card[p[yy]]+=card[p[xx]];
                p[p[xx]]=p[yy];
            }else{
                card[p[xx]]+=card[p[yy]];
                p[p[yy]]=p[xx];
            }
        }else{
            rez-=muchii[i].c;
        }
    }
    for(int i=1;i<=n;i++){
        if(p[i]==i){
            rez+=a;
        }
    }
    rez-=a;
    g<<rez;
}
