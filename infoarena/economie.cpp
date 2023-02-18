
#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 1000
#define MAXVAL 50000

using namespace std;

ifstream f("economie.in");
ofstream g("economie.out");

int n,sir[NMAX+5],ok[MAXVAL+5],rez[NMAX+5],lrez;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    sort(sir+1,sir+n+1);
    for(int i=1;i<=n;i++){
        if(!ok[sir[i]]){
            rez[++lrez]=sir[i];
            ok[sir[i]]=1;
            for(int j=1;j<=MAXVAL-sir[i];j++){
                if(ok[j]){
                    ok[j+sir[i]]=1;
                }
            }
        }
    }
    g<<lrez<<'\n';
    for(int i=1;i<=lrez;i++){
        g<<rez[i]<<'\n';
    }
}
