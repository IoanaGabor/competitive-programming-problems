
#include <iostream>
#include <fstream>
#include <cmath>
#define NMAX 4000001

using namespace std;

ifstream f("tg.in");
ofstream g("tg.out");

bool numarat_deja[NMAX];
int n,k;
long long contor;
int main(){

    f>>n;
    for(int i=1;i<=n;i++){
        if(!numarat_deja[i]){
            for(int j=1;i*j*j<=n;j++){
                numarat_deja[i*j*j]=1;
                contor+=(j-1);
            }
        }
    }
    g<<contor;
    f.close();
    g.close();
}
