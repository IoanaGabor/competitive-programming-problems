
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("harta5.in");
ofstream g("harta5.out");

int n,m,cerinta,k,harta[1505][1505],linii[1505],coloane[1505];

struct patrat{
    int i1,j1,i2,j2;
};

patrat sir[1001];

void unu(){
    int l1,l2,contor=0;
    int imax=0,smax=0;
    for(int i=1;i<=k;i++){
        l1=sir[i].i2-sir[i].i1+1;
        l2=sir[i].j2-sir[i].j1+1;
        if(l1==l2 && l1*l2>smax){
            smax=l1*l2;
            imax=i;
        }
    }
    g<<smax<<' ';
    for(int i=1;i<=k;i++){
        l1=sir[i].i2-sir[i].i1+1;
        l2=sir[i].j2-sir[i].j1+1;
        if(i!=imax&& l1<=((sir[imax].i2-sir[imax].i1+1)-2)&& l2<=((sir[imax].i2-sir[imax].i1+1)-2)){
            contor++;
        }
    }
    g<<contor<<'\n';
}

void marcheaza(int x){
    int x1=sir[x].i1,y1=sir[x].j1,x2=sir[x].i2,y2=sir[x].j2;
    for(int i=x1;i<=x2;i++){
        harta[i][y1]=harta[i][y2]=1;
    }
    for(int i=y1;i<=y2;i++){
        harta[x1][i]=harta[x2][i]=1;
    }
}

void doi(){
    for(int i=1;i<=k;i++){
        marcheaza(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            linii[i]+=harta[i][j];
            coloane[j]+=harta[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(linii[i]==0){
            i++;
            while(linii[i]==0&& i<=n){
                i++;
            }
            i--;
        }
        for(int j=1;j<=m;j++){
            if(coloane[j]==0){
                j++;
                while(coloane[j]==0&& j<=m){
                    j++;
                }
                j--;
            }
            g<<harta[i][j]<<' ';
        }
        g<<'\n';
    }
}

int main(){
    f>>cerinta>>n>>m>>k;
    for(int i=1;i<=k;i++){
        f>>sir[i].i1>>sir[i].j1>>sir[i].i2>>sir[i].j2;
    }
    if(cerinta==1){
        unu();
    }else{
        doi();
    }
    f.close();
    g.close();
}
