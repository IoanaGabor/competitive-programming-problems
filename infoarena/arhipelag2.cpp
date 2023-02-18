
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arhipelag2.in");
ofstream g("arhipelag2.out");

int n,m,startx[1001],starty[1001],endx[1001],endy[1001],costx[1001],costy[1001],x,y,xrez,yrez,minim=(1<<29);
short int h[1001][1001];

void calculeaza(int nn,int start[],int endd[],int cost[]){
    int a=0,b=0;
    cost[1]=0;
    for(int i=1;i<=nn;i++){
        cost[1]+=(i-1)*start[i];
        b+=start[i];
    }
    b-=start[1];
    for(int i=2;i<=nn;i++){
        a+=endd[i-1];
        cost[i]=cost[i-1]+a-b;
        b-=start[i];
    }
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>h[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(h[i][j]==1){
                x=i;
                y=j;
                while(h[x][j]==1){
                    x++;
                }
                x--;
                while(h[i][y]==1){
                    y++;
                }
                y--;
                startx[i]++;
                starty[j]++;
                endx[x]++;
                endy[y]++;
                for(int k=i;k<=x;k++){
                    for(int l=j;l<=y;l++){
                        h[k][l]=-1;
                    }
                }
            }
        }
    }
    calculeaza(n,startx,endx,costx);
    calculeaza(m,starty,endy,costy);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(h[i][j]==0){
                if(costx[i]+costy[j]<minim){
                    minim=costx[i]+costy[j];
                    xrez=i;
                    yrez=j;
                }
            }
        }
    }
    g<<xrez<<' '<<yrez;
    f.close();
    g.close();
}
