#include <iostream>
#include <fstream>
#define MAXNM 100
#define MAXTARA 2504
using namespace std;

int matrice[MAXNM][MAXNM],coloana_identica[MAXNM][MAXNM];
bool sepoate[MAXTARA][MAXNM][MAXNM],exista_tara[MAXTARA];

int main() {
    ifstream f("luna.in");
    ofstream g("luna.out");
    int n,m;
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            f>>matrice[i][j];
            exista_tara[matrice[i][j]]=true;
            if(matrice[i][j]==matrice[i-1][j]){
                coloana_identica[i][j]=coloana_identica[i-1][j]+1;
            }else{
                coloana_identica[i][j]=1;
            }
        }
    }
    int inalt;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            inalt=n+1;
            for(int k=j;k>=1 && matrice[i][j]==matrice[i][k];k--){
                inalt=min(inalt,coloana_identica[i][k]);
                sepoate[matrice[i][j]][inalt][j-k+1]=true;
            }
        }
    }
    int teste,l,L,tara;
    f>>teste;
    while(teste--){
        f>>tara>>l>>L;
        if(exista_tara[tara]){
            if(sepoate[tara][l][L] || sepoate[tara][L][l]){
                g<<"Cererea poate fi satisfacuta!"<<'\n';
            }else{
                g<<"Cererea nu poate fi satisfacuta!"<<'\n';
            }
        }else{
            g<<"Tara de provenienta nu are parcele pe Luna!"<<'\n';
        }
    }
    f.close();
    g.close();
}
