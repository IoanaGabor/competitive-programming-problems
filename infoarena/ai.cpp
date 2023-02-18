
#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 1000
#define pi first
#define pj second

using namespace std;

ifstream f("ai.in");
ofstream g("ai.out");

int n,xt,yt,xs1,ys1,xs2,ys2,xr1,yr1,xr2,yr2,k,xo,yo,matrice[NMAX+5][NMAX+5],drum[NMAX+5][NMAX+5],rez1,cnt,cnt2;
int dist11,dist12,dist21,dist22;
queue <pair <int,int> > q;
pair <int,int> aux,auxx;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void unu(){
    f>>n>>xt>>yt>>xs1>>ys1>>xs2>>ys2>>xr1>>yr1>>xr2>>yr2>>k;
    for(int i=1;i<=k;i++){
        f>>xo>>yo;
        matrice[xo][yo]=-1;
    }
    matrice[xt][yt]=16;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(matrice[i][j]==0){
                rez1=max(rez1,cnt);
                cnt=0;
                if((min(xt,xs1)<=i&&i<=max(xt,xs1))&&(min(yt,ys1)<=j&&j<=max(yt,ys1))&&(i-xt)*(ys1-yt)==(j-yt)*(xs1-xt)){
                    matrice[i][j]+=1;
                }
                if((min(xt,xs2)<=i&&i<=max(xt,xs2))&&(min(yt,ys2)<=j&&j<=max(yt,ys2))&&(i-xt)*(ys2-yt)==(j-yt)*(xs2-xt)){
                    matrice[i][j]+=2;
                }
            }
            if(matrice[i][j]==-1){
                cnt++;
            }else{
                rez1=max(rez1,cnt);
                cnt=0;
            }
            if(matrice[j][i]==-1){
                cnt2++;
            }else{
                rez1=max(rez1,cnt2);
                cnt2=0;
            }
        }
        rez1=max(rez1,cnt);
        cnt=0;
        rez1=max(rez1,cnt2);
        cnt2=0;
    }
    g<<rez1<<'\n';

}

bool ok(int i,int j){
    return (1<=i&&i<=n&&1<=j&&j<=n&&drum[i][j]==0&&matrice[i][j]!=16&&matrice[i][j]!=-1);
}

int calc_dist(int xs,int ys,int val){
    q.push(make_pair(xs,ys));
    while(!q.empty()){
        aux=q.front();
        q.pop();
        for(int d=0;d<4;d++){
            auxx.pi=aux.pi+dx[d];
            auxx.pj=aux.pj+dy[d];
            if(ok(auxx.pi,auxx.pj)){
                drum[auxx.pi][auxx.pj]=drum[aux.pi][aux.pj]+1;
                q.push(auxx);
                if(matrice[auxx.pi][auxx.pj]==1||matrice[auxx.pi][auxx.pj]==3){
                    if(val==1){
                        dist11=min(dist11,drum[auxx.pi][auxx.pj]);
                    }else{
                        dist21=min(dist21,drum[auxx.pi][auxx.pj]);
                    }
                }
                if(matrice[auxx.pi][auxx.pj]==2||matrice[auxx.pi][auxx.pj]==3){
                    if(val==1){
                        dist12=min(dist12,drum[auxx.pi][auxx.pj]);
                    }else{
                        dist22=min(dist22,drum[auxx.pi][auxx.pj]);
                    }
                }
            }
        }
    }
}

void doi(){
    dist11=dist12=dist21=dist22=(1<<29);
    calc_dist(xr1,yr1,1);
    while(!q.empty()){
        q.pop();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            drum[i][j]=0;
        }
    }
    calc_dist(xr2,yr2,2);
    g<<min(max(dist11,dist22),max(dist12,dist21));
}

int main(){
    unu();
    doi();
    f.close();
    g.close();
}
