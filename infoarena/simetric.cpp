
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("simetric.in");
ofstream g("simetric.out");

int n,m,matrice[401][401],aux[401][401],frecventa[401],ok,l,l_max;

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        aux[i][m]=1;
        frecventa[1]++;
    }
    for(int i=1;i<=m;i++){
        aux[n][i]=1;
        frecventa[1]++;
    }
    frecventa[1]--;
    for(int i=n-1;i>=1;i--){
        for(int j=m-1;j>=1;j--){
            ok=1;
            l=aux[i+1][j+1];
            for(int k=1;k<=l&&ok;k++){
                if(matrice[i][j+k]!=matrice[i+k][j]){
                    ok=0;
                }else{
                    aux[i][j]++;
                    frecventa[aux[i][j]]++;
                }
            }
            aux[i][j]++;
            frecventa[aux[i][j]]++;
            l_max=max(aux[i][j],l_max);
        }
    }
    for(int i=1;i<=l_max;i++){
        g<<frecventa[i]<<'\n';
    }
    f.close();
    g.close();
}

