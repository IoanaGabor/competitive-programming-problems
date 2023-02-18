
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#define NMAX 8
#define MMAX 14
#define VALMAX 10000

using namespace std;

ifstream f("scara2.in");
ofstream g("scara2.out");

int h,n,m,p,sir[NMAX+5],sol[NMAX+5],viz[MMAX+5],hsuma;
double dp[NMAX+5],efmin=VALMAX;

inline double dmin(double a,double b){
    if(a<b){
        return a;
    }
    return b;
}

inline double modul(double a){
    if(a>0){
        return a;
    }
    return -a;
}

inline double calculeaza(){
    double suma;
    for(int i=1;i<=n;i++){
        dp[i]=VALMAX;
        dp[i]=dmin(dp[i],dp[i-1]+sir[i]);
        suma=sir[i];
        for(int j=i-1;j>=1&&suma+sir[j]<=m;j--){
            suma+=sir[j];
            dp[i]=dmin(dp[i],(dp[j-1]+p+(double)(suma/(double)(i-j+1))));
        }
    }
    return dp[n];
}

inline void bkt(int k){
    if(k==n+1){
        if(hsuma==h){
            do{
                double aux=calculeaza();
                if(efmin>aux+0.001){
                    efmin=aux;
                    for(int i=1;i<=n;i++){
                        sol[i]=sir[i];
                    }
                }
            }while(next_permutation(sir+2,sir+n+1));
        }
    }else{
        for(int j=sir[k-1]+1;j<=m&&hsuma+j<=h;j++){
            hsuma+=j;
            sir[k]=j;
            bkt(k+1);
            hsuma-=j;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	f.tie(0); g.tie(0);
    f>>h>>n>>m>>p;
    bkt(1);
    g<<fixed<<setprecision(2)<<efmin<<'\n';
    for(int i=1;i<=n;i++){
        g<<sol[i]<<' ';
    }
    f.close();
    g.close();
}
