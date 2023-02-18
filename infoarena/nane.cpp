
#include <iostream>
#include <fstream>
#define NMAX 100000

using namespace std;

ifstream f("nane.in");
ofstream g("nane.out");

int n,k,sir[NMAX+5],sume[35];
long long cnt;

bool verif(){
    int ret=0;
    for(int i=0;i<30;i++){
        if(sume[i]>0){
            ret++;
        }
        if(ret>k){
            return false;
        }
    }
    return true;
}

void muta(int ii,int semn){
    for(int i=0;i<30;i++){
        sume[i]+=((sir[ii]>>i)&1)*semn;
    }
}

int main() {
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    int j=1;
    for(int i=1;i<=n;i++){
        muta(i,1);
        while(j<=i&&!verif()){
            muta(j,-1);
            j++;
        }
        cnt+=(i-j+1);
    }
    g<<cnt;
    f.close();
    g.close();
}
