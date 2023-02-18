
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("orase.in");
ofstream g("orase.out");

int n,m,dist,l,r1,r2;

int main(){
    f>>m>>n;
    for(int i=1;i<=n;i++){
        f>>dist>>l;
        r1=max(r1,-dist+l);
        r2=max(r2,dist+l);
    }
    g<<r1+r2;
    f.close();
    g.close();
}
