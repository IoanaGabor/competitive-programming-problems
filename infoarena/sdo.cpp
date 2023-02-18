#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 3000000

using namespace std;

ifstream f("sdo.in");
ofstream g("sdo.out");

int n,sir[NMAX+1],k;

int main(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    nth_element(sir+1,sir+k,sir+n+1);
    g<<sir[k];
    f.close();
    g.close();
}
