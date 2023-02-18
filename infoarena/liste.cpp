#include <iostream>
#include <fstream>
#include <bitset>
#define LMAX 100000
#define MAXVAL 120
#define NMAX 10

using namespace std;

ifstream f("liste.in");
ofstream g("liste.out");

int l,n,x,top;
bitset <MAXVAL> fr,zero,stiva[LMAX],aux;

int main(){
    f>>l;
    while(l--){
        f>>n;
        fr=zero;
        while(n--){
            f>>x;
            fr[x]=1;
        }
        stiva[++top]=fr;
        aux=(stiva[top]&stiva[top-1]);
        while((top>=2) && aux!=zero){
            stiva[top-1]=(stiva[top-1]|stiva[top]);
            top--;
            aux=(stiva[top]&stiva[top-1]);
        }
    }
    g<<top;
    f.close();
    g.close();
}
