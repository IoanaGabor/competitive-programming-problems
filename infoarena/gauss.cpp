#include <bits/stdc++.h>
#define NMAX 300
#define ERR 0.0000001

using namespace std;

ifstream fi("gauss.in");
ofstream fo("gauss.out");

int n,m;
double a[NMAX+5][NMAX+5];
int ii,jj,ok,p;
double x[NMAX+5];

int main(){
    fi>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m+1;j++){
            fi>>a[i][j];
        }
    }
    ii=jj=1;
    while(ii<=n&&jj<=m){
        ok=0;
        for(int i=ii;i<=n&&!ok;i++){
            if(abs(a[i][jj])>ERR){
                if(i!=ii){
                    for(int j=1;j<=m+1;j++){
                        swap(a[i][j],a[ii][j]);
                    }
                }
                ok=1;
            }
        }
        if(ok){
            for(int j=jj+1;j<=m+1;j++){
                a[ii][j]=(double)(a[ii][j]/((double)a[ii][jj]));
            }
            a[ii][jj]=1;
            for(int i=ii+1;i<=n;i++){
                for(int j=jj+1;j<=m+1;j++){
                    a[i][j]=a[i][j]-a[i][jj]*a[ii][j];
                }
                a[i][jj]=0;
            }
            ii++;
        }
        jj++;
    }
    for(int i=n;i>=1;i--){
        ok=0;
        for(int j=1;j<=m&&!ok;j++){
            if(abs(a[i][j])>ERR){
                p=j;
                ok=1;
            }
        }
        if(!ok){
            if(abs(a[i][m+1])>ERR){
                fo<<"Imposibil"<<'\n';
                fi.close();
                fo.close();
                return 0;
            }
        }else{
            x[p]=a[i][m+1];
            for(int j=p+1;j<=m;j++){
                x[p]-=a[i][j]*x[j];
            }
        }
    }
    for(int i=1;i<=m;i++){
        fo<<fixed<<setprecision(10)<<x[i]<<' ';
    }
    fi.close();
    fi.close();
}