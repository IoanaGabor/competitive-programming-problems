
#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 100000

using namespace std;

ifstream f("nn.in");
ofstream g("nn.out");

double sir1[NMAX+5],tg1,tg2;

struct baraj{
    int x1,x2,y1,y2;
} sir2[NMAX+5];
int n,m,aux1,aux2,x,y;

int cauta1(double val){
    int pas=1<<20,rez=0;
    while(pas){
        if(rez+pas<=n&&sir1[rez+pas]<val){
            rez+=pas;
        }
        pas>>=1;
    }
    return rez;
}

int cauta2(double val){
    int pas=1<<20,rez=0;
    while(pas){
        if(rez+pas<=n&&sir1[rez+pas]<=val){
            rez+=pas;
        }
        pas>>=1;
    }
    return rez;
}


double tangenta(int a,int b){
    return (double)b/a;
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>x>>y;
        sir1[i]=tangenta(x,y);
    }
    sort(sir1+1,sir1+n+1);
    for(int i=1;i<=m;i++){
        f>>sir2[i].x1>>sir2[i].y1>>sir2[i].x2>>sir2[i].y2;
        tg1=tangenta(sir2[i].x1,sir2[i].y1);
        tg2=tangenta(sir2[i].x2,sir2[i].y2);
        if(tg1>tg2){
            swap(tg1,tg2);
        }
        aux1=cauta1(tg1);
        aux2=cauta2(tg2);
        if(aux2-aux1<=1){
            g<<0<<'\n';
        }else{
            g<<aux2-aux1-1<<'\n';
        }
    }
    f.close();
    g.close();
}
