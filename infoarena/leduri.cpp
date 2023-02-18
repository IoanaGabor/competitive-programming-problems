
#include <iostream>
#include <fstream>
#define NMAX 100005
using namespace std;

int n,sir[NMAX],rez[NMAX],aux[NMAX];

int nr_pasi(){
    int contor=0;
    for(int i=1;i<n;i++){
        if(aux[i]!=rez[i]){
            for(int j=0;j<=2;j++){
                aux[i+j]=1^aux[i+j];
            }
            contor++;
        }
    }
    return contor;
}

int main(){
    ifstream f("leduri.in");
    ofstream g("leduri.out");
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        aux[i]=sir[i];
    }
    for(int i=1;i<=n;i++){
        f>>rez[i];
    }
    int sol1,sol2;
    sol1=nr_pasi();
    if(aux[n]!=rez[n]){
        sol1=100000000;
    }
    for(int i=1;i<=n;i++){
        aux[i]=sir[i];
    }
    aux[1]=aux[1]^1;
    aux[2]=aux[2]^1;
    sol2=nr_pasi()+1;
    if(aux[n]!=rez[n]){
        sol2=100000000;
    }
    g<<min(sol1,sol2);
    f.close();
    g.close();
}
