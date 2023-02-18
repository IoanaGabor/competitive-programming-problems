
#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 4000

using namespace std;

ifstream f("cuburi3.in");
ofstream g("cuburi3.out");

struct cub{
    int l,w,ind;
} sir[NMAX+5];
int n,bst[NMAX+5],ant[NMAX+5],lung[NMAX+5],ind,rez;

bool criteriu(cub a,cub b){
    if(a.l==b.l){
        return a.w>b.w;
    }
    return a.l>b.l;
}

void afis(int i){
    if(i==0){
        return;
    }
    afis(ant[i]);
    g<<sir[i].ind<<'\n';
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i].l>>sir[i].w;
        sir[i].ind=i;
    }
    sort(sir+1,sir+n+1,criteriu);
    rez=1;
    for(int i=1;i<=n;i++){
        ind=0;
        for(int j=1;j<i;j++){
            if(sir[i].w<=sir[j].w){
                if(bst[ind]<bst[j]){
                    ind=j;
                }
            }
        }
        bst[i]=bst[ind]+sir[i].l;
        ant[i]=ind;
        lung[i]=lung[ind]+1;
        if(bst[rez]<bst[i]){
            rez=i;
        }
    }
    g<<lung[rez]<<' '<<bst[rez]<<'\n';
    afis(rez);
    f.close();
    g.close();
}
