
#include <iostream>
#include <fstream>
#include <cstring>
#include <bitset>

using namespace std;

ifstream f("roboti2.in");
ofstream g("roboti2.out");

int n,m,p,t,x,y,prec[155];
bitset <200> copaci[200];

int aux[155][155];

int calculeaza(int x){
    int contor=0;
    memset(aux,0,sizeof(aux));
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(copaci[i][j]==1){
                if(i>x&& j<=m-x){
                    aux[i][j]=1+aux[i-x][j+x];
                }else{
                    aux[i][j]=1;
                }
            }else{
                aux[i][j]=max(aux[i][j+1],aux[i-1][j]);
            }
            contor=max(contor,aux[i][j]);
        }
    }
    return contor;
}

void precalculeaza(){
    int l=min(n,m);
    for(int i=1;i<=l;i++){
        prec[i]=calculeaza(i);
    }
}

int cauta(int x){
    int pas=1<<7,r=0,l=min(n,m);
    while(pas){
        if(r+pas<=l&&prec[r+pas]>x){
            r+=pas;
        }
        pas>>=1;
    }
    r++;
    return r;
}

int main(){
    f>>p>>n>>m>>t;
    while(t--){
        f>>x>>y;
        copaci[x][y]=1;
    }
    if(p==1){
        f>>x;
        g<<calculeaza(x);
    }else{
        f>>y;
        precalculeaza();
        while(y--){
            f>>x;
            g<<cauta(x)<<'\n';
        }
    }
    f.close();
    g.close();
}
