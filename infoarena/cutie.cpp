
#include <iostream>
#include <fstream>
#define NMAX 10000

using namespace std;

ifstream f("cutie.in");
ofstream g("cutie.out");

int t,n,k,m,sfarsit[NMAX+5],bila,decizii,paritate,d1,d2;

int cauta1(){
    int pas=1<<13;
    int rez=0;
    while(pas){
        if(rez+pas<=k&&sfarsit[rez+pas]<bila){
            rez+=pas;
        }
        pas>>=1;
    }
    return rez;
}

int cauta2(){
    int pas=1<<13;
    int rez=0;
    while(pas){
        if(rez+pas<=k&&sfarsit[rez+pas]<=bila){
            rez+=pas;
        }
        pas>>=1;
    }
    return rez+1;
}

int main(){
    f>>t;
    while(t--){
        decizii=0;
        paritate=0;
        f>>n>>k>>m;
        sfarsit[1]=1;
        k++;
        for(int i=2;i<=k;i++){
            f>>sfarsit[i];
        }
        sfarsit[++k]=n;
        for(int i=1;i<=m;i++){
            f>>bila;
            d1=bila-sfarsit[cauta1()];
            d2=sfarsit[cauta2()]-bila;
            if(d1%2!=d2%2){
                decizii++;
            }else{
                paritate+=(d1%2);
            }
        }
        if(paritate%2==1||decizii%2==1){
            g<<1;
        }else{
            g<<0;
        }
    }
    f.close();
    g.close();
}
