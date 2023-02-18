
#include <iostream>
#include <fstream>
#define NMAX 500
using namespace std;

ifstream f("tort2.in");
ofstream g("tort2.out");

int n,m,k,val,s[NMAX+1][NMAX+1],t,a,b,minim=NMAX*NMAX,contor,aux;

int main(){
    f>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>val;
            s[i][j]=val+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    t=s[n][m];
    for(int kk=0;kk<=k;kk++){
        a=n-kk;
        b=m-(k-kk);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i+a-1<=n&&j+b-1<=m){
                    aux=s[i+a-1][j+b-1]-s[i+a-1][j-1]-s[i-1][j+b-1]+s[i-1][j-1];
                    if(minim>aux){
                        minim=aux;
                        contor=1;
                    }else if(minim==aux){
                        contor++;
                    }
                }
                if(j+b-1>m){
                    break;
                }
            }
            if(i+a-1>n){
                break;
            }
        }
    }
    g<<t-minim<<'\n'<<contor<<'\n';
    f.close();
    g.close();
}
