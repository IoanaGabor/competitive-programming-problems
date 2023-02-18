#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("cumpanit.in");
ofstream g("cumpanit.out");

long long a,b;
int baze[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
long long rez[100000],lrez;

void bkt(int k,int se,int sb,long long nr){
    if(k>14){
        if(nr<=b&&nr>=a&&sb==se){
            rez[++lrez]=nr;
        }
        return;
    }
    bkt(k+1,se,sb,nr);
    for(int i=1;i<=43;i++){
        nr=nr*1LL*baze[k];
        if(nr>b){
            return;
        }
        bkt(k+1,se+i,sb+baze[k],nr);
    }
}

int main(){
    f>>a>>b;
    bkt(1,0,0,1);
    sort(rez+1,rez+lrez+1);
    for(int i=1;i<=lrez;i++){
        g<<rez[i]<<'\n';
    }
    f.close();
    g.close();
}
