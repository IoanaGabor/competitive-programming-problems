#include <iostream>
#include <fstream>
#include <cstring>
#define NMAX 255

using namespace std;

ifstream f("grad.in");
ofstream g("grad.out");

char sir[NMAX+5];
int n,aux[30],rez,gr;

void descompune(int nr){
    int i=2,contor,cnr=nr;
    while(nr!=1&&i<cnr){
        contor=0;
        while(nr%i==0){
            contor++;
            nr/=i;
        }
        aux[i]+=aux[cnr]*contor;
        i++;
    }
    if(nr!=cnr){
        aux[cnr]=0;
    }
}

int main(){
    while(f>>sir){
        n=strlen(sir);
        for(int i=1;i<=26;i++){
            aux[i]=0;
        }
        for(int i=0;i<n;i++){
            aux[sir[i]-'a'+1]+=i+1;
        }
        gr=1;
        for(int i=4;i<=26;i++){
            descompune(i);
        }
        for(int i=2;i<=26;i++){
            gr*=(aux[i]+1);
            gr%=n;
        }
        rez+=gr;
    }
    g<<rez;
    f.close();
    g.close();
}
