
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("suma.in");
    ofstream g("suma.out");
    long long n,p;
    f>>n>>p;
    n=n%p;
    g<<((n*(n+1)*(n-1))/3)%p;
    f.close();
    g.close();
}
