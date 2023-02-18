
#include <iostream>
#include <fstream>
#define MAXVAL 1<<30
#define NMAX 16

using namespace std;

ifstream f("flip.in");
ofstream g("flip.out");

int n,m,matrice[NMAX+5][NMAX+5],suma,rez=-MAXVAL;

void calculeaza(){
    int aux;
    suma=0;
    for(int i=1;i<=n;i++){
        aux=0;
        for(int j=1;j<=m;j++){
            aux+=matrice[i][j];
        }
        if(aux<0){
            aux*=(-1);
        }
        suma+=aux;
    }
}

void bkt(int k){
    if(k>m){
        calculeaza();
        rez=max(rez,suma);
    }else{
        bkt(k+1);
        for(int i=1;i<=n;i++){
            matrice[i][k]*=(-1);
        }
        bkt(k+1);
    }
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
        }
    }
    bkt(1);
    g<<rez;
    f.close();
    g.close();
}
