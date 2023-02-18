
#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 250

using namespace std;

ifstream f("muzeu.in");
ofstream g("muzeu.out");

int n,rez[NMAX+5][NMAX+5];
char mat[NMAX+5][NMAX+5];
queue <pair<int,int> >q;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};

void lee(){
    pair<int,int> aux;
    int x,y;
    while(!q.empty()){
        aux=q.front();
        q.pop();
        for(int d=0;d<4;d++){
            x=aux.first+dx[d];
            y=aux.second+dy[d];
            if(rez[x][y]!=-2&&rez[x][y]>rez[aux.first][aux.second]+1){
                rez[x][y]=rez[aux.first][aux.second]+1;
                q.push(make_pair(x,y));
            }
        }
    }
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>(mat[i]+1);
    }
    for(int i=0;i<=n+1;i++){
        rez[i][0]=rez[0][i]=rez[n+1][i]=rez[i][n+1]=-2;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mat[i][j]=='#'){
                rez[i][j]=-2;
            }else if(mat[i][j]=='P'){
                rez[i][j]=0;
                q.push(make_pair(i,j));
            }else{
                rez[i][j]=NMAX*NMAX;
            }
        }
    }
    lee();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(rez[i][j]==NMAX*NMAX){
                rez[i][j]=-1;
            }
            g<<rez[i][j]<<' ';
        }
        g<<'\n';
    }
    f.close();
    g.close();
}
