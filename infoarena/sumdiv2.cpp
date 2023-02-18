#include <iostream>
#include <fstream>
#define NMAX 1000000

using namespace std;

ifstream f("sumdiv2.in");
ofstream g("sumdiv2.out");

unsigned long long rez[NMAX+5],a,b,n;

int main() {
    for(int i=1;i<=NMAX;i++){
        rez[i]+=rez[i-1];
        for(int j=i;j<=NMAX;j+=i){
            rez[j]+=i;
        }
    }
    f>>n;
    while(n--){
        f>>a>>b;
        g<<rez[b]-rez[a-1]<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
