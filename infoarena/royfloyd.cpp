
#include <iostream>
#include <fstream>
#define NMAX 100

using namespace std;

ifstream f("royfloyd.in");
ofstream g("royfloyd.out");

int n,matrice[NMAX+5][NMAX+5];

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f>>matrice[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(matrice[i][k]&&matrice[k][j]&&i!=j&&(matrice[i][j]>matrice[i][k]+matrice[k][j]||matrice[i][j]==0)){
                    matrice[i][j]=matrice[i][k]+matrice[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g<<matrice[i][j]<<' ';
        }
        g<<'\n';
    }
    f.close();
    g.close();
}
