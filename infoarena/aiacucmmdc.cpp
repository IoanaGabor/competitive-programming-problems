
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("aiacucmmdc.in");
    ofstream g("aiacucmmdc.out");
    long long n,p,nr,contor=0,rez=0;
    f>>n>>p;
    for(int i=1;i<=n;i++) {
        f>>nr;
        if(nr%p==0) {
            contor++;
        }else{
            rez=rez+contor*(contor+1)/2;
            contor=0;
        }
    }
    rez=rez+contor*(contor+1)/2;
    g<<rez;
    f.close();
    g.close();
}
