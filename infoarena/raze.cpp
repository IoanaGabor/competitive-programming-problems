
#include <iostream>
#include <fstream>
#define NMAX 135

using namespace std;

ifstream f("raze.in");
ofstream g("raze.out");

int t,n,m,matrice[NMAX+5][NMAX+5],aux[5][NMAX+5][NMAX+5],maxim,nmax,s;

int main(){
    f>>t;
    while(t--){
        f>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f>>matrice[i][j];
                for(int k=1;k<=4;k++){
                    aux[k][i][j]=0;
                }
                if(i>1&&j>1&&i<n&&j<m){
                    aux[1][i][j]=aux[1][i-1][j-1]+matrice[i-1][j-1];
                }
            }
        }
        for(int i=2;i<n;i++){
            for(int j=m-1;j>=2;j--){
                aux[2][i][j]=aux[2][i-1][j+1]+matrice[i-1][j+1];
            }
        }
        for(int i=n-1;i>=2;i--){
            for(int j=2;j<m;j++){
                aux[3][i][j]=aux[3][i+1][j-1]+matrice[i+1][j-1];
            }
        }
        for(int i=n-1;i>=2;i--){
            for(int j=m-1;j>=2;j--){
                aux[4][i][j]=aux[4][i+1][j+1]+matrice[i+1][j+1];
            }
        }
        maxim=-1;
        for(int i=2;i<=n-1;i++){
            for(int j=2;j<=m-1;j++){
                if(matrice[i][j]==0){
                    s=0;
                    for(int k=1;k<=4;k++){
                        if(aux[k][i][j]==0){
                            s++;
                        }
                    }
                    if(s>maxim){
                        maxim=s;
                        nmax=1;
                    }else if(s==maxim){
                        nmax++;
                    }
                }
            }
        }
        g<<maxim<<' '<<nmax<<'\n';
    }
    f.close();
    g.close();
}
