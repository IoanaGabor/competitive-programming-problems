
#include <iostream>
#include <fstream>
#define NMAX 1000000

using namespace std;

ifstream f("xspe.in");
ofstream g("xspe.out");

int n,sir[NMAX+5],stiva[NMAX+5],top,ind[NMAX+5];

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    stiva[++top]=1;
    for(int i=2;i<=n;i++){
        while(top&&sir[i]<sir[stiva[top]]){
            ind[stiva[top]]=i;
            top--;
        }
        stiva[++top]=i;
    }
    for(int i=1;i<=n;i++){
        g<<sir[i]+sir[ind[i]]<<' ';
    }
    f.close();
    g.close();
}
