
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cri.in");
ofstream g("cri.out");

int n,m,x,y,c[505][505],min1=8001,min2=8001,min3=8001,min4=8001,s1,s2,s3,s4,c1,c2,c3,c4,maxim,zona,cmin;

int main(){
    f>>n>>m>>x>>y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>c[i][j];
            if(i<=x&&j<=y){
                s1+=c[i][j];
                if(x%2==0&&y%2==0&&min1>c[i][j]&&(x-i+1+y-j+1)%2==1){
                    min1=c[i][j];
                }
            }
            if(i<=x&&y<=j){
                s2+=c[i][j];
                if(x%2==0&&(m-y+1)%2==0&&min2>c[i][j]&&(x-i+1+j-y+1)%2==1){
                    min2=c[i][j];
                }
            }
            if(x<=i&&j<=y){
                s3+=c[i][j];
                if((n-x+1)%2==0&&y%2==0&&min3>c[i][j]&&(i-x+1+y-j+1)%2==1){
                    min3=c[i][j];
                }
            }
            if(x<=i&&y<=j){
                s4+=c[i][j];
                if((n-x+1)%2==0&&(m-y+1)%2==0&&min4>c[i][j]&&(i-x+1+j-y+1)%2==1){
                    min4=c[i][j];
                }
            }
        }
    }
    c1=x*y;
    c2=x*(m-y+1);
    c3=(n-x+1)*y;
    c4=(n-x+1)*(m-y+1);
    if(min1!=8001){
        s1-=min1;
        c1--;
    }
    if(min2!=8001){
        s2-=min2;
        c2--;
    }
    if(min3!=8001){
        s3-=min3;
        c3--;
    }
    if(min4!=8001){
        s4-=min4;
        c4--;
    }
    maxim=max(max(s1,s2),max(s3,s4));
    cmin=2500000;
    if(s1==maxim &&cmin>c1){
        zona=1;
        cmin=c1;
    }
    if(s2==maxim &&cmin>c2){
        zona=2;
        cmin=c2;
    }
    if(s3==maxim &&cmin>c3){
        zona=3;
        cmin=c3;
    }
    if(s4==maxim &&cmin>c4){
        zona=4;
        cmin=c4;
    }
    g<<zona<<' '<<maxim<<' '<<cmin<<'\n';
    f.close();
    g.close();
}
