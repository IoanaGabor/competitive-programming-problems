#include <iostream>
#include <fstream>
#define NMAX 1000000

using namespace std;

ifstream f("ciurulet.in");
ofstream g("ciurulet.out");

char sir[NMAX+1];
int n,rez[NMAX+1],ok,unu=0;

int main(){
    f>>n;
    for(int i=2;i<=n;i++){
        f>>sir[i];
    }
    for(int i=2;i<=n;i++){
        if(sir[i]=='1'){
            for(int j=i;j<=n;j+=i){
                rez[j]=1;
            }
        }else if(sir[i]=='?'){
            ok=1;
            for(int j=2*i;j<=n;j+=i){
                if(sir[j]=='1'){
                    ok=0;
                }
            }
            if(ok){
                for(int j=i;j<=n;j+=i){
                    rez[j]=1;
                }
            }
        }
    }
    for(int i=2;i<=n;i++){
        unu+=rez[i];
    }
    g<<unu<<'\n';
    for(int i=2;i<=n;i++){
        g<<rez[i];
    }
    f.close();
    g.close();
}
