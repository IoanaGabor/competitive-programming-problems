
#include <iostream>
#include <fstream>
#include <cstring>
#define MMAX 50
#define NMAX 20
#define XMAX 60
#define MAXVAL (1LL<<20)-1

using namespace std;

ifstream f("zidar.in");
ofstream g("zidar.out");

int dp[3][NMAX+5][NMAX+5][XMAX+5],aux[NMAX+5][XMAX+5],auxx[NMAX+5][XMAX+5],matrice[MMAX+5][NMAX+5],sume[MMAX+5][NMAX+5],m,n,x,t,nrmaxc;

void init(){
    for(int i=0;i<=2;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                for(int l=0;l<=x;l++){
                    dp[i][j][k][l]=MAXVAL;
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            aux[i][j]=MAXVAL;
        }
    }
}

int main(){
    f>>m>>n>>x>>t;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            f>>matrice[i][j];
            sume[i][j]=matrice[i][j]+sume[i][j-1];
        }
    }
    init();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            auxx[i][j]=MAXVAL;
        }
    }
    for(int j=1;j<=n;j++){
        for(int k=j;k<=n;k++){
            dp[1][j][k][k-j+1]=sume[1][k]-sume[1][j-1];
            if(dp[1][j][k][k-j+1]<=t){
                nrmaxc=max(nrmaxc,k-j+1);
            }
            for(int l=j;l<=k;l++){
                aux[l][k-j+1]=min(aux[l][k-j+1],sume[1][k]-sume[1][j-1]);
                auxx[l][k-j+1]=aux[l][k-j+1];
            }
        }
    }
    for(int i=2;i<=m;i++){
        init();
        for(int j=1;j<=n;j++){
            for(int k=j;k<=n;k++){
                if(k-j+1<=x){
                    for(int l=j;l<=k;l++){
                        for(int c=1;c<=x;c++){
                            if(auxx[l][c]!=MAXVAL&&k-j+1+c<=x){
                                dp[i%2][j][k][k-j+1+c]=min(sume[i][k]-sume[i][j-1]+auxx[l][c],dp[i%2][j][k][k-j+1+c]);
                                if(dp[i%2][j][k][k-j+1+c]<=t){
                                    nrmaxc=max(nrmaxc,k-j+1+c);
                                }
                            }
                        }
                    }
                    for(int l=j;l<=k;l++){
                        for(int c=1;c<=x;c++){
                            aux[l][c]=min(aux[l][c],dp[i%2][j][k][c]);
                        }
                    }
                }
            }
        }
        for(int ii=1;ii<=n;ii++){
            for(int jj=1;jj<=x;jj++){
                auxx[ii][jj]=aux[ii][jj];
            }
        }
    }
    g<<nrmaxc;
    f.close();
    g.close();
}
