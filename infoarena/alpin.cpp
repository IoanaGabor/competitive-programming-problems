
#include <iostream>
#include <fstream>
#define NMAX 1024

using namespace std;

ifstream f("alpin.in");
ofstream g("alpin.out");

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int n,matrice[NMAX+5][NMAX+5],dp[NMAX+5][NMAX+5],prec[NMAX+5][NMAX+5],lgmax,xs,ys;

bool inauntru(int x,int y){
    if(1<=x&&x<=n&&1<=y&&y<=n){
        return true;
    }
    return false;
}

int afla_lungime(int x,int y){
    if(dp[x][y]){
        return dp[x][y];
    }
    int xn,yn;
    for(int d=0;d<4;d++){
        xn=x+dx[d];
        yn=y+dy[d];
        if(inauntru(xn,yn)&&matrice[xn][yn]<matrice[x][y]&&dp[x][y]<afla_lungime(xn,yn)){
            dp[x][y]=afla_lungime(xn,yn);
            prec[x][y]=d;
        }
    }
    dp[x][y]++;
    return dp[x][y];
}

void afiseaza(int x,int y){
    int xn,yn;
    if(prec[x][y]!=-1){
        xn=x+dx[prec[x][y]];
        yn=y+dy[prec[x][y]];
        afiseaza(xn,yn);
    }
    g<<x<<' '<<y<<'\n';
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f>>matrice[i][j];
            prec[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(lgmax<afla_lungime(i,j)){
                lgmax=afla_lungime(i,j);
                xs=i;
                ys=j;
            }
        }
    }
    g<<lgmax<<'\n';
    afiseaza(xs,ys);
    f.close();
    g.close();
}
