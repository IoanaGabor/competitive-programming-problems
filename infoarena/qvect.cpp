
#include <iostream>
#include <fstream>
#define NMAX 100
#define KMAX 5000
using namespace std;

ifstream f("qvect.in");
ofstream g("qvect.out");

int n,q,sir[NMAX+5][KMAX+5],tip,x,y;

int unu(int a, int b){
    int la=sir[a][0],lb=sir[b][0];
    int i=1,j=1;
    int dist=2000000011;
    while(i<=la&&j<=lb){
        if(sir[a][i]==sir[b][j]){
            return 0;
        }else if(sir[a][i]<sir[b][j]){
            dist=min(dist,(sir[b][j]-sir[a][i]));
            i++;
        }else{
            dist=min(dist,(sir[a][i]-sir[b][j]));
            j++;
        }
    }
    return dist;
}

int cauta(int k,int val){
    int rez=0,pas=1<<13;
    while(pas){
        if(rez+pas<=sir[k][0]&&sir[k][rez+pas]<val){
            rez+=pas;
        }
        pas>>=1;
    }
    return rez;
}

bool verif(int a, int b, int val){
    int mijloc=0,contor=0;
    for(int i=a;i<=b;i++){
        mijloc+=sir[i][0];
        contor+=cauta(i,val);
    }
    mijloc>>=1;
    if(contor<mijloc){
        return true;
    }
    return false;
}

int doi(int a, int b){
    int rez=-1000000000;
    unsigned int pas=1<<31;
    while(pas){
        if(verif(a,b,rez+pas)){
            rez+=pas;
        }
        pas>>=1;
    }
    return rez;
}

int main(){
    f>>n>>q;
    for(int i=1;i<=n;i++){
        f>>sir[i][0];
        for(int j=1;j<=sir[i][0];j++){
            f>>sir[i][j];
        }
    }
    while(q--){
        f>>tip>>x>>y;
        if(tip==1){
            g<<unu(x,y)<<'\n';
        }else{
            g<<doi(x,y)<<'\n';
        }
    }
    f.close();
    g.close();
}
