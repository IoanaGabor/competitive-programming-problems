
#include <iostream>
#include <fstream>
#define MOD 1000000007
using namespace std;

ifstream f("fibsum.in");
ofstream g("fibsum.out");

int t,le,ri;
struct matrice{
    long long m[3][3];
};

matrice inmultire(matrice a,matrice b){
    matrice c;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            c.m[i][j]=0;
            for(int k=0;k<2;k++){
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
            }
        }
    }
    return c;
}

int fib(int k){
    matrice tr,rez;
    tr.m[0][1]=tr.m[1][0]=tr.m[1][1]=1;
    tr.m[0][0]=0;
    rez.m[0][0]=rez.m[1][1]=1;
    rez.m[0][1]=rez.m[1][0]=0;
    if(k>=2){
        k--;
        while(k){
            if(k%2==0){
                tr=inmultire(tr,tr);
                k=k/2;
            }else{
                k--;
                rez=inmultire(rez,tr);
            }
        }
        return 1LL*(rez.m[1][0]+rez.m[1][1])%MOD;
    }
    return 1;
}

int main(){
    f>>t;
    while(t--){
        f>>le>>ri;
        g<<(fib(ri+2)-fib(le+1)+MOD)%MOD<<'\n';
    }
    f.close();
    g.close();
}
