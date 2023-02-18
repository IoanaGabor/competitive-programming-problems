
#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 1000

using namespace std;

ifstream f("sahara.in");
ofstream g("sahara.out");

int n,m,qmare,t,x1,x2,y1,y2,qmic,matrice[NMAX+5][NMAX+5],contor,rez,xx,yy;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
queue <pair <int,int> >q;
pair <int,int> aux;

void filll(int x,int y){
    q.push(make_pair(x,y));
    matrice[x][y]=-1;
    contor++;
    while(!q.empty()){
        aux=q.front();
        x=aux.first;
        y=aux.second;
        q.pop();
        for(int d=0;d<=3;d++){
            xx=x+dx[d];
            yy=y+dy[d];
            if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&matrice[xx][yy]>=qmare){
                q.push(make_pair(xx,yy));
                matrice[xx][yy]=-1;
                contor++;
            }
        }
    }
}

int main(){
    f>>n>>m>>qmare>>t;
    while(t--){
        f>>x1>>y1>>x2>>y2>>qmic;
        matrice[x1][y1]+=qmic;
        matrice[x2+1][y2+1]+=qmic;
        matrice[x1][y2+1]-=qmic;
        matrice[x2+1][y1]-=qmic;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            matrice[i][j]+=matrice[i-1][j]+matrice[i][j-1]-matrice[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(matrice[i][j]>=qmare){
                contor=0;
                filll(i,j);
                rez=max(rez,contor);
            }
        }
    }
    g<<rez;
    f.close();
    g.close();
}
