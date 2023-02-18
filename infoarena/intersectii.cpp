
#include <iostream>
#include <fstream>
#define NMAX 2000

using namespace std;

ifstream f("intersectii.in");
ofstream g("intersectii.out");

int n,m,frecventa[2*NMAX+5],q,x;
bool vazut[NMAX+1][NMAX+1];

int main(){
    f>>n>>m;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(vazut[i][j]==false){
                for(int d=1;i*d<n&&j*d<m;d++){
                    frecventa[d*(i+j-1)]+=4;
                    vazut[i*d][j*d]=true;
                }
            }
        }
    }
    f>>q;
    while(q--){
        f>>x;
        g<<frecventa[x]<<'\n';
    }
    f.close();
    g.close();
}
