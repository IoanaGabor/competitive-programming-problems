
#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 1000
#define MAXVAL 1000000
#define INMAX 100000

using namespace std;

ifstream f("intrus.in");
ofstream g("intrus.out");

struct ceva{
    int x,y,cnt,maxvip;
} rez[INMAX+5];

int p,n,m,d,matrice[NMAX+5][NMAX+5],prim[NMAX+5][NMAX+5],frecventa[MAXVAL+5],nint,lrez;
bool ciur[MAXVAL+5];
void constr_ciur(){
    ciur[0]=ciur[1]=1;
    for(int i=2;i*i<=MAXVAL;i++){
        if(ciur[i]==0){
            for(int j=i+i;j<=MAXVAL;j+=i){
                ciur[j]=1;
            }
        }
    }
}

void calc(int k){
    int i,j;
    i=rez[k].x;
    j=rez[k].y;
    for(int ii=i-d/2;ii<=i+d/2;ii++){
        for(int jj=j-d/2;jj<=j+d/2;jj++){
            if(1<=ii&&ii<=n&&1<=jj&&jj<=m){
                if(prim[ii][jj]){
                    rez[k].cnt++;
                    rez[k].maxvip=max(matrice[ii][jj],rez[k].maxvip);
                }
            }
        }
    }
}

bool cmp(ceva a,ceva b){
    if(a.cnt==b.cnt){
        if(a.maxvip==b.maxvip){
            if(a.x==b.x){
                return a.y<b.y;
            }
            return a.x<b.x;
        }
        return a.maxvip>b.maxvip;
    }
    return a.cnt>b.cnt;
}

int main(){
    constr_ciur();
    f>>p>>n>>m>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
            frecventa[matrice[i][j]]++;
        }
    }
    if(p==1){
        for(int i=1;i<=MAXVAL;i++){
            if(frecventa[i]>1){
                nint+=frecventa[i];
            }
        }
        g<<nint<<'\n';
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(ciur[matrice[i][j]]==0){
                    prim[i][j]=1;
                }
                if(frecventa[matrice[i][j]]>1&&matrice[i][j]>0){
                    rez[++lrez].x=i;
                    rez[lrez].y=j;
                }
            }
        }
        for(int i=1;i<=lrez;i++){
            calc(i);
        }
        sort(rez+1,rez+lrez+1,cmp);
        if(lrez!=0){
            for(int i=1;i<=lrez;i++){
                g<<matrice[rez[i].x][rez[i].y]<<' '<<rez[i].x<<' '<<rez[i].y<<'\n';
            }
        }else{
            g<<-1<<'\n';
        }
    }
    f.close();
    g.close();
}
