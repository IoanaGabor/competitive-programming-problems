
#include <iostream>
#include <fstream>
#define nmax 16001

using namespace std;

ifstream f("transport.in");
ofstream g("transport.out");

int n,k,sir[nmax],suma=0,maxim=-1;

bool ok(int volum){
    int contor=0,transport=0;
    for(int i=1;i<=n;i++){
        if(transport+sir[i]<=volum){
            transport=transport+sir[i];
        }else{
            contor++;
            transport=sir[i];
        }
    }
    if(transport){
        contor++;
    }
    if(contor<=k){
        return 1;
    }
    return 0;
}

int cautare(int stanga,int dreapta){
    int mijloc;
    while(stanga!=dreapta){
        mijloc=(stanga+dreapta)/2;
        if(ok(mijloc)){
            dreapta=mijloc;
        }else{
            stanga=mijloc+1;
        }
    }
    return stanga;
}

int main(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        maxim=max(maxim,sir[i]);
        suma=suma+sir[i];
    }
    g<<cautare(maxim,suma);
    f.close();
    g.close();
}
