
#include <iostream>
#include <fstream>
#define NMAX 200000

using namespace std;

ifstream f("logik.in");
ofstream g("logik.out");

int n,sir[NMAX+5],sumaor,rez,ok,impar;

int main() {
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        if(sir[i]%2==0){
            if(!ok){
                ok=1;
                rez=sir[i];
            }else{
                rez&=sir[i];
            }
            if(impar){
                sumaor|=sir[i];
            }
        }else{
            if(!impar){
                impar=1;
                sumaor=sir[i];
            }else{
                sumaor|=sir[i];
                if(!ok){
                    ok=1;
                    rez=sumaor;
                }else{
                    rez&=sumaor;
                }
                sumaor=sir[i];
            }
        }
    }
    if(ok){
        g<<rez;
    }else{
        g<<-1;
    }
    f.close();
    g.close();
}
