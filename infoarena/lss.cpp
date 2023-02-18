
#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 100000

using namespace std;

ifstream f("lss.in");
ofstream g("lss.out");

int n,k,sir[NMAX+5];
long long rez;

int main(){
    f>>k>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    sort(sir+1,sir+n+1);
    for(int i=1;i<=n;i++){
        rez+=1LL*max(1,(sir[i]-1)%k+1-i+1);
    }
    g<<rez;
    f.close();
    g.close();
}

