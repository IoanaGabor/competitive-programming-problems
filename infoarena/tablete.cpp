
#include <iostream>
#include <fstream>
#define NMAX 1000

using namespace std;

ifstream f("tablete.in");
ofstream g("tablete.out");

int n,k,rez[NMAX+1][NMAX+1],aux;

int main(){
    f>>n>>k;
    if(k%2==1){
        for(int i=1;i<=n;i++){
            if(i%2==1){
                rez[i][k]++;
            }else{
                rez[i][1]--;
            }
        }
        if(n%2==1){
            rez[1][k+1]--;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            aux++;
            rez[i][j]+=aux;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=k+1;j<=n;j++){
            aux++;
            rez[i][j]+=aux;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g<<rez[i][j]<<' ';
        }
        g<<'\n';
    }
    f.close();
    g.close();
}
