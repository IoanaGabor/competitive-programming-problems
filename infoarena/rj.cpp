#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 100
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("rj.in");
ofstream g("rj.out");

int n,m,ij,jj,ir,jr,irez,jrez,rez=MAXVAL;
char matrice[NMAX+5][NMAX+5];
int drum[2][NMAX+5][NMAX+5];
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
queue <pair<int,int> > q;

bool ok(int i,int j,int ind){
    if(1<=i&&i<=n&&1<=j&&j<=m&&matrice[i][j]==' '&&drum[ind][i][j]==0){
        return true;
    }
    return false;
}

void bfs(int is,int js,int ind){
    pair<int,int> aux,auxx;
    aux=make_pair(is,js);
    q.push(aux);
    drum[ind][is][js]=1;
    while(!q.empty()){
        aux=q.front();
        q.pop();
        for(int dir=0;dir<8;dir++){
            auxx.first=aux.first+dx[dir];
            auxx.second=aux.second+dy[dir];
            if(ok(auxx.first,auxx.second,ind)){
                drum[ind][auxx.first][auxx.second]=drum[ind][aux.first][aux.second]+1;
                q.push(auxx);
            }
        }
    }
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f.get();
        for(int j=1;j<=m;j++){
            matrice[i][j]=f.get();
            if(matrice[i][j]=='R'){
                ir=i;
                jr=j;
            }else if(matrice[i][j]=='J'){
                ij=i;
                jj=j;
            }else if(matrice[i][j]=='X'){
                drum[0][i][j]=drum[1][i][j]=-1;
            }
        }
    }
    bfs(ir,jr,0);
    bfs(ij,jj,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(drum[0][i][j]==drum[1][i][j]&&drum[0][i][j]>0&&rez>drum[0][i][j]){
                rez=drum[0][i][j];
                irez=i;
                jrez=j;
            }
        }
    }
    g<<rez<<' '<<irez<<' '<<jrez;
    f.close();
    g.close();
}
