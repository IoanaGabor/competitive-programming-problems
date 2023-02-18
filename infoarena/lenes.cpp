#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXVAL (1LL<<31)-1
#define NMAX 500

using namespace std;

ifstream f("lenes.in");
ofstream g("lenes.out");

int cerinta,m,n,k1,k2,matrice[NMAX+5][NMAX+5],rez1=MAXVAL,sume[NMAX+5][NMAX+5],aux,cost1[NMAX+5],cost2[NMAX+5];

int cost_popas(int j,int k){
    int c1,c2,suma=sume[j][m];
    c1=1;
    c2=1;
    for(int i=1;i<=k;i++){
        if(matrice[j-1][c1]<matrice[j+1][c2]){
            suma+=matrice[j-1][c1];
            c1++;
        }else{
            suma+=matrice[j+1][c2];
            c2++;
        }
    }
    return suma;
}

int modul(int x){
    if(x<0){
        return -x;
    }
    return x;
}

int calculeaza(int x,int y){
    int suma=0;
    if(modul(x-y)==1){
        if((x==1&&k1!=0)||(x==n&&k1!=0)){
            return MAXVAL;
        }
        if((y==n&&k2!=0)||(y==1&&k2!=0)){
            return MAXVAL;
        }
        suma=sume[x][m]+sume[y][m];
        if(x<y){
            suma+=sume[x-1][k1]+sume[y+1][k2];
        }else{
            suma+=sume[y-1][k2]+sume[x+1][k1];
        }
        return suma;
    }else if(modul(x-y)>2){
        suma=cost1[x]+cost2[y];
        return suma;
    }else if(modul(x-y)==2){
        int l1,l2,l3,v1,v2,v3,c1=1,c2=1,c3=1,vmin;
        suma=sume[x][m]+sume[y][m];
        l1=min(x,y)-1;
        l2=(x+y)/2;
        l3=max(x,y)+1;
        for(int i=1;i<=k1+k2;i++){
            v1=matrice[l1][c1];
            v2=matrice[l2][c2];
            v3=matrice[l3][c3];
            if((x<y&&c1>k1)||(x>y&&c1>k2)){
                v1=MAXVAL;
            }
            if((x<y&&c3>k2)||(x>y&&c1>k2)){
                v3=MAXVAL;
            }
            vmin=min(v1,min(v2,v3));
            suma+=vmin;
            if(vmin==v1){
                c1++;
            }else if(vmin==v2){
                c2++;
            }else{
                c3++;
            }
        }
        return suma;
    }
}

int main(){
    f>>cerinta>>m>>n>>k1>>k2;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            f>>matrice[j][i];
        }
    }
    for(int i=1;i<=n;i++){
        sort(matrice[i]+1,matrice[i]+m+1);
        for(int j=1;j<=m;j++){
            sume[i][j]=sume[i][j-1]+matrice[i][j];
        }
    }
    for(int i=0;i<=n+1;i++){
        matrice[i][0]=MAXVAL;
        matrice[i][m+1]=MAXVAL;
    }
    for(int i=0;i<=m+1;i++){
        matrice[0][i]=MAXVAL;
        matrice[n+1][i]=MAXVAL;
    }
    for(int i=1;i<=n;i++){
        cost1[i]=cost_popas(i,k1);
        cost2[i]=cost_popas(i,k2);
    }
    if(cerinta==1){
        for(int i=1;i<=n;i++){
            rez1=min(cost1[i],rez1);
        }
        g<<rez1;
    }else{
        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=n;i2++){
                if(i1==i2){
                    continue;
                }
                aux=calculeaza(i1,i2);
                rez1=min(rez1,aux);
            }
        }
        g<<rez1;
    }
}
