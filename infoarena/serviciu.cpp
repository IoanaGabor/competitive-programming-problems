
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("serviciu.in");
    ofstream g("serviciu.out");
    int n,acasa,serviciu,maxim=-1;
    f>>n;
    for(int i=1;i<=n;i++) {
        f>>acasa>>serviciu;
        if(acasa>serviciu){
            int aux=acasa;
            acasa=serviciu;
            serviciu=aux;
        }
        if(maxim<min(serviciu-acasa,2*n-serviciu+acasa)){
            maxim=min(serviciu-acasa,2*n-serviciu+acasa);
        }
    }
    g<<maxim;
    f.close();
    g.close();
}
