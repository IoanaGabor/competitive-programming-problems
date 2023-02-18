
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("trompeta.in");
    ofstream g("trompeta.out");
    int n,m,l_stiva=-1,k;
    char x[1000001],stiva[1000001];
    f>>n>>m;
    k=n-m;
    f>>x;
    for(int i=0;i<n;i++){
        while(l_stiva>=0 && k>0 && stiva[l_stiva]<x[i]){
            k--;
            l_stiva--;
        }
        l_stiva++;
        stiva[l_stiva]=x[i];
    }
    g<<stiva;
    f.close();
    g.close();
}
