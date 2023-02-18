
#include <iostream>
#include <fstream>
#define NMAX 1000
#define MMAX 5000

using namespace std;

ifstream f("robot3.in");
ofstream g("robot3.out");

int n,m,matrice[NMAX+1][NMAX+1],sir[MMAX+1],x,y,e;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char ch;

int main(){
    f>>n>>m>>x>>y;
    for(int i=1;i<=m;i++){
        f>>ch;
        if(ch=='N'){
            sir[i]=0;
        }
        if(ch=='E'){
            sir[i]=1;
        }
        if(ch=='S'){
            sir[i]=2;
        }
        if(ch=='V'){
            sir[i]=3;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f>>matrice[i][j];
        }
    }
    e=matrice[x][y];
    for(int i=1;i<=m&&e;i++){
        e--;
        x+=dx[sir[i]];
        y+=dy[sir[i]];
        e+=matrice[x][y];
    }
    g<<x<<' '<<y<<'\n';
    f.close();
    g.close();
}
