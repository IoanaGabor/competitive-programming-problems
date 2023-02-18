#include <bits/stdc++.h>
#define NMAX 2000
#define MOD 1000000007

using namespace std;

ifstream fi("matsum.in");
ofstream fo("matsum.out");

int n,m;
int p[NMAX+5],q[NMAX+5];
int mat[NMAX+5][NMAX+5];
long long sum1[NMAX+5][NMAX+5],sum2[NMAX+5][NMAX+5],sum3[NMAX+5][NMAX+5],sum4[NMAX+5][NMAX+5];
long long rez,aux,buc;

int main(){
    fi>>n>>m;
    for(int i=1;i<=n;i++){
        fi>>p[i];
    }
    for(int j=1;j<=m;j++){
        fi>>q[j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mat[i][j]=((p[i]*q[j])^p[i]^q[j]);
            sum1[i][j]=(((1LL*mat[i][j]*i*j)%MOD)+sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1]+MOD)%MOD;
            sum2[i][j]=(((1LL*mat[i][j]*i*(m-j+1))%MOD)+sum2[i-1][j]+sum2[i][j-1]-sum2[i-1][j-1]+MOD)%MOD;
            sum3[i][j]=(((1LL*mat[i][j]*(n-i+1)*j)%MOD)+sum3[i-1][j]+sum3[i][j-1]-sum3[i-1][j-1]+MOD)%MOD;
            sum4[i][j]=(((1LL*mat[i][j]*(n-i+1)*(m-j+1))%MOD)+sum4[i-1][j]+sum4[i][j-1]-sum4[i-1][j-1]+MOD)%MOD;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            aux=(((1LL*mat[i][j]*sum1[i][j])%MOD)*1LL*(n-i+1)*(m-j+1))%MOD;
            rez+=aux;
            rez%=MOD;
            buc=(sum2[i][m]-sum2[i][j]+MOD)%MOD;
            aux=(((1LL*mat[i][j]*buc)%MOD)*1LL*(n-i+1)*j)%MOD;
            rez+=aux;
            rez%=MOD;
            buc=(sum3[n][j]-sum3[i][j]+MOD)%MOD;
            aux=(((1LL*mat[i][j]*buc)%MOD)*1LL*i*(m-j+1))%MOD;
            rez+=aux;
            rez%=MOD;
            buc=(sum4[n][m]-sum4[n][j]-sum4[i][m]+sum4[i][j]+2*MOD)%MOD;
            aux=(((1LL*mat[i][j]*buc)%MOD)*1LL*i*j)%MOD;
            rez+=aux;
            rez%=MOD;
        }
    }
    fo<<rez;
    fi.close();
    fo.close();
}