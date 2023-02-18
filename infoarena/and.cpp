
#include <iostream>
#include <fstream>
#define nmax 100000

using namespace std;

int n,sir[nmax+1];

int main(){
    ifstream f("and.in");
    ofstream g("and.out");
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    int aux,maxim=0,contor=0;
    for(int i=0;i<=30;i++){
        contor=0;
        aux=(1<<i);
        for(int j=1;j<=n;j++){
            if(aux&sir[j]){
                contor++;
            }else{
                maxim=max(maxim,contor);
                contor=0;
            }
        }
        maxim=max(maxim,contor);
    }
    g<<maxim;
    f.close();
    g.close();
}
