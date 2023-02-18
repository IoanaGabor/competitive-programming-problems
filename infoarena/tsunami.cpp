
#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 1000

using namespace std;

ifstream f("tsunami.in");
ofstream g("tsunami.out");

queue <pair<int,int>> q;
int n,m,h,matrice[NMAX+5][NMAX+5],viz[NMAX+5][NMAX+5],cnt=0;
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};

bool inauntru(int i,int j){
    return (1<=i&&i<=n&&1<=j&&j<=m);
}

void numara(){
    pair <int,int> aux,auxx;
    while(!q.empty()){
        aux=q.front();
        q.pop();
        if(viz[aux.first][aux.second]){
            continue;
        }
        cnt++;
        viz[aux.first][aux.second]=1;
        for(int d=0;d<4;d++){
            auxx.first=aux.first+dx[d];
            auxx.second=aux.second+dy[d];
            if(inauntru(auxx.first,auxx.second)&&matrice[auxx.first][auxx.second]!=0&&matrice[auxx.first][auxx.second]<h){
                q.push(make_pair(auxx.first,auxx.second));
            }
        }
    }
}

int main(){
    f>>n>>m>>h;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(matrice[i][j]==0){
                for(int d=0;d<4;d++){
                    if(inauntru(i+dx[d],j+dy[d])&&matrice[i+dx[d]][j+dy[d]]!=0&&matrice[i+dx[d]][j+dy[d]]<h){
                        q.push(make_pair(i+dx[d],j+dy[d]));
                    }
                }
            }
        }
    }
    numara();
    g<<cnt;
    f.close();
    g.close();
}
