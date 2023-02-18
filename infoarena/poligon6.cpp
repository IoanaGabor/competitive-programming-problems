
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream f("poligon6.in");
ofstream g("poligon6.out");

int n,r[1000001],rez[1000010],l_rez;

struct punct{
    int c1,c2,ip;
};

punct tinte[1000010];
int lt;

void adauga_tinte(int raza){
    int j;
    for(int i=1;i*i<=raza*raza;i++){
        j=sqrt(raza*raza-i*i);
        if(i>j){
            break;
        }
        if(j*j==(raza*raza-i*i)){
            tinte[++lt].ip=raza;
            tinte[lt].c1=i;
            tinte[lt].c2=j;
        }
    }
}

bool criteriu(punct a,punct b){
    return a.c1*b.c2<b.c1*a.c2;
}

bool verif(punct a,punct b){
    return a.c1*b.c2==b.c1*a.c2;
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>r[i];
        adauga_tinte(r[i]);
    }
    sort(tinte+1,tinte+lt+1,criteriu);
    for(int i=1;i<=lt;i++){
        if(i==1||!verif(tinte[i-1],tinte[i])){
            rez[++l_rez]=1;
        }else{
            rez[l_rez]++;
        }
    }
    g<<lt*2<<'\n'<<l_rez*2<<'\n';
    for(int i=1;i<=l_rez;i++){
        g<<rez[i]<<' ';
    }
    for(int i=l_rez;i>=1;i--){
        g<<rez[i]<<' ';
    }
    f.close();
    g.close();
}
