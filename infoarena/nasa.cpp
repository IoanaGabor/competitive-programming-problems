#include <iostream>
#include <fstream>
#include <bitset>
#define SQRTMAX 46340

using namespace std;

ifstream f("nasa.in");
ofstream g("nasa.out");

long long a,b,rez;

bitset <SQRTMAX> ciur;
int aux[SQRTMAX];

int main(){
    f>>a>>b;
    for(long long i=1;i<=SQRTMAX;i++){
        aux[i]=1;
        ciur[i]=0;
    }
    for(long long i=2;i<=SQRTMAX;i++){
        if(ciur[i]==0){
            for(long long j=i;j<=SQRTMAX;j+=i){
                ciur[j]=1;
                aux[j]=aux[j]*(-1);
            }
            for(long long j=(i*i);j<=SQRTMAX;j+=(i*i)){
                aux[j]=0;
            }
        }
    }
    for(long long i=1;i*i<=b;i++){
        rez+=aux[i]*(b/(i*i)-(a-1)/(i*i));
    }
    g<<rez;
    f.close();
    g.close();
}
