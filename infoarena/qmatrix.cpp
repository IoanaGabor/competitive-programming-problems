
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("qmatrix.in");
ofstream g("qmatrix.out");

int n,linii[10][4005],coloane[10][4005],p,k;

int cauta_linii(){
    if(k>linii[p][n]){
        return 0;
    }
    int pas=1<<12,i=0;
    while(pas){
        if(i+pas<=n&&linii[p][i+pas]<k){
            i+=pas;
        }
        pas>>=1;
    }
    i++;
    return i;
}

int cauta_coloane(){
    if(k>coloane[p][n]){
        return 0;
    }
    int pas=1<<12,i=0;
    while(pas){
        if(i+pas<=n&&coloane[p][i+pas]<k){
            i+=pas;
        }
        pas>>=1;
    }
    i++;
    return i;
}


int main(){
    int x,y,q,cif;
    f>>n>>x>>y>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cif=(x*i+y*j+1)%10;
            x=y;
            y=cif;
            linii[cif][i]++;
            coloane[cif][j]++;
        }
    }
    for(int i=0;i<=9;i++){
        for(int j=2;j<=n;j++){
            linii[i][j]+=linii[i][j-1];
            coloane[i][j]+=coloane[i][j-1];
        }
    }
    char ch;
    while(q--){
        f>>ch>>k>>p;
        if(ch=='C'){
            g<<cauta_coloane()<<'\n';
        }else{
            g<<cauta_linii()<<'\n';
        }
    }
    f.close();
    g.close();
}
