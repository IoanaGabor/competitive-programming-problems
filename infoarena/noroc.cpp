
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream f("noroc.in");
    ofstream g("noroc.out");
    float x,m;
    f>>x>>m;
    if(x>=m) {
        g<<fixed<<setprecision(7)<<(float)0;
    }else{
        g<<fixed<<setprecision(7)<<1-x/m;
    }
    f.close();
    g.close();
}
