
#include <iostream>
#include <fstream>
#define NMAX 1000

using namespace std;

ifstream f("triunghi3.in");
ofstream g("triunghi3.out");

int n,triunghi[NMAX+5][NMAX+5],dp[NMAX+5][NMAX+5],sumel[NMAX+5][NMAX+5],sumec[NMAX+5][NMAX+5];

int calc(int x,int y){
    int suma=0,suma2=0,s=0,s2=0;
    suma=(sumec[n-y][y]-sumec[x-1][y]+sumec[n-y][y+1]-sumec[x-1][y+1])*(n-y-x+1);
    s=triunghi[n-y+1][y]+triunghi[x][y]+2*(sumec[n-y][y]-sumec[x][y]);
    suma2=(sumel[x][n-x]-sumel[x][y-1]+sumel[x+1][n-x]-sumel[x+1][y-1])*(n-y-x+1);
    s2=triunghi[x][n-x+1]+triunghi[x][y]+2*(sumel[x][n-x]-sumel[x][y]);
    return min(suma+s+dp[x][y+1],suma2+s2+dp[x+1][y]);
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            f>>triunghi[i-j+1][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            sumel[i][j]=sumel[i][j-1]+triunghi[i][j];
            sumec[i][j]=sumec[i-1][j]+triunghi[i][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(i==n){
                dp[i-j+1][j]=0;
            }else{
                dp[i-j+1][j]=calc(i-j+1,j);
            }
        }
    }
    g<<dp[1][1];
    f.close();
    g.close();
}
