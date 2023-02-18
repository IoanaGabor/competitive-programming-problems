
#include <iostream>
#include <fstream>
#define baza 100000
using namespace std;

ifstream f("tamplar.in");
ofstream g("tamplar.out");

int rez[1000000];

void inmulteste(int x){
    int t=0;
    for(int i=1;i<=rez[0];i++){
        rez[i]=(t+rez[i]*x);
        t=rez[i]/baza;
        rez[i]%=baza;
    }
    while(t!=0){
        rez[++rez[0]]+=t%baza;
        t=t/baza;
    }
}

int nr_cifre(int n){
    if(n==0){
        return 1;
    }
    int contor=0;
    while(n){
        contor++;
        n/=10;
    }
    return contor;
}

int main(){
    int n;
    f>>n;
    rez[0]=rez[1]=1;
    for(int i=2;i<=n-1;i++){
        inmulteste(i);
    }
    int nr;
    g<<rez[rez[0]];
    for(int i=rez[0]-1;i>=1;i--){
        nr=nr_cifre(rez[i]);
        for(int j=1;j<=5-nr;j++){
            g<<0;
        }
        g<<rez[i];
    }
    f.close();
    g.close();
}
