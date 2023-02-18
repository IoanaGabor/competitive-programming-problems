///nu ai citit cu atentie cerinta
#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>
#include <iomanip>
#define MAXVAL 100000000
#define NMAX 50

using namespace std;

ifstream f("excursie.in");
ofstream g("excursie.out");

queue<pair<int,int> >q;
int n,m,matrice[NMAX+5][NMAX+5],li,ci,lf,cf;
double efort[NMAX+5][NMAX+5],lung[NMAX+5][NMAX+5],lmax;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

double dist(int c1,int c2){
    return (double)sqrt((c2-c1)*(c2-c1)+1);
}

long double ef(int c1,int c2){
    if(c1==c2){
        return 1;
    }else if(c1<c2){
        return (c2-c1)*dist(c1,c2);
    }else{
        return (double)(c1-c2)*dist(c1,c2)/2;
    }
}

bool inside(int x,int y){
    if(1<=x&&x<=n&&1<=y&&y<=m){
        return true;
    }
    return false;
}

void lee(){
    q.push(make_pair(li,ci));
    efort[li][ci]=0;
    lung[li][ci]=0;
    pair<int,int> aux,auxx;
    while(!q.empty()){
        aux=q.front();
        q.pop();
        for(int d=0;d<4;d++){
            auxx.first=aux.first+dx[d];
            auxx.second=aux.second+dy[d];
            if(inside(auxx.first,auxx.second)&&(efort[aux.first][aux.second]+ef(matrice[aux.first][aux.second],matrice[auxx.first][auxx.second])<efort[auxx.first][auxx.second]||(efort[aux.first][aux.second]+ef(matrice[aux.first][aux.second],matrice[auxx.first][auxx.second])==efort[auxx.first][auxx.second]&&lung[aux.first][aux.second]+dist(matrice[aux.first][aux.second],matrice[auxx.first][auxx.second])<lung[auxx.first][auxx.second]))){
                efort[auxx.first][auxx.second]=efort[aux.first][aux.second]+ef(matrice[aux.first][aux.second],matrice[auxx.first][auxx.second]);
                lung[auxx.first][auxx.second]=lung[aux.first][aux.second]+dist(matrice[aux.first][aux.second],matrice[auxx.first][auxx.second]);
                q.push(auxx);
            }
        }
    }
}

int main(){
    f>>n>>m>>lmax;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
            efort[i][j]=MAXVAL;
            lung[i][j]=MAXVAL;
        }
    }
    f>>li>>ci>>lf>>cf;
    lee();
    if(lung[lf][cf]>lmax){
        g<<-1;
    }else{
        g<<fixed<<setprecision(3)<<efort[lf][cf]<<' '<<lung[lf][cf];
    }
    f.close();
    g.close();
}
