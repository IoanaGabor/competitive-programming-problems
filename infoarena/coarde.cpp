#include <bits/stdc++.h>
#define NMAX 1000
#define MOD 9999991

using namespace std;

ifstream fi("coarde.in");
ofstream fo("coarde.out");

int n,teste;
long long cat[NMAX+5];

int main() {
    cat[0]=1;
    for(int i=1;i<=NMAX;i++){
        cat[i]=0;
        for(int j=0;j<i;j++){
            cat[i]=(cat[i]+1LL*cat[j]*cat[i-j-1])%MOD;

        }
    }
    while(fi>>n){
        if(n==0){
            break;
        }
        teste++;
        fo<<teste<<":"<<cat[n]<<'\n';
    }
    fi.close();
    fo.close();
}
