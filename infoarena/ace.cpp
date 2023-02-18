
#include <iostream>
#include <fstream>
#define nmax 1001

using namespace std;

ifstream f("ace.in");
ofstream g("ace.out");

int c,n,m,matrice[nmax][nmax],contor;
bool verif[nmax][nmax];
int main() {
    f>>c;
    f>>n>>m;
    for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
            f>>matrice[i][j];
       }
    }
    contor=0;
    int maxim=matrice[n][m],d_maxim=1;
    for(int i=n-1;i>=1;i--){
        if(maxim*(n-i)<matrice[i][m]*d_maxim){
            contor++;
            maxim=matrice[i][m];
            d_maxim=n-i;
        }
    }
    maxim=matrice[n][m];
    d_maxim=1;
    for(int i=m-1;i>=1;i--){
        if(maxim*(m-i)<matrice[n][i]*d_maxim){
            contor++;
            maxim=matrice[n][i];
            d_maxim=m-i;
        }
    }

    if(c==1){
        g<<contor;
        return 0;
    }
    int salt;
    d_maxim=1;
    bool prima=false;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            maxim=0;
            prima=false;
            salt=1;
            while(salt*i<n && salt*j<m){
                if(!verif[n-i*salt][m-j*salt]){
                    verif[n-i*salt][m-j*salt]=true;
                    if(!prima){
                        prima=true;
                        d_maxim=salt;
                        maxim=matrice[n-i*salt][m-j*salt];
                        contor++;
                    }
                    else if(matrice[n-i*salt][m-j*salt]*d_maxim>maxim*salt){
                        d_maxim=salt;
                        maxim=matrice[n-i*salt][m-j*salt];
                        contor++;
                    }
                }
                salt++;
            }
        }
    }
    g<<contor;
    f.close();
    g.close();
}
