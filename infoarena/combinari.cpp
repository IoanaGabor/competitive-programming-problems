
#include <iostream>
#include <fstream>
#define NMAX 18

using namespace std;

ifstream f("combinari.in");
ofstream g("combinari.out");

int n,m;
int sir[NMAX+5];

void bkt(int k){
    if(k==m){
        for(int i=1;i<=m;i++){
            g<<sir[i]<<' ';
        }
        g<<'\n';
    }else{
        for(int i=sir[k]+1;i<=n-(m-k-1);i++){
            sir[k+1]=i;
            bkt(k+1);
        }
    }
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n-m+1;i++){
        sir[1]=i;
        bkt(1);
    }
    f.close();
    g.close();
}
