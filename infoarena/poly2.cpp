
#include <iostream>
#include <fstream>
#define NMAX 500
#define MOD 30103

using namespace std;

ifstream f("poly2.in");
ofstream g("poly2.out");

int n,c[NMAX+5];

int main(){
    f>>n;
    c[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            c[i]=(c[i]+c[j]*c[i-j-1])%MOD;
        }
    }
    g<<c[n];
    f.close();
    g.close();
}
