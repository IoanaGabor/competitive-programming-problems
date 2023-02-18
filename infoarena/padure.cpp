
#include <iostream>
#include <fstream>
#include <deque>
#define MAXVAL (1LL<<31)-1
#define NMAX 1000

using namespace std;

ifstream f("padure.in");
ofstream g("padure.out");

struct ceva{
    int x,y,c;
} aux,auxx;
int n,m,xa,ya,xc,yc,copaci[NMAX+5][NMAX+5],cost[NMAX+5][NMAX+5];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
deque<ceva>dq;

int main(){
    f>>n>>m>>xa>>ya>>xc>>yc;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>copaci[i][j];
            cost[i][j]=MAXVAL;
        }
    }
    for(int i=0;i<=n+1;i++){
        copaci[i][m+1]=copaci[i][0]=-1;
    }
    for(int j=0;j<=m+1;j++){
        copaci[0][j]=copaci[n+1][j]=-1;
    }
    aux.x=xa;
    aux.y=ya;
    aux.c=0;
    cost[xa][ya]=0;
    dq.push_back(aux);
    while(!dq.empty()){
        aux=dq.front();
        aux.c=cost[aux.x][aux.y];
        dq.pop_front();
        for(int d=0;d<4;d++){
            auxx.x=aux.x+dx[d];
            auxx.y=aux.y+dy[d];
            if(copaci[auxx.x][auxx.y]!=-1){
                if(copaci[auxx.x][auxx.y]!=copaci[aux.x][aux.y]&&cost[auxx.x][auxx.y]>aux.c+1){
                    auxx.c=aux.c+1;
                    cost[auxx.x][auxx.y]=auxx.c;
                    dq.push_back(auxx);
                }else if(copaci[auxx.x][auxx.y]==copaci[aux.x][aux.y]&&cost[auxx.x][auxx.y]>aux.c){
                    auxx.c=aux.c;
                    cost[auxx.x][auxx.y]=auxx.c;
                    dq.push_front(auxx);
                }
            }
        }
    }
    g<<cost[xc][yc];
    f.close();
    g.close();
}
