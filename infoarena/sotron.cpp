
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("sotron.in");
ofstream g("sotron.out");

int n,matrice[245][245],rez;

bool nu_am_iesit(int x,int y){
    return (x>=1&&x<=n&&y>=1&&y<=n);
}

void rezolva(int x,int y){
    int suma=0;
    while(nu_am_iesit(x,y)){
        if(suma+matrice[x][y]<=matrice[x][y]){
            suma=matrice[x][y];
        }else{
            suma+=matrice[x][y];
        }
        rez=max(rez,suma);
        if((x+y)%2==0){
            x--;
        }else{
            y++;
        }
    }
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f>>matrice[i][j];
        }
    }
    rez=matrice[1][1];
    for(int i=1;i<=n;i++){
        rezolva(i,1);
        rezolva(n,i);
    }
    g<<rez;
    f.close();
    g.close();
}
