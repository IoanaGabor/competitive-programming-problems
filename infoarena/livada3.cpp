
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("livada3.in");
ofstream g("livada3.out");

long long matrice[101][25001],maxim[101][25001],n,m,r,x,y,z,w,u,max_maxim=-1;
long long c,sume_partiale[101][25001];

void citire(){
    f>>n>>m>>c>>r>>x>>y>>z>>w>>u;
    for(int i=1;i<=m;i++){
        f>>matrice[1][i];
        sume_partiale[1][i]=sume_partiale[1][i-1]+matrice[1][i];
        if(i>1){
            maxim[1][i]=max(maxim[1][i-1],matrice[1][i]);
        }else{
            maxim[1][i]=matrice[1][i];
        }
        max_maxim=max(max_maxim,matrice[1][i]);
    }
    for(int i=2;i<=n;i++){
        f>>matrice[i][1];
        sume_partiale[i][1]=matrice[i][1];
        maxim[i][1]=matrice[i][1];
        max_maxim=max(max_maxim,matrice[i][1]);
    }
}

void construire_matrice(){
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            matrice[i][j]=(matrice[i-1][j]*x+matrice[i][j-1]*y+matrice[i-1][j-1]*z+w)%u;
            sume_partiale[i][j]=sume_partiale[i][j-1]+matrice[i][j];
            maxim[i][j]=max(maxim[i][j-1],matrice[i][j]);
            max_maxim=max(max_maxim,matrice[i][j]);
        }
    }
}

long long cauta_val(long long val,long long i){
    long long pas=1<<15,j=0;
    while(pas){
        if(maxim[i][j+pas]<=val&&j+pas<=m){
            j=j+pas;
        }
        pas=pas/2;
    }
    return j;
}

long long compara(long long val){
    if(val>max_maxim){
        return 0;
    }
    long long aux[101],suma=0;
    for(int i=1;i<=n;i++){
        aux[i]=sume_partiale[i][cauta_val(val,i)];
    }
    sort(aux+1,aux+n+1);
    for(int i=n-r+1;i<=n;i++){
        suma=suma+aux[i];
    }
    if(suma<c){
        return 1;
    }
    return 0;
}

long long cauta(){
    long long pas=1LL*1<<30,rez=0;
    while(pas){
        if(compara(rez+pas)){
            rez=rez+pas;
        }
        pas=pas/2;
    }
    return rez+1;
}

int main(){
    citire();
    construire_matrice();
    g<<cauta()<<'\n';
    f.close();
    g.close();
}
