#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 100
#define MAXVAL 20000005

using namespace std;

ifstream f("taxe2.in");
ofstream g("taxe2.out");

queue< pair<int,int> > q;
int n,matrice[NMAX+5][NMAX+5],dp[NMAX+5][NMAX+5],s;
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};

bool nu_ies(int x,int y){
    return (x>=1&&x<=n&&y>=1&&y<=n);
}

int main()
{
    f>>s>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f>>matrice[i][j];
            dp[i][j]=MAXVAL;
        }
    }
    q.push(make_pair(1,1));
    dp[1][1]=matrice[1][1];
    int x,y,x2,y2;
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            x2=x+dx[d];
            y2=y+dy[d];
            if(nu_ies(x2,y2)&&dp[x2][y2]>dp[x][y]+matrice[x2][y2]){
                dp[x2][y2]=dp[x][y]+matrice[x2][y2];
                q.push(make_pair(x2,y2));
            }
        }
    }
    if(s-dp[n][n]<0){
        g<<-1;
    }else{
        g<<s-dp[n][n];
    }
    f.close();
    g.close();
    return 0;
}
