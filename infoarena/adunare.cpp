
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("adunare.in");
    ofstream g("adunare.out");
    unsigned long long a,b;
    f>>a>>b;
    g<<a+b;
    f.close();
    g.close();
}
