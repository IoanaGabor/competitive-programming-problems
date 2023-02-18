
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("tabela.in");
ofstream g("tabela.out");

int n,m,r1,r2,p,rez;

int main(){
    f>>n>>m;
    n--;
    m--;
    p=1;
    while(n||m){
        r1=n%2;
        n=n/2;
        r2=m%2;
        m=m/2;
        if(r1!=r2){
            rez+=p;
        }
        p*=2;
    }
    g<<rez;
    f.close();
    g.close();
}
