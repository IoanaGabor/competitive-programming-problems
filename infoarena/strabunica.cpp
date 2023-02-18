
#include <iostream>
#include <fstream>
#define NMAX 200000

using namespace std;

ifstream f("strabunica.in");
ofstream g("strabunica.out");

int stiva[NMAX+5],top,sir[NMAX+5],n;
long long rez;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        while(sir[stiva[top]]>=sir[i]&&top){
            rez=max(rez,1LL*sir[stiva[top]]*(i-1-stiva[top-1]));
            top--;
        }
        stiva[++top]=i;
    }
    while(top){
        rez=max(rez,1LL*sir[stiva[top]]*(n-stiva[top-1]));
        top--;
    }
    g<<rez;
    f.close();
    g.close();
}
