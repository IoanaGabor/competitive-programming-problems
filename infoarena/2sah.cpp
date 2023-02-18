
#include <iostream>
#include <fstream>
#define MOD 100003

using namespace std;

ifstream f("2sah.in");
ofstream g("2sah.out");

struct matrice{
    long long c[3][3];
};
matrice t;
matrice inmultire(matrice a,matrice b){
    matrice rez;
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            rez.c[i][j]=0;
            for(int k=0;k<=2;k++){
                rez.c[i][j]=(rez.c[i][j]+a.c[i][k]*b.c[k][j])%MOD;
            }
        }
    }
    return rez;
}

long long putere(long long n,long long exponent){
    long long rez=1;
    while(exponent){
        if(exponent%2==0){
            exponent=exponent/2;
            n=n*n%MOD;
        }else{
            exponent--;
            rez=rez*n%MOD;
        }
    }
    return rez;
}

matrice putere_matrice(matrice T,long long exponent){
    matrice rez;
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            if(i==j){
                rez.c[i][j]=1;
            }else{
                rez.c[i][j]=0;
            }
        }
    }
    while(exponent){
        if(exponent%2==0){
            exponent=exponent/2;
            T=inmultire(T,T);
        }else{
            exponent--;
            rez=inmultire(rez,T);
        }
    }
    return rez;
}

int main(){
    long long p,n,k;
    f>>p>>n>>k;
    if(p==1){
        g<<putere(3,k-1)%MOD<<'\n';
    }else{
        if(n+2-k==1){
            g<<1<<'\n';
        }else if(n+2-k==2){
            g<<1<<'\n';
        }else if(n+2-k==3){
            g<<2<<'\n';
        }else{
            t.c[0][1]=t.c[1][2]=t.c[2][0]=t.c[2][1]=t.c[2][2]=1;
            t=putere_matrice(t,n+1-k);
            int rez=(t.c[0][0]*1+t.c[0][1]*1+t.c[0][2]*2)%MOD;
            g<<rez<<'\n';
        }
    }
    f.close();
    g.close();
}
