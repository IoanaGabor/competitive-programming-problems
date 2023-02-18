
#include <iostream>
#include <fstream>
#define NMAX 250
#define PMAX 1000

using namespace std;

ifstream f("gheizere.in");
ofstream g("gheizere.out");

struct gheizer{
    int x,y,r,t,d;
} gh[PMAX+5];
int n,m,p,v,e;
int dp[2][NMAX+5][NMAX+5],ok[NMAX+5][NMAX+5];

bool arevecini(int x,int y,int timp){
    return (dp[(timp-1)%2][x-1][y]||dp[(timp-1)%2][x][y-1]||dp[(timp-1)%2][x+1][y]||dp[(timp-1)%2][x][y+1]);
}

void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ok[i][j]=1;
        }
    }
}

int main(){
    f>>n>>m>>p>>v>>e;
    for(int i=1;i<=p;i++){
        f>>gh[i].x>>gh[i].y>>gh[i].r>>gh[i].t>>gh[i].d;
    }
    dp[1][v][1]=1;
    int t2;
    for(int timp=2;timp<=1000;timp++){
        init();
        for(int i=1;i<=p;i++){
            t2=(timp-1)%(gh[i].t+gh[i].d);
            if(t2>=gh[i].t){
                for(int ii=max(1,gh[i].x-gh[i].r);ii<=min(n,gh[i].x+gh[i].r);ii++){
                    for(int jj=max(1,gh[i].y-gh[i].r);jj<=min(m,gh[i].y+gh[i].r);jj++){
                        ok[ii][jj]=0;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(ok[i][j]&&arevecini(i,j,timp)){
                    dp[(timp%2)][i][j]=1;
                }else{
                    dp[(timp%2)][i][j]=0;
                }
            }
        }
        if(dp[(timp%2)][e][m]){
            g<<timp<<'\n';
            f.close();
            g.close();
            return 0;
        }
    }
}
