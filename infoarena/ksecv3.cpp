
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("ksecv3.in");
    ofstream g("ksecv3.out");
    long long n,k,sir[100001],suma=0;
    f>>n>>k;
    for(int i=1;i<=n;i++) {
        f>>sir[i];
        suma=suma+sir[i];
    }
    if(suma%k!=0){
        g<<-1;
        f.close();
        g.close();
        return 0;
    }else{
        suma=suma/k;
    }
    long long suma_secventa=0,sir_indici[100001],l=0;
    for(int i=1;i<=n;i++) {
        suma_secventa=suma_secventa+sir[i];
        if(suma_secventa==suma){
            l++;
            sir_indici[l]=i;
            suma_secventa=0;
        }else if(suma_secventa>suma){
            g<<-1;
            f.close();
            g.close();
            return 0;
        }
    }
    for(int i=1;i<=l;i++) {
        g<<sir_indici[i]<<' ';
    }
    f.close();
    g.close();
}
