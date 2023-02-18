
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream f("balulbobocilor.in");
    ofstream g("balulbobocilor.out");
    double v1,v2,d,v,inutil;
    f>>d>>v1>>inutil>>inutil>>v2>>inutil>>inutil>>v;
    double rez=v*d/(v1+v2);
    g<<setprecision(6)<<fixed<<rez;
    f.close();
    g.close();
}
