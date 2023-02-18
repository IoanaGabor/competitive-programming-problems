
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("cpal.in");
    ofstream g("cpal.out");
    int contor=0,nr,nu_este_zero=0;
    for(int i=1;i<=10;i++) {
        for(int j=1;j<=9;j++) {
            f>>nr;
            if(nr%2==1){
                contor++;
            }
            nu_este_zero=nu_este_zero+nr;
        }
        if(contor<=1 && nu_este_zero){
            g<<"1\n";
        }else{
            g<<"0\n";
        }
        contor=0;
        nu_este_zero=0;
    }
    f.close();
    g.close();
}
