
#include <iostream>
#include <fstream>
#define nmax 1005

using namespace std;

ifstream f("fadema.in");
ofstream g("fadema.out");

int matrice[nmax][nmax],matrice_aux[nmax][nmax],n,m;

int main() {
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
            if(i==1){
                matrice_aux[i][j]=1;
            }else{
                if(matrice[i][j]!=matrice[i-1][j]){
                    matrice_aux[i][j]=matrice_aux[i-1][j]+1;
                }else{
                    matrice_aux[i][j]=1;
                }
            }
        }
    }
    int L,l,rez=1;
    bool continua=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            continua=1;
            L=n;
            for(int k=j;k>=1 && continua;k--){
                if(matrice[i][k]==matrice[i][k-1] || rez>j*L){
                    continua=0;
                }
                    L=min(L,matrice_aux[i][k]);
                    l=j-k+1;
                    if(rez<l*L){
                        rez=l*L;
                    }

            }

        }
    }
    g<<rez;
    f.close();
    g.close();
}
