
#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>

using namespace std;

ifstream f("lacuri.in");
ofstream g("lacuri.out");

int n,matrice[105][105],dim,e,contor;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
queue <pair<int,int> > q;
pair<int,int> aux,aux2;
int maxx,minx,maxy,miny;

void afiseaza(int x,int y){
    if(x==1&&y==1){
        g<<x<<' '<<y<<'\n';
        return;
    }
    int xx,yy;
    for(int i=0;i<=3;i++){
        xx=x+dx[i];
        yy=y+dy[i];
        if(xx>0&&xx<=n&&yy>0&&yy<=n&&matrice[xx][yy]+1==matrice[x][y]){
            afiseaza(xx,yy);
            break;
        }
    }
    g<<x<<' '<<y<<'\n';
}

void umple(int x,int y){
    matrice[x][y]=e;
    dim++;
    if(x<minx){
        minx=x;
    }
    if(x>maxx){
        maxx=x;
    }
    if(y<miny){
        miny=y;
    }
    if(y>maxy){
        maxy=y;
    }
    int xx,yy;
    for(int i=0;i<=3;i++){
        xx=x+dx[i];
        yy=y+dy[i];
        if(xx<=n&&xx>0&&yy<=n&&yy>0&&matrice[xx][yy]==1){
            umple(xx,yy);
        }
    }
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f>>matrice[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(matrice[i][j]==1){
                e--;
                dim=0;
                maxx=maxy=0;
                minx=miny=105;
                umple(i,j);
                if(sqrt(dim)*sqrt(dim)==dim&&maxx-minx==maxy-miny&&maxy-miny+1==sqrt(dim)){
                    contor++;
                }
            }
        }
    }
    g<<contor<<'\n';
    if(contor==-e){
        aux.first=1;
        aux.second=1;
        q.push(aux);
        matrice[1][1]=1;
        while(!q.empty()){
            aux=q.front();
            q.pop();
            aux2=aux;
            for(int i=0;i<=3;i++){
                aux2.first=aux.first+dx[i];
                aux2.second=aux.second+dy[i];
                if(aux2.first>0&&aux2.second>0&&aux2.first<=n&&aux2.second<=n&&(matrice[aux2.first][aux2.second]==0)){
                    matrice[aux2.first][aux2.second]=matrice[aux.first][aux.second]+1;
                    q.push(aux2);
                }
            }
        }
        afiseaza(n,n);
    }
    f.close();
    g.close();
}
