
#include <iostream>
#include <fstream>
#include <queue>
#define nmax 180

using namespace std;

ifstream f("alee.in");
ofstream g("alee.out");

int n,m,matrice[nmax][nmax],xf,yf;
bool gasit;
struct coord{
    int x,y;
};

queue <coord> q;

int main() {
    f>>n>>m;
    coord nr;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            matrice[i][j]=-2;
        }
    }
    for(int i=1;i<=m;i++){
        f>>nr.x>>nr.y;
        matrice[nr.x][nr.y]=-1;
    }
    f>>nr.x>>nr.y;
    matrice[nr.x][nr.y]=-1;
    q.push(nr);
    f>>xf>>yf;
    matrice[xf][yf]=-3;
    gasit=0;
    coord aux;
    while(!q.empty() && !gasit){
        nr=q.front();
        if(nr.x==xf && nr.y==yf){
            gasit=1;
            g<<matrice[xf][yf]+2;
        }else{
            if(matrice[nr.x+1][nr.y]<-1){
                matrice[nr.x+1][nr.y]=matrice[nr.x][nr.y]+1;
                aux.x=nr.x+1;
                aux.y=nr.y;
                q.push(aux);
            }
            if(matrice[nr.x][nr.y+1]<-1){
                matrice[nr.x][nr.y+1]=matrice[nr.x][nr.y]+1;
                aux.x=nr.x;
                aux.y=nr.y+1;
                q.push(aux);
            }
            if(matrice[nr.x-1][nr.y]<-1){
                matrice[nr.x-1][nr.y]=matrice[nr.x][nr.y]+1;
                aux.x=nr.x-1;
                aux.y=nr.y;
                q.push(aux);
            }
            if(matrice[nr.x][nr.y-1]<-1){
                matrice[nr.x][nr.y-1]=matrice[nr.x][nr.y]+1;
                aux.x=nr.x;
                aux.y=nr.y-1;
                q.push(aux);
            }
        }
        q.pop();
    }
    f.close();
    g.close();
}
