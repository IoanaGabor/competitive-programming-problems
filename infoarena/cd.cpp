
#include <iostream>
#include <fstream>
#define NMAX 300
#define MOD 9901

using namespace std;

ifstream f("cd.in");
ofstream g("cd.out");

int n,s,y,aux[NMAX+1],c,rez;

int main(){
    f>>n>>s;
    for(int i=1;i<=n;i++){
        f>>y>>c;
        aux[i]+=s/n+y-1;
        aux[c]-=y;
    }
    rez=1;
    for(int i=1;i<=n;i++){
        rez=(rez*aux[i])%MOD;
    }
    g<<rez;
    f.close();
    g.close();
}
