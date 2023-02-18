
#include <iostream>
#include <fstream>
#define NMAX 100000

using namespace std;

ifstream f("sortare2.in");
ofstream g("sortare2.out");

int fr[NMAX+2],n,val,cnt;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>val;
        if(!fr[val-1]){
            cnt++;
        }
        fr[val]++;
    }
    g<<cnt-1;
}
