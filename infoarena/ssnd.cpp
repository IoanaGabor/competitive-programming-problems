
#include <iostream>
#include <fstream>
#include <bitset>
#define SQRT 1000000
#define MOD 9973

using namespace std;

ifstream f("ssnd.in");
ofstream g("ssnd.out");

int t,prime[SQRT+3],n_prime;
long long n,suma,nr_div;
bitset <SQRT+3> ciur;

void initializeaza_ciur(){
    for(long long i=2;i<=SQRT;i++){
        if(ciur[i]==0){
            prime[++n_prime]=i;
            for(long long j=i*i;j<=SQRT;j+=i){
                ciur[j]=1;
            }
        }
    }
}

void calculeaza(){
    long long putere;
    int i=1,contor;
    nr_div=1;
    suma=1;
    while(prime[i]*prime[i]<=n&&i<=n_prime&&n!=1){
        contor=0;
        putere=1;
        while(n%prime[i]==0){
            contor++;
            putere=putere*prime[i];
            n/=prime[i];
        }
        if(contor){
            putere*=prime[i];
            suma=(suma*(putere-1)/(prime[i]-1))%MOD;
            nr_div*=(contor+1);
        }
        i++;
    }
    if(n!=1){
        nr_div*=2;
        suma=(suma*(n+1))%MOD;
    }
}

int main(){
    f>>t;
    initializeaza_ciur();
    while(t--){
        f>>n;
        calculeaza();
        g<<nr_div<<' '<<suma<<'\n';
    }
    f.close();
    g.close();
}
