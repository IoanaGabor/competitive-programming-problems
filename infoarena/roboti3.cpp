
#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>
#define nmax 100001

using namespace std;

ifstream f("roboti3.in");
ofstream g("roboti3.out");

int v,n,sir[2*nmax];
int contor=1,maxim=-1;
int rez[nmax],stanga,dreapta;
int main() {
    f>>v;
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    if(v==1){
        for(int i=1;i<=n;i++){
            sir[n+i]=sir[i];
        }
        for(int i=1;i<=2*n;i++){
            if(sir[i]>sir[i+1]){
                if(maxim<contor){
                    maxim=contor;
                }
                contor=1;
            }else{
                contor++;
            }
        }
        if(maxim<contor){
            maxim=contor;
        }
        g<<maxim<<'\n';
    }else{
        sort(sir+1,sir+n+1);
        rez[1]=sir[1];
        rez[n+1]=sir[1];
        stanga=1;
        dreapta=n+1;
        int i=2;
        while(i<=n){
            if(rez[stanga]<=rez[dreapta]){
                stanga++;
                rez[stanga]=sir[i];
            }else{
                dreapta--;
                rez[dreapta]=sir[i];
            }
            i++;
        }
    }
    for(int i=1;i<=n;i++){
        g<<rez[i]<<' ';
    }
    f.close();
    g.close();
}
