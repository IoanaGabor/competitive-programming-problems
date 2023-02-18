
#include <iostream>
#include <fstream>
#define NMAX  1000000000
#define MOD 1000000007

using namespace std;

ifstream f("aiafarapalindroame.in");
ofstream g("aiafarapalindroame.out");

int n;
struct matrice{
    long long a[3][3];
};

matrice inmultire(matrice A,matrice B){
    matrice C;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            C.a[i][j]=0;
            for(int k=0;k<2;k++){
                C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j])%MOD;
            }
        }
    }
    return C;
}

void sol(){
    if(n==1){
        g<<26<<'\n';
        return;
    }else if(n==2){
        g<<26*26<<'\n';
        return;
    }
    long long doi=26*25,trei=26*25*25;
    int cn=n;
    n=n-3;
    matrice t,b;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            t.a[i][j]=0;
            if(i==j){
                t.a[i][j]=1;
            }
        }
    }
    b.a[0][0]=0;
    b.a[0][1]=1;
    b.a[1][0]=b.a[1][1]=24;
    while(n){
        if(n%2==0){
            n=n/2;
            b=inmultire(b,b);
        }else{
            n--;
            t=inmultire(t,b);
        }
    }
    g<<(1LL*(doi*t.a[0][0])%MOD+1LL*(trei*t.a[0][1])%MOD+1LL*(doi*t.a[1][0])%MOD+1LL*(trei*t.a[1][1])%MOD)%MOD<<'\n';
    n=cn;
}

int main(){
    f>>n;
    sol();
    f.close();
    g.close();
}
