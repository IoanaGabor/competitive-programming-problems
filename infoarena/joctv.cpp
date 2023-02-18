
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("joctv.in");
ofstream g("joctv.out");

int n,aux[101][101],x,rez,suma=-10000000;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f>>x;
            aux[i][j]=aux[i-1][j]+x;
        }
    }
    for(int i=1;i<=n;i++){
        for(int k=i;k<=n;k++){
            suma=0;
            for(int j=1;j<=n;j++){
                if(suma+aux[k][j]-aux[i-1][j]>aux[k][j]-aux[i-1][j]){
                    suma+=aux[k][j]-aux[i-1][j];
                }else{
                    suma=aux[k][j]-aux[i-1][j];
                }
                rez=max(rez,suma);
            }
        }
    }
    g<<rez<<'\n';
    f.close();
    g.close();
}
