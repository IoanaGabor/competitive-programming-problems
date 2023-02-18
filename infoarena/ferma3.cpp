
#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 500

using namespace std;

ifstream f("ferma3.in");
ofstream g("ferma3.out");

int v,n,m,matrice[NMAX+5][NMAX+5],viz[NMAX+5][NMAX+5],cnt_cel[NMAX+5][NMAX+5],parc_nr[NMAX+5][NMAX+5],cntparc,maxim,lvec,xrez,yrez,lrez;
char ch;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct aux{
    int first,second,third;
} vec[10];

bool criteriu(aux a,aux b){
    return a.second>b.second;
}

void filll(int x,int y,int nr,int &c){
    if(matrice[x][y]==nr&&viz[x][y]==0){
        c++;
        viz[x][y]=1;
        parc_nr[x][y]=cntparc;
        for(int i=0;i<4;i++){
            filll(x+dx[i],y+dy[i],nr,c);
        }
    }
}

void filll2(int x,int y,int nr,int cnt){
    if(matrice[x][y]==nr&&viz[x][y]==1){
        viz[x][y]=-1;
        cnt_cel[x][y]=cnt;
        for(int i=0;i<4;i++){
            filll2(x+dx[i],y+dy[i],nr,cnt);
        }
    }
}

int main(){
    f>>v>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>ch;
            matrice[i][j]=ch-'a'+1;
        }
    }
    int cnt;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(viz[i][j]==0){
                cnt=0;
                cntparc++;
                filll(i,j,matrice[i][j],cnt);
                filll2(i,j,matrice[i][j],cnt);
                maxim=max(maxim,cnt);
            }
        }
    }
    if(v==1){
        g<<maxim;
    }else{
        maxim=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                lvec=0;
                for(int d=0;d<4;d++){
                    if(i+dx[d]<=n&&i+dx[d]>=1&&j+dy[d]<=m&&j+dy[d]>=1){
                       vec[++lvec].first=matrice[i+dx[d]][j+dy[d]];
                       vec[lvec].second=cnt_cel[i+dx[d]][j+dy[d]];
                       vec[lvec].third=parc_nr[i+dx[d]][j+dy[d]];
                       for(int dd=1;dd<lvec;dd++){
                            if(vec[lvec].first==vec[dd].first&&vec[dd].third==vec[lvec].third){
                                lvec--;
                                break;
                            }
                       }
                    }
                }
                for(int k=lvec;k>=1;k--){
                    for(int kk=1;kk<k;kk++){
                        if(vec[k].first==vec[kk].first){
                            vec[kk].second+=vec[k].second;
                            for(int kkk=k+1;kkk<=lvec;kkk++){
                                vec[kkk-1]=vec[kkk];
                            }
                            lvec--;
                            break;
                        }
                    }
                }
                sort(vec+1,vec+lvec+1,criteriu);
                for(int k=1;k<=lvec;k++){
                    if(matrice[i][j]!=vec[k].first){
                        if(vec[k].second+1>maxim){
                            xrez=i;
                            yrez=j;
                            maxim=vec[k].second+1;
                            lrez=vec[k].first;
                        }
                        break;
                    }
                }
            }
        }
        g<<xrez<<' '<<yrez<<'\n'<<char(lrez+'a'-1);
    }
    f.close();
    g.close();
}
