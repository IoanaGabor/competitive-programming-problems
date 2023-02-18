#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define NMAX 150

using namespace std;

ifstream f("castel.in");
ofstream g("castel.out");

int n,m,k,matrice[NMAX+5][NMAX+5],cheie[NMAX*NMAX+5],xs,ys,cnt,viz[NMAX*NMAX+5];
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
queue<int> q;
vector <int> deblocheaza[NMAX*NMAX+5];
void bfs(){
    cheie[k]=1;
    q.push(k);
    viz[k]=1;
    int x,y,val,xn,yn;
    while(!q.empty()){
        val=q.front();
        q.pop();
        x=(val+m-1)/m;
        y=val-(x-1)*m;
        if(!cheie[val]){
            cheie[val]=1;
            for(size_t i=0;i<deblocheaza[val].size();i++){
                q.push(deblocheaza[val][i]);
            }
        }
        for(int d=0;d<4;d++){
            xn=x+dx[d];
            yn=y+dy[d];
            if(1<=xn&&xn<=n&&1<=yn&&yn<=m&&viz[m*(xn-1)+yn]==0){
                viz[m*(xn-1)+yn]=1;
                if(cheie[matrice[xn][yn]]==1){
                    q.push(m*(xn-1)+yn);
                }else{
                    deblocheaza[matrice[xn][yn]].push_back(m*(xn-1)+yn);
                }
            }
        }
    }
}

int main(){
    f>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
        }
    }
    bfs();
    for(int i=1;i<=n*m;i++){
        cnt+=cheie[i];
    }
    g<<cnt;
    f.close();
    g.close();
}
