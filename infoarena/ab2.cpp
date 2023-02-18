#include <iostream>
#include <fstream>
#define AMAX 30000

using namespace std;

ifstream f("ab2.in");
ofstream g("ab2.out");

int a,b,n,aux;
int lungimi[AMAX+1];

int main(){
    f>>n>>a>>b;
    aux=n;
    for(int i=a;i>=1;i--){
        lungimi[i]=min(b,aux-i+1);
        aux-=lungimi[i];
    }
    aux=1;
    for(int i=1;i<=a;i++){
        for(int j=aux+lungimi[i]-1;j>=aux;j--){
            g<<j<<' ';
        }
        aux+=lungimi[i];
    }
    f.close();
    g.close();
}
