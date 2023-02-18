
#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 100
#define x first
#define y second

using namespace std;

ifstream f("sudest.in");
ofstream g("sudest.out");

int n,k,matrice[NMAX+5][NMAX+5],mutari[2*NMAX],suma_max[NMAX+5][NMAX+5],ind;
pair <int,int> prec[NMAX+5][NMAX+5];
pair <pair<int,int>, int> aux,auxx;
queue <pair <pair<int,int>,int> > q;

void afisare(int ii,int jj){
    if(ii!=1||jj!=1){
        afisare(prec[ii][jj].x,prec[ii][jj].y);
    }
    g<<ii<<' '<<jj<<'\n';
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f>>matrice[i][j];
            suma_max[i][j]=-1;
        }
    }
    f>>k;
    for(int i=1;i<=k;i++){
        f>>mutari[i];
    }
    aux.x.x=1;
    aux.x.y=1;
    aux.y=1;
    q.push(aux);
    ind=1;
    suma_max[1][1]=matrice[1][1];
    while(!q.empty()){
        aux=q.front();
        q.pop();
        if(aux.x.x+mutari[aux.y]<=n){
            auxx.x.x=aux.x.x+mutari[aux.y];
            auxx.x.y=aux.x.y;
            if(suma_max[auxx.x.x][auxx.x.y]<suma_max[aux.x.x][aux.x.y]+matrice[auxx.x.x][auxx.x.y]){
                prec[auxx.x.x][auxx.x.y]=make_pair(aux.x.x,aux.x.y);
                suma_max[auxx.x.x][auxx.x.y]=suma_max[aux.x.x][aux.x.y]+matrice[auxx.x.x][auxx.x.y];
                if(aux.y<k){
                    auxx.y=aux.y+1;
                    q.push(auxx);
                }
            }
        }
        if(aux.x.y+mutari[aux.y]<=n){
            auxx.x.y=aux.x.y+mutari[aux.y];
            auxx.x.x=aux.x.x;
            if(suma_max[auxx.x.x][auxx.x.y]<suma_max[aux.x.x][aux.x.y]+matrice[auxx.x.x][auxx.x.y]){
                prec[auxx.x.x][auxx.x.y]=make_pair(aux.x.x,aux.x.y);
                suma_max[auxx.x.x][auxx.x.y]=suma_max[aux.x.x][aux.x.y]+matrice[auxx.x.x][auxx.x.y];
                if(aux.y<k){
                    auxx.y=aux.y+1;
                    q.push(auxx);
                }
            }
        }
    }
    g<<suma_max[n][n]<<'\n';
    afisare(n,n);
    f.close();
    g.close();
}
