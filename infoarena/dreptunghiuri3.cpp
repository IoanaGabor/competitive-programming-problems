
#include <iostream>
#include <fstream>
#include <algorithm>
#define KMAX 1000

using namespace std;

ifstream f("dreptunghiuri3.in");
ofstream g("dreptunghiuri3.out");

struct dreptunghi{
    int x1,x2,y1,y2,val;
    int px1,px2,py1,py2;
} sir[KMAX+3];
int n,m,k,X[3*KMAX+10],Y[3*KMAX+10],lx,ly,matrice[3*KMAX+10][3*KMAX+10];
long long maxim,nrmax;

void elimdubluri(int sir[],int& l){
    int aux=-1;
    int sir2[3*KMAX+10],l2=0;
    for(int i=1;i<=l;i++){
        if(aux==sir[i]){
            sir[i]=-1;
        }else{
            aux=sir[i];
            sir2[++l2]=sir[i];
        }
    }
    for(int i=1;i<=l2;i++){
        sir[i]=sir2[i];
    }
    l=l2;
}

int cauta_indice(int val,int sir[],int l){
    int pas=1<<12,rez=0;
    while(pas){
        if(pas+rez<=l&&sir[rez+pas]<=val){
            rez+=pas;
        }
        pas>>=1;
    }
    return rez;
}

int main(){
    f>>n>>m>>k;
    for(int i=1;i<=k;i++){
        f>>sir[i].x1>>sir[i].y1>>sir[i].x2>>sir[i].y2>>sir[i].val;
        X[++lx]=sir[i].x1;
        X[++lx]=sir[i].x2;
        X[++lx]=sir[i].x2+1;
        Y[++ly]=sir[i].y1;
        Y[++ly]=sir[i].y2;
        Y[++ly]=sir[i].y2+1;
    }
    X[++lx]=1;
    X[++lx]=n;
    Y[++ly]=1;
    Y[++ly]=m;
    sort(X+1,X+lx+1);
    elimdubluri(X,lx);
    sort(Y+1,Y+ly+1);
    elimdubluri(Y,ly);
    if(X[lx]==n+1){
        lx--;
    }
    if(Y[ly]==m+1){
        ly--;
    }
    X[lx+1]=n+1;
    Y[ly+1]=m+1;
    for(int i=1;i<=k;i++){
        sir[i].px1=cauta_indice(sir[i].x1,X,lx);
        sir[i].px2=cauta_indice(sir[i].x2,X,lx);
        sir[i].py1=cauta_indice(sir[i].y1,Y,ly);
        sir[i].py2=cauta_indice(sir[i].y2,Y,ly);
        matrice[sir[i].px1][sir[i].py1]+=sir[i].val;
        matrice[sir[i].px2+1][sir[i].py2+1]+=sir[i].val;
        matrice[sir[i].px1][sir[i].py2+1]-=sir[i].val;
        matrice[sir[i].px2+1][sir[i].py1]-=sir[i].val;
    }
    for(int i=1;i<=lx;i++){
        for(int j=1;j<=ly;j++){
            matrice[i][j]+=matrice[i-1][j]+matrice[i][j-1]-matrice[i-1][j-1];
            if(maxim<matrice[i][j]){
                maxim=matrice[i][j];
                nrmax=1LL*(X[i+1]-X[i])*(Y[j+1]-Y[j]);
            }else if(maxim==matrice[i][j]){
                nrmax+=1LL*(X[i+1]-X[i])*(Y[j+1]-Y[j]);
            }
        }
    }
    g<<maxim<<' '<<nrmax<<'\n';
    f.close();
    g.close();
}
