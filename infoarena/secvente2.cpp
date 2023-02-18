
#include <iostream>
#include <fstream>
#define NMAX 1000001

using namespace std;

ifstream f("secvente2.in");
ofstream g("secvente2.out");

int n,aux[NMAX],x,stanga,dreapta,maxim;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>x;
        stanga=x;
        dreapta=x;
        if(aux[x-1]!=0){
            stanga=aux[x-1];
        }
        if(aux[x+1]!=0){
            dreapta=aux[x+1];
        }
        aux[stanga]=dreapta;
        aux[dreapta]=stanga;
        maxim=max(maxim,dreapta-stanga+1);
        g<<maxim<<'\n';
    }
    f.close();
    g.close();
}
