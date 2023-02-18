#include <bits/stdc++.h>
#define NMAX 1000

using namespace std;

int n,m,x,y,d;
int mat[NMAX+5][NMAX+5];
int p;
int k1,k2;

ifstream fi("matriceechilibrata.in");
ofstream fo("matriceechilibrata.out");

int gcd(int a,int b){
    int c;
    while(b){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main(){
    fi>>n>>m>>x>>y;
    d=gcd(x,y);
    p=gcd(n,m);
    if(n*x==m*y&&d<=p){
        k1=n/p;
        k2=m/p;
        for(int k=0;k<p;k++){
            for(int i=0;i<k1;i++){
                for(int j=0;j<k2;j++){
                    for(int dd=0;dd<d;dd++){
                        mat[1+k*k1+i][1+(((k+dd)*k2)%m)+j]=1;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                fo<<mat[i][j];
            }
            fo<<'\n';
        }
    }else{
        fo<<-1<<'\n';
    }
}