
#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

ifstream fi("margiki.in");
ofstream fo("margiki.out");

struct matrice{
    long long C[4][4];
};

matrice inmultire(matrice A,matrice B){
    matrice rez;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            rez.C[i][j]=0;
            for(int k=0;k<3;k++){
                rez.C[i][j]=(rez.C[i][j]+1LL*A.C[i][k]*B.C[k][j])%MOD;
            }
        }
    }
    return rez;
}

matrice putere(matrice A,long long n){
    matrice rez;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
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

long long n;
long long sol;

int main(){
    fi>>n;
    if(n==1){
        fo<<1<<'\n';
    }else if(n==2){
        fo<<2<<'\n';
    }else if(n==3){
        fo<<4<<'\n';
    }else{
        matrice T;
        T.C[0][2]=T.C[1][0]=T.C[1][2]=T.C[2][1]=T.C[2][2]=1;
        T.C[0][0]=T.C[0][1]=T.C[1][1]=T.C[2][0]=0;
        T=putere(T,n-3);
        sol=(T.C[0][2]+2LL*T.C[1][2]%MOD+4LL*T.C[2][2]%MOD)%MOD;
        fo<<sol<<'\n';
    }
    fi.close();
    fo.close();
}