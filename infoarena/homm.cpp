
#include <iostream>
#include <fstream>
#define NMMAX 105
#define KMAX 21
using namespace std;

int a[KMAX][NMMAX][NMMAX];

int main() {
    ifstream f("homm.in");
    ofstream g("homm.out");
    long long n,m,k,x1,x2,y1,y2;
    f>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            f>>a[1][i][j];
            if(a[1][i][j]!=0){
                a[1][i][j]=-1;
            }
        }
    }
    for(int i=0;i<=n+1;i++){
        a[1][i][0]=-1;
        a[1][i][m+1]=-1;

    }
    for(int j=0;j<=m+1;j++){
        a[1][0][j]=-1;
        a[1][n+1][j]=-1;
    }
    f>>x1>>y1>>x2>>y2;
    if(a[1][x1+1][y1]==0){
        a[1][x1+1][y1]=1;
    }
    if(a[1][x1-1][y1]==0){
        a[1][x1-1][y1]=1;
    }
    if(a[1][x1][y1+1]==0){
        a[1][x1][y1+1]=1;
    }
    if(a[1][x1][y1-1]==0){
        a[1][x1][y1-1]=1;
    }
    for(int l=2;l<=k;l++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[1][i][j]!=-1){
                    if(a[l-1][i+1][j]>0){
                        a[l][i][j]=a[l][i][j]+a[l-1][i+1][j];
                    }
                    if(a[l-1][i-1][j]>0){
                        a[l][i][j]=a[l][i][j]+a[l-1][i-1][j];
                    }
                    if(a[l-1][i][j+1]>0){
                        a[l][i][j]=a[l][i][j]+a[l-1][i][j+1];
                    }
                    if(a[l-1][i][j-1]>0){
                        a[l][i][j]=a[l][i][j]+a[l-1][i][j-1];
                    }
                }
            }

        }
    }
    long long s=0;
    for(int l=1;l<=k;l++){
        s=s+a[l][x2][y2];
    }
    if(x1==x2 && y1==y2){
        s++;
    }
    g<<s;
    f.close();
    g.close();
}
