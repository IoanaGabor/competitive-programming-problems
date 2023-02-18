
#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,a,b;
    f>>n;
    for(int i=1;i<=n;i++){
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }
    f.close();
    g.close();
}
