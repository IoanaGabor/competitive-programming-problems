
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("noname.in");
    ofstream g("noname.out");
    int n,p1[1001],p2[1001];
    f>>n;
    for(int i=1;i<=n;i++) {
        f>>p1[i];
    }
    for(int i=1;i<=n;i++) {
        f>>p2[i];
    }
    g<<1<<'\n';
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(n<p1[i]+p2[j]){
                g<<'1'<<' ';
            }else{
                g<<'0'<<' ';
            }
        }
        g<<'\n';
    }
    f.close();
    g.close();
}
