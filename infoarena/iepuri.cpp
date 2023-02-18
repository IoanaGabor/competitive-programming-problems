#include <bits/stdc++.h>
#define MOD 666013

using namespace std;

ifstream fi("iepuri.in");
ofstream fo("iepuri.out");

int t;
int x,y,z,a,b,c,n;
long long sol;

struct matrice{
    long long mat[3][3];
} A,T;

matrice mult(matrice a,matrice b){
    matrice c;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            c.mat[i][j]=0;
            for(int k=0;k<3;k++){
                c.mat[i][j]=(c.mat[i][j]+1LL*a.mat[i][k]*b.mat[k][j])%MOD;
            }
        }
    }
    return c;
}

void solve(){
    fi>>x>>y>>z>>a>>b>>c>>n;
    T.mat[0][0]=T.mat[0][2]=T.mat[1][0]=T.mat[1][1]=0;
    T.mat[0][1]=T.mat[1][2]=1;
    T.mat[2][0]=c;
    T.mat[2][1]=b;
    T.mat[2][2]=a;
    n-=2;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==j){
                A.mat[i][j]=1;
            }else{
                A.mat[i][j]=0;
            }
        }
    }
    while(n){
        if(n%2==0){
            n/=2;
            T=mult(T,T);
        }else{
            n--;
            A=mult(A,T);
        }
    }
    sol=((A.mat[2][0]*x)%MOD + (A.mat[2][1]*y)%MOD + (A.mat[2][2]*z)%MOD)%MOD;
    fo<<sol<<'\n';
}

int main()
{
    fi>>t;
    while(t--){
        solve();
    }
    fi.close();
    fo.close();
    return 0;
}
