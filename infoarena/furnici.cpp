
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("furnici.in");
    ofstream g("furnici.out");
    long long l,n,pozitie,timp=0;
    char ch;
    f>>l>>n;
    for(int i=1;i<=n;i++) {
        f>>pozitie>>ch;
        if(ch=='D'){
            timp=max(timp,l-pozitie);
        }else{
            timp=max(timp,pozitie);
        }
    }
    g<<timp;
    f.close();
    g.close();
}
