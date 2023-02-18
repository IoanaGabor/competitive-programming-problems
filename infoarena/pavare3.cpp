
#include <iostream>
#include <fstream>
#define NMAX 150

using namespace std;

ifstream f("pavare3.in");
ofstream g("pavare3.out");

int n,m;
int matrice[NMAX+5][NMAX+5],cnt,invers,sc,nl;

int main(){
    f>>n>>m;
    if((n<m||n==3)&&m!=3){
        swap(n,m);
        invers=1;
    }
    for(int i=1;i<=m;i+=3){
        for(int j=1;j<=n;j+=4){
            if(j+3<=n&&cnt*6<n*m/2&&i+2<=m){
                matrice[j][i]=matrice[j+1][i]=matrice[j+2][i]=matrice[j+3][i]=matrice[j][i+1]=matrice[j+2][i+1]=++cnt;
                matrice[j][i+2]=matrice[j+1][i+2]=matrice[j+2][i+2]=matrice[j+3][i+2]=matrice[j+1][i+1]=matrice[j+3][i+1]=++cnt;
            }
        }
    }
    sc=(n/4)*4;
    nl=n*m/24;
    if(sc>nl*4){
        sc=nl*4;
    }
    if(n%2==0){
        for(int i=sc+1;i<=n;i+=2){
            for(int j=1;j<=m;j++){
                matrice[i][j]=matrice[i+1][j]=++cnt;
            }
        }
    }else{
        for(int i=sc+1;i<=n;i++){
            for(int j=1;j<=m;j+=2){
                matrice[i][j]=matrice[i][j+1]=++cnt;
            }
        }
    }
    for(int i=1;i<=n;i+=2){
        for(int j=1;j<=m;j++){
            if(matrice[i][j]==0){
                matrice[i][j]=matrice[i+1][j]=++cnt;
            }
        }
    }
    if(!invers){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                g<<matrice[i][j]<<' ';
            }
            g<<'\n';
        }
    }else{
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                g<<matrice[j][i]<<' ';
            }
            g<<'\n';
        }
    }

    f.close();
    g.close();
}
