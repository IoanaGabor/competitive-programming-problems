
#include <iostream>
#include <fstream>

using namespace std;

int a[400002];

int main() {
    ifstream f("fsb.in");
    ofstream g("fsb.out");
    int n,contor=200001,rez=0;
    char ch;
    f>>n;
    a[200001]=1;
    for(int i=1;i<=n;i++){
        f>>ch;
        if(ch=='0') {
            contor++;
        }else{
            contor--;
        }
        rez=rez+a[contor];
        a[contor]++;
    }
    g<<rez;
    f.close();
    g.close();
}
