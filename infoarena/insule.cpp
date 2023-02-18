
#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 100

using namespace std;

ifstream f("insule.in");
ofstream g("insule.out");

int n,m,matrice[NMAX+5][NMAX+5],copie[NMAX+5][NMAX+5],rez[5],drum[NMAX+5][NMAX+5];
char ch;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
queue <pair<int,int> > q;
pair <int,int> aux,auxx;

void filll(int val,int x,int y){
    copie[x][y]=-1;
    for(int i=0;i<4;i++){
        if(copie[x+dx[i]][y+dy[i]]==val){
            filll(val,x+dx[i],y+dy[i]);
        }
    }
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>ch;
            matrice[i][j]=ch-'0';
            copie[i][j]=matrice[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        copie[i][0]=copie[i][m+1]=-1;
        matrice[i][0]=matrice[i][m+1]=-1;
    }
    for(int i=1;i<=m;i++){
        copie[0][i]=copie[n+1][i]=-1;
        matrice[0][i]=matrice[n+1][i]=-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(copie[i][j]>0){
                rez[copie[i][j]]++;
                filll(copie[i][j],i,j);
            }
            if(matrice[i][j]==0&&drum[i][j]==0){
                for(int d=0;d<4;d++){
                    if(matrice[i+dx[d]][j+dy[d]]==1){
                        drum[i][j]=1;
                        q.push(make_pair(i,j));
                        break;
                    }
                }
            }
        }
    }
    int gata=0;
    while(!q.empty()&&!gata){
        aux=q.front();
        q.pop();
        for(int d=0;d<4;d++){
            auxx=aux;
            auxx.first+=dx[d];
            auxx.second+=dy[d];
            if(matrice[auxx.first][auxx.second]==0&&drum[auxx.first][auxx.second]==0){
                drum[auxx.first][auxx.second]=drum[aux.first][aux.second]+1;
                q.push(auxx);
            }
            if(matrice[auxx.first][auxx.second]==2){
                gata=1;
                rez[4]=drum[aux.first][aux.second];
                break;
            }
        }
    }
    g<<rez[1]<<' '<<rez[2]<<' '<<rez[3]<<' '<<rez[4]<<'\n';
    f.close();
    g.close();
}
