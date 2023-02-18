#include <iostream>
#include <fstream>
#define NMAX 3000
#define MMAX 1000

using namespace std;

ifstream f("tractor2.in");
ofstream g("tractor2.out");

struct ceva{
    int t,d,c;
};

int l1,l2,n,m,p;
long long dp[NMAX+5][MMAX+5];
ceva sir1[NMAX+5],sir2[MMAX+5],var;

long long maxim(long long a,long long b){
    if(a<b){
        return b;
    }
    return a;
}

long long minim(long long a,long long b){
    if(a>b){
        return b;
    }
    return a;
}

void cursa(int x,int y){
    long long tt,cc;
    if(y+1<=m&&sir2[y+1].d==4){
        tt=sir2[y+1].t;
        cc=sir2[y+1].c;
        if(dp[x][y+1]==-1){
            dp[x][y+1]=1LL*maxim(dp[x][y],tt)+1LL*cc+1LL*p;
        }else{
            dp[x][y+1]=minim(dp[x][y+1],1LL*maxim(dp[x][y],tt)+1LL*cc+1LL*p);
        }
    }
    if(x+1<=n&&y+1<=m&&sir2[y+1].d==3){
        tt=maxim(sir2[y+1].t,sir1[x+1].t);
        cc=maxim(sir2[y+1].c,sir1[x+1].c);
        if(dp[x+1][y+1]==-1){
            dp[x+1][y+1]=1LL*maxim(dp[x][y],tt)+1LL*cc+1LL*p;
        }else{
            dp[x+1][y+1]=minim(dp[x+1][y+1],1LL*maxim(dp[x][y],tt)+1LL*cc+1LL*p);
        }
    }
    if(x+2<=n&&y+1<=m&&sir2[y+1].d==2){
        tt=maxim(sir2[y+1].t,maxim(sir1[x+1].t,sir1[x+2].t));
        cc=maxim(sir2[y+1].c,maxim(sir1[x+1].c,sir1[x+2].c));
        if(dp[x+2][y+1]==-1){
            dp[x+2][y+1]=1LL*maxim(dp[x][y],tt)+1LL*cc+1LL*p;
        }else{
            dp[x+2][y+1]=minim(dp[x+2][y+1],1LL*maxim(dp[x][y],tt)+1LL*cc+1LL*p);
        }
    }
    if(y+2<=m&&sir2[y+1].d==2&&sir2[y+2].d==2){
        tt=maxim(sir2[y+1].t,sir2[y+2].t);
        cc=maxim(sir2[y+1].c,sir2[y+2].c);
        if(dp[x][y+2]==-1){
            dp[x][y+2]=1LL*maxim(dp[x][y],tt)+1LL*cc+1LL*p;
        }else{
            dp[x][y+2]=minim(dp[x][y+2],1LL*maxim(dp[x][y],tt)+1LL*cc+1LL*p);
        }
    }
    if(x+4<=n){
        tt=maxim(maxim(sir1[x+1].t,sir1[x+2].t),maxim(sir1[x+3].t,sir1[x+4].t));
        cc=maxim(maxim(sir1[x+1].c,sir1[x+2].c),maxim(sir1[x+3].c,sir1[x+4].c));
        if(dp[x+4][y]==-1){
            dp[x+4][y]=1LL*maxim(dp[x][y],tt)+1LL*cc+1LL*p;
        }else{
            dp[x+4][y]=minim(dp[x+4][y],1LL*maxim(dp[x][y],tt)+1LL*cc+1LL*p);
        }
    }
}

int main() {
    f>>n>>m>>p;
    for(int i=1;i<=n+m;i++){
        f>>var.t>>var.d>>var.c;
        if(var.d==1){
            sir1[++l1]=var;
        }else{
            sir2[++l2]=var;
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(dp[i][j]!=-1){
                cursa(i,j);
            }
        }
    }
    g<<dp[n][m];
    f.close();
    g.close();
    return 0;
}
