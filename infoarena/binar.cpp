
#include <iostream>
#include <fstream>
#define NMAX 2000

using namespace std;

ifstream f("binar.in");
ofstream g("binar.out");

int n,m;
char matrice[NMAX+5][NMAX+5];
int rez[NMAX+5],zero[NMAX+5],unu[NMAX+5];

void calculeaza(int l,int r,int ind){
    if(l>=r||ind>n){
        return;
    }
    int l0=0,l1=0;
    for(int i=l;i<=r;i++){
        if(matrice[ind][rez[i]]=='0'){
            zero[++l0]=rez[i];
        }else{
            unu[++l1]=rez[i];
        }
    }
    if(l0==0||l1==0){
        calculeaza(l,r,ind+1);
        return;
    }
    for(int i=1;i<=l0;i++){
        rez[l+i-1]=zero[i];
    }
    for(int i=1;i<=l1;i++){
        rez[l+l0-1+i]=unu[i];
    }
    calculeaza(l,l+l0-1,ind+1);
    calculeaza(l+l0,r,ind+1);
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>(matrice[i]+1);
    }
    for(int i=1;i<=m;i++){
        rez[i]=i;
    }
    calculeaza(1,m,1);
    for(int i=1;i<=m;i++){
        g<<rez[i]<<' ';
    }
    f.close();
    g.close();
}
