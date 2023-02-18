
#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 500
#define pi first
#define pj second

using namespace std;

ifstream f("rover.in");
ofstream g("rover.out");

int cerinta,n,gr,matrice[NMAX+5][NMAX+5],nrp[NMAX+5][NMAX+5];
deque <pair <int,int> > dq;
pair <int,int> aux;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool inside(int x,int y){
    return (1<=x&&x<=n&&1<=y&&y<=n);
}

int lee(int val){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            nrp[i][j]=-1;
        }
    }
    if(matrice[1][1]>=val){
        nrp[1][1]=0;
    }else{
        nrp[1][1]=1;
    }
    dq.push_back(make_pair(1,1));
    int x,y;
    while(!dq.empty()){
        aux=dq.front();
        dq.pop_front();
        for(int d=0;d<4;d++){
            x=aux.pi+dx[d];
            y=aux.pj+dy[d];
            if(inside(x,y)&&nrp[x][y]==-1){
                nrp[x][y]=nrp[aux.pi][aux.pj];
                if(matrice[x][y]>=val){
                    dq.push_front(make_pair(x,y));
                }else{
                    nrp[x][y]++;
                    dq.push_back(make_pair(x,y));
                }
            }
        }
    }
    return nrp[n][n];
}

int cauta(){
    int pas=1<<12,rez=0;
    while(pas){
        if(lee(rez+pas)==0){
            rez+=pas;
        }
        pas>>=1;
    }
    return rez;
}

int main(){
    f>>cerinta>>n;
    if(cerinta==1){
        f>>gr;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f>>matrice[i][j];
            }
        }
        g<<lee(gr);
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f>>matrice[i][j];
            }
        }
        g<<cauta();
    }
    f.close();
    g.close();
}
