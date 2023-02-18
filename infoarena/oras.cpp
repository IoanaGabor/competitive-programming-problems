
#include <iostream>
#include <fstream>
#define NMAX 200

using namespace std;

ifstream f("oras.in");
ofstream g("oras.out");

int n,matrice[NMAX+5][NMAX+5];

void calc(int n){
    if(n==3){
        matrice[1][2]=1;
        matrice[2][3]=1;
        matrice[3][1]=1;
        return;
    }
    if(n==6){
        matrice[1][2]=1;
        matrice[1][5]=1;
        matrice[1][6]=1;
        matrice[2][3]=1;
        matrice[2][5]=1;
        matrice[3][1]=1;
        matrice[3][5]=1;
        matrice[3][6]=1;
        matrice[4][1]=1;
        matrice[4][2]=1;
        matrice[4][3]=1;
        matrice[5][4]=1;
        matrice[5][6]=1;
        matrice[6][2]=1;
        matrice[6][4]=1;
        return;
    }
    calc(n-2);
    matrice[n-1][n]=1;
    for(int i=1;i<=n-2;i++){
        matrice[n][i]=1;
        matrice[i][n-1]=1;
    }
}

int main(){
    f>>n;
    if(n==4){
        g<<-1<<'\n';
    }else{
        calc(n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g<<matrice[i][j];
            }
            g<<'\n';
        }
    }
    f.close();
    g.close();
}
