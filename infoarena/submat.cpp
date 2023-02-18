
#include <iostream>
#include <fstream>
#include <algorithm>
#define MMAX 1000

using namespace std;

ifstream f("submat.in");
ofstream g("submat.out");

int n,m,val,sir[MMAX+5],rez=-1;

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>val;
            sir[i]+=(1-val);
        }
    }
    sort(sir+1,sir+n+1);
    for(int j=n;j>=1;j--){
        rez=max(rez,sir[j]*(n-j+1));
    }
    g<<rez;
    f.close();
    g.close();
}
