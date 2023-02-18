
#include <bits/stdc++.h>
#define NMAX 1000

using namespace std;

ifstream fi("pirati.in");
ofstream fo("pirati.out");

int n,m,q,cnt,x1,yy1,x2,yy2;
int mat[NMAX+5][NMAX+5],cod[NMAX+5][NMAX+5];
int t[NMAX*NMAX+5],lev[NMAX*NMAX+5];
char ch;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

void filll(int x,int y,int c){
    cod[x][y]=c;
    for(int i=0;i<8;i++){
        x2=x+dx[i];
        yy2=y+dy[i];
        if(cod[x2][yy2]==0&&mat[x2][yy2]==mat[x][y]){
            filll(x2,yy2,c);
        }
    }
}

void cauta_vecini(int x,int y,int c){
    for(int i=0;i<8;i++){
        x2=x+dx[i];
        yy2=y+dy[i];
        if(cod[x2][yy2]!=-NMAX*NMAX-5&&cod[x2][yy2]!=c){
            if(t[cod[x2][yy2]]==-1){
                t[cod[x2][yy2]]=c;
                lev[cod[x2][yy2]]=lev[c]+1;
            }
        }
    }
}

void read(){
    fi>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            fi>>ch;
            mat[i][j]=ch-'0';
        }
    }
}

void get_tree(){
    for(int i=0;i<=m+1;i++){
        cod[0][i]=cod[n+1][i]=-NMAX*NMAX-5;
    }
    for(int i=0;i<=n+1;i++){
        cod[i][0]=cod[i][m+1]=-NMAX*NMAX-5;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!cod[i][j]){
                ++cnt;
                filll(i,j,cnt);                
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        t[i]=-1;
    }
    t[1]=0;
    lev[1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cauta_vecini(i,j,cod[i][j]);
        }
    }    
}

int dist(int n1,int n2){
    int ret=0;
    if(lev[n1]<lev[n2]){
        swap(n1,n2);
    }
    while(lev[n1]!=lev[n2]){
        n1=t[n1];
        ret++;
    }
    while(n1!=n2){
        n1=t[n1];
        n2=t[n2];
        ret+=2;
    }
    ret/=2;
    return ret;
}

void solve(){
    int n1,n2;
    while(q--){
        fi>>x1>>yy1>>x2>>yy2;
        n1=cod[x1][yy1];
        n2=cod[x2][yy2];
        fo<<dist(n1,n2)<<'\n';
    }
}

int main(){
    read();
    get_tree();
    solve();
    fi.close();
    fo.close();
}