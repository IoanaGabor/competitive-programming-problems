
#include <iostream>
#include <fstream>
#define nmax 1501

using namespace std;

ifstream f("bemo.in");
ofstream g("bemo.out");

struct indici{
    int rand,coloana;
};

indici sir[nmax*nmax];
int matrice[nmax][nmax];
bool marcat[nmax][nmax];
int r,c;

int main(){
    f>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            f>>matrice[i][j];
            sir[matrice[i][j]].rand=i;
            sir[matrice[i][j]].coloana=j;
        }
    }
    int x,y;
    for(int i=1;i<=r*c;i++){
        x=sir[i].rand;
        y=sir[i].coloana;
        if(!marcat[x][y]){
            for(int k=x-1;k>=1;k--){
                for(int j=y+1;j<=c;j++){
                    if(!marcat[k][j]){
                        marcat[k][j]=1;
                    }else{
                        break;
                    }
                }
            }
            for(int k=x+1;k<=r;k++){
                for(int j=y-1;j>=1;j--){
                    if(!marcat[k][j]){
                        marcat[k][j]=1;
                    }else{
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(!marcat[i][j]){
                g<<matrice[i][j]<<' ';
            }
        }
    }
    f.close();
    g.close();
}
