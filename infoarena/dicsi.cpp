
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("dicsi.in");
ofstream g("dicsi.out");

int n,p,log;

int main(){
    f>>n;
    p=1;
    while(p<=n){
        p=p*2;
        log++;
    }
    g<<log<<'\n';
    for(int i=1;i<=n;i++){
        log=0;
        p=1;
        while(p<=i){
            p=p*2;
            log++;
        }
        g<<log<<' ';
    }
    f.close();
    g.close();
}
