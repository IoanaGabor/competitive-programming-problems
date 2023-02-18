
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("inundatie.in");
ofstream g("inundatie.out");

long long n,m,q;
long long sir[90005],aux[90005];

long long cauta(long long a){
    long long pas=1<<30,rez=0;
    while(pas){
        if(rez+pas<=n&&sir[rez+pas]<=a){
            rez+=pas;
        }
        pas/=2;
    }
    return rez;
}

int main(){
    f>>n>>m;
    n*=m;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    sort(sir+1,sir+n+1);
    for(int i=1;i<=n;i++){
        aux[i]=aux[i-1]+sir[i];
    }
    f>>q;
    int j;
    long long x,rez;
    for(int i=1;i<=q;i++){
        f>>x;
        x--;
        if(x<=0){
            g<<0<<'\n';
        }else{
            j=cauta(x);
            rez=aux[j];
            rez+=(n-j)*x;
            g<<rez<<'\n';
        }
    }
    f.close();
    g.close();
}
