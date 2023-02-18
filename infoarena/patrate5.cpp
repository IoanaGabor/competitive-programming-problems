#include <iostream>
#include <fstream>
#include <cmath>
#define VMAX 591
#define NMAX 1000

using namespace std;

ifstream f("patrate5.in");
ofstream g("patrate5.out");

int este[2*VMAX*VMAX+5],a[NMAX+5],b[NMAX+5],c[NMAX+5],v[NMAX+5],n,p;

int main(){
    f>>n>>p;
    v[2]=2;
    a[2]=1;
    b[2]=1;
    for(int i=1;i<=VMAX;i++){
        for(int j=1;j<=i;j++){
            este[i*i+j*j]=i;
        }
    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<=VMAX;j++){
            if(este[v[i-1]+j*j]){
                a[i]=este[v[i-1]+j*j];
                b[i]=sqrt(v[i-1]+j*j-a[i]*a[i]);
                c[i]=j;
                break;
            }
        }
        v[i]=a[i]*a[i]+b[i]*b[i];
    }
    g<<v[n]<<'\n';
    for(int i=n-p+2;i>=2;i--){
        g<<a[i]<<' '<<b[i]<<' ';
        for(int j=i+1;j<=n;j++){
            g<<c[j]<<' ';
        }
        g<<'\n';
    }
    f.close();
    g.close();
}
