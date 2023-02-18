#include <iostream>
#include <fstream>
#define KMAX 100000
#define NMAX 3000

using namespace std;

ifstream f("tablou.in");
ofstream g("tablou.out");

int n,m,matrice[NMAX+5][NMAX+5],sume[NMAX+5][NMAX+5],l1,l2,c1,c2,culoare,k;
char ch;
long long sume_tablouri[KMAX+5],suma_tot;

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>ch;
            matrice[i][j]=ch-'0';
            sume[i][j]=sume[i-1][j]+sume[i][j-1]-sume[i-1][j-1]+matrice[i][j];
        }
    }
    f>>k;
    for(int i=1;i<=k;i++){
        f>>l1>>c1>>l2>>c2>>culoare;
        sume_tablouri[i]=sume[n][m]+culoare*(l2-l1+1)*(c2-c1+1)-(sume[l2][c2]-sume[l1-1][c2]-sume[l2][c1-1]+sume[l1-1][c1-1]);
        suma_tot+=sume_tablouri[i];
    }
    for(int i=1;i<=k;i++){
        g<<n*m*1LL*(1LL*k*sume_tablouri[i]-1LL*suma_tot)<<'\n';
    }
    f.close();
    g.close();
}
