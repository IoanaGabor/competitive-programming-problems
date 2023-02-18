
#include <iostream>
#include <fstream>
#define NMAX 100

using namespace std;

ifstream f("yinyang.in");
ofstream g("yinyang.out");

int n,m,matrice[NMAX+5][NMAX+5],ok,cnt,k;

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
        }
    }
    while(!ok){
        ok=1;
        for(int i=1;i<n;i++){
            k=1;
            while(matrice[i][k]==matrice[i+1][k]&&k<m){
                k++;
            }
            if(matrice[i][k]>matrice[i+1][k]){
                ok=0;
                cnt++;
                for(int j=1;j<=m;j++){
                    swap(matrice[i][j],matrice[i+1][j]);
                }
            }
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<n;i++){
            if(matrice[i][j]>matrice[i+1][j]){
                ok=0;
            }
        }
    }
    if(ok==0){
        g<<"-1";
        f.close();
        g.close();
        return 0;
    }
    ok=0;
    while(!ok){
        ok=1;
        for(int j=1;j<m;j++){
            k=1;
            while(matrice[k][j]==matrice[k][j+1]&&k<n){
                k++;
            }
            if(matrice[k][j]>matrice[k][j+1]){
                ok=0;
                cnt++;
                for(int i=1;i<=n;i++){
                    swap(matrice[i][j],matrice[i][j+1]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            if(matrice[i][j]>matrice[i][j+1]){
                ok=0;
            }
        }
    }
    if(ok==0){
        g<<"-1";
    }else{
        g<<cnt;
    }
    f.close();
    g.close();
}
