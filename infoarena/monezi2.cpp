
#include <iostream>
#include <fstream>
#define VALMAX 100000
#define NMAX 50

using namespace std;

ifstream f("monezi2.in");
ofstream g("monezi2.out");

int n,v[NMAX+5],q,s,suma,bine[VALMAX+5];

int main(){
    f>>n;
    bine[0]=1;
    for(int i=1;i<=n;i++){
        f>>v[i];
        suma+=v[i];
        for(int j=suma;j<=VALMAX;j++){
            if(bine[j-suma]){
                bine[j]=1;
            }
        }
    }
    f>>q;
    while(q--){
        f>>s;
        if(bine[s]){
            g<<"DA"<<'\n';
        }else{
            g<<"NU"<<'\n';
        }
    }
    f.close();
    g.close();
}
