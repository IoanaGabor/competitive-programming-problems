#include <iostream>
#include <fstream>
#define NMAX 1000
#define LMAX 26

using namespace std;

ifstream f("rox.in");
ofstream g("rox.out");

int n,m,u,q,x1,x2,y1,y2;
int matrice[NMAX+3][NMAX+3],rez[NMAX+3][NMAX+3],val,sol;
char ch;

int main(){
    f>>n>>m>>u;
    while(u--){
        f>>x1>>y1>>x2>>y2>>ch;
        q=ch-'A';
        matrice[x1][y1]^=(1<<q);
        matrice[x2+1][y2+1]^=(1<<q);
        matrice[x1][y2+1]^=(1<<q);
        matrice[x2+1][y1]^=(1<<q);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            rez[i][j]=rez[i-1][j]^rez[i][j-1]^rez[i-1][j-1]^matrice[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            val=rez[i][j];
            sol=0;
            while(val){
                sol+=val%2;
                val/=2;
            }
            rez[i][j]=sol;
        }
    }
    f>>q;
    while(q--){
        f>>x1>>y1;
        g<<rez[x1][y1]<<'\n';
    }
    f.close();
    g.close();
}
