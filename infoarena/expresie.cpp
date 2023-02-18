
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream f("expresie.in");
    ofstream g("expresie.out");
    long long n,sir[1001],suma=0,suma_max=0;
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        suma=suma+sir[i];
    }
    for(int i=1;i<=n-2;i++){
        suma_max=max(suma_max,suma-sir[i]-sir[i+1]-sir[i+2]+sir[i]*sir[i+1]*sir[i+2]);
    }
    for(int i=1;i<=n-3;i++){
        for(int j=i+2;j<=n-1;j++){
            suma_max=max(suma_max,suma-sir[i]-sir[i+1]-sir[j]-sir[j+1]+sir[i]*sir[i+1]+sir[j]*sir[j+1]);
        }
    }
    g<<suma_max;
    f.close();
    g.close();
}
