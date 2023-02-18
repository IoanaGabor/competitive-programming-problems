
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream f("chiftea.in");
    ofstream g("chiftea.out");
    int t,n,rad;
    f>>t;
    for(int i=1;i<=t;i++) {
        f>>n;
        rad=sqrt(n);
        if(rad*rad==n) {
            g<<4*rad<<'\n';
        }else{
            if(rad*(rad+1)<n){
                g<<4*rad+4<<'\n';
            }else{
                g<<4*rad+2<<'\n';
            }
        }
    }
    f.close();
    g.close();
}
