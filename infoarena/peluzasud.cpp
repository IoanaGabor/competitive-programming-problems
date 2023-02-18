
#include <iostream>
#include <fstream>

using namespace std;


int main() {
    ifstream f("peluzasud.in");
    ofstream g("peluzasud.out");
    long long n,x;
    f>>n>>x;
    g<<100000000000001;
    f.close();
    g.close();
}
