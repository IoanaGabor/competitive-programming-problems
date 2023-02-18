
#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 1000
#define MAXVAL 40000

using namespace std;

ifstream f("taxa.in");
ofstream g("taxa.out");

int n,m,xs,ys,xe,ye,mat[NMAX+5][NMAX+5],cost[NMAX+5][NMAX+5];
int dx[]={0,1,0,-1,1,-1,1,-1};
int dy[]={1,0,-1,0,1,1,-1,-1};
queue<pair<int,int>> q[MAXVAL+5];

bool inauntru(int x,int y){
    return (1<=x&&x<=n&&1<=y&&y<=m);
}

void filll(int x,int y,int c){
    int x2,y2;
    if(cost[x][y]==-1){
        cost[x][y]=c;
        for(int d=0;d<8;d++){
            x2=x+dx[d];
            y2=y+dy[d];
            if(inauntru(x2,y2)){
                if(mat[x][y]==mat[x2][y2]){
                    filll(x2,y2,c);
                }else{
                    q[c+mat[x][y]*mat[x2][y2]].push(make_pair(x2,y2));
                }
            }
        }
    }
}

int main(){
    f>>n>>m>>xs>>ys>>xe>>ye;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>mat[i][j];
            cost[i][j]=-1;
        }
    }
    q[0].push(make_pair(xs,ys));
    for(int i=0;i<=MAXVAL;i++){
        int x,y;
        while(!q[i].empty()){
            x=q[i].front().first;
            y=q[i].front().second;
            q[i].pop();
            if(cost[x][y]==-1){
                filll(x,y,i);
            }
            if(cost[xe][ye]!=-1){
                g<<cost[xe][ye];
                f.close();
                g.close();
                return 0;
            }
        }
    }
    f.close();
    g.close();
}
