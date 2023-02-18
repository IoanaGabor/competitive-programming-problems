
#include <iostream>
#include <fstream>
#define NMAX 100
#define KMAX 1000
#define MOD 997
#define ii first
#define jj second

using namespace std;

ifstream f("poarta.in");
ofstream g("poarta.out");

int n,m,k,l1,c1,l2,c2,nrdrum[NMAX+5][NMAX+5],timp,nr,d1,d2,nrd1[KMAX+5],lnrd1,nrd2[KMAX+5],lnrd2;
pair <int,int> port[KMAX+5];

int drumminim(int x1,int y1,int x2,int y2){
    if(x1>x2){
        swap(x1,x2);
    }
    if(y1>y2){
        swap(y1,y2);
    }
    return (x2-x1)+(y2-y1);
}

int nrdrummin(int x1,int y1,int x2,int y2){
    if(x1>x2){
        swap(x1,x2);
    }
    if(y1>y2){
        swap(y1,y2);
    }
    return nrdrum[x2-x1+1][y2-y1+1];
}

int main(){
    f>>n>>m>>k;
    f>>l1>>c1>>l2>>c2;
    for(int i=1;i<=k;i++){
        f>>port[i].ii>>port[i].jj;
    }
    for(int i=1;i<=n;i++){
        nrdrum[i][1]=1;
    }
    for(int j=1;j<=m;j++){
        nrdrum[1][j]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            nrdrum[i][j]=(nrdrum[i][j-1]+nrdrum[i-1][j])%MOD;
        }
    }
    timp=drumminim(l1,c1,l2,c2);
    nr=nrdrummin(l1,c1,l2,c2);
    d1=n+m;
    for(int i=1;i<=k;i++){
        if(d1>drumminim(l1,c1,port[i].ii,port[i].jj)){
            d1=drumminim(l1,c1,port[i].ii,port[i].jj);
            lnrd1=0;
            nrd1[++lnrd1]=nrdrummin(l1,c1,port[i].ii,port[i].jj);
        }else if(d1==drumminim(l1,c1,port[i].ii,port[i].jj)){
            nrd1[++lnrd1]=nrdrummin(l1,c1,port[i].ii,port[i].jj);
        }
    }
    d2=n+m;
    for(int i=1;i<=k;i++){
        if(d2>drumminim(l2,c2,port[i].ii,port[i].jj)){
            d2=drumminim(l2,c2,port[i].ii,port[i].jj);
            lnrd2=0;
            nrd2[++lnrd2]=nrdrummin(l2,c2,port[i].ii,port[i].jj);
        }else if(d2==drumminim(l2,c2,port[i].ii,port[i].jj)){
            nrd2[++lnrd2]=nrdrummin(l2,c2,port[i].ii,port[i].jj);
        }
    }
    if(d1+d2+1<=timp){
        if(d1+d2+1<timp){
            nr=0;
        }
        timp=d1+d2+1;
        for(int i=1;i<=lnrd1;i++){
            for(int j=1;j<=lnrd2;j++){
                nr=(nr+nrd1[i]*nrd2[j])%MOD;
            }
        }
    }
    g<<timp<<'\n'<<nr<<'\n';
}
