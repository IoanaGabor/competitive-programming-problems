#include <iostream>
#include <fstream>
#define NMAX 100

using namespace std;

ifstream f("neuroni.in");
ofstream g("neuroni.out");

int matrice[NMAX+5][NMAX+5],n,m;

void constr_matrice(){
    matrice[1][1]=m;
    for(int i=1;i<n;i++){
        for(int j=1;j<=i;j++){
            if(i%2==0){
                matrice[i+1][j]+=matrice[i][j]/2+matrice[i][j]%2;
                matrice[i+1][j+1]+=matrice[i][j]/2;
            }else{
                matrice[i+1][j]+=matrice[i][j]/2;
                matrice[i+1][j+1]+=matrice[i][j]/2+matrice[i][j]%2;
            }
        }
    }
}

int main() {
    f>>n>>m;
    constr_matrice();
    for(int i=1;i<=n;i++){
        g<<matrice[n][i]<<' ';
    }
    f.close();
    g.close();
}
