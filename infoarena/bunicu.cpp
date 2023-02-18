
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("bunicu.in");
    ofstream g("bunicu.out");
    int t,n;
    char ch;
    int sir[1001];
    f>>t;
    for(int k=1;k<=t;k++) {
        f>>n;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                f>>ch;
                if(i==j){
                    sir[i]=!(ch-'0');
                }
            }
        }
        for(int i=1;i<=n;i++) {
            g<<sir[i];
        }
        g<<'\n';
    }
    f.close();
    g.close();
}
