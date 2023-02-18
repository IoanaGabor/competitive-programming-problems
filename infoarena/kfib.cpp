
#include <iostream>
#include <fstream>
#define MOD 666013;

using namespace std;

struct matrice{
    long long C[2][2];
};

matrice inmultire(matrice A,matrice B){
    matrice rez;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            rez.C[i][j]=0;
            for(int k=0;k<2;k++){
                rez.C[i][j]=(rez.C[i][j]+A.C[i][k]*B.C[k][j])%MOD;
            }
        }
    }
    return rez;
}

matrice putere(matrice A,int n){
    matrice rez;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            rez.C[i][j]=0;
            if(i==j){
                rez.C[i][j]++;
            }
        }
    }
    while(n){
        if(n%2==0){
            n=n/2;
            A=inmultire(A,A);
        }else{
            n--;
            rez=inmultire(A,rez);
        }
    }
    return rez;
}

int main(){
    ifstream f("kfib.in");
    ofstream g("kfib.out");
    int n;
    f>>n;
    matrice T;
    T.C[0][1]=T.C[1][0]=T.C[1][1]=1;
    T.C[0][0]=0;
    T=putere(T,n);
    g<<(T.C[0][1])%MOD;
    f.close();
    g.close();
}
