
#include <iostream>
#include <fstream>
#define NMAX 25000
#define MOD 46337

using namespace std;

ifstream f("fibo2.in");
ofstream g("fibo2.out");

int n,fibonacci[NMAX+1];

int main(){
    f>>n;
    fibonacci[1]=fibonacci[2]=1;
    for(int i=3;i<=n;i++){
        fibonacci[i]=(fibonacci[i-1]+fibonacci[i-2])%MOD;
    }
    if(n%2==1){
        g<<1<<'\n'<<n/2<<' '<<n/2+1<<'\n'<<fibonacci[n/2]<<'\n'<<fibonacci[n/2+1]<<'\n'<<fibonacci[n];
    }
    if(n%2==0){
        g<<0<<'\n'<<n/2-1<<' '<<n/2+1<<'\n'<<fibonacci[n/2-1]<<'\n'<<fibonacci[n/2+1]<<'\n'<<fibonacci[n];
    }
    f.close();
    g.close();
}
