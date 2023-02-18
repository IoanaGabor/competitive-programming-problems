
#include <iostream>
#include <fstream>
#include <bitset>
#define SQRT 109545
#define LPRIME 10414
#define NMAX 12000000000

using namespace std;

ifstream f("frac.in");
ofstream g("frac.out");

bitset<SQRT+5> ciur;
long long n,p;
int prime[LPRIME+5],lp,fact[25],lf;

void afla_prime(){
    for(int i=2;i<=SQRT;i++){
        if(!ciur[i]){
            prime[++lp]=i;
            for(int j=2*i;j<=SQRT;j+=i){
                ciur[j]=1;
            }
        }
    }
}

void desc(long long x){
    lf=0;
    for(int i=1;prime[i]<=x&&i<=lp;i++){
        if(x%prime[i]==0){
            fact[++lf]=prime[i];
            while(x%prime[i]==0){
                x/=prime[i];
            }
        }
    }
    if(x!=1){
        fact[++lf]=x;
    }
}

long long nrfrac(long long x){
    int cnt;
    long long ret=x;
    long long div;
    for(int mask=1;mask<(1<<lf);mask++){
        div=1;
        cnt=0;
        for(int i=0;i<lf;i++){
            if((mask>>i)&1){
                div*=1LL*fact[i+1];
                cnt++;
            }
        }
        if(cnt%2==0){
            ret+=(1LL*x/div);
        }else{
            ret-=(1LL*x/div);
        }
    }
    return ret;
}

long long cauta(){
    long long pas=1LL<<61;
    long long rez=0;
    while(pas){
        if(nrfrac(rez+pas)<p){
            rez+=pas;
        }
        pas>>=1;
    }
    rez++;
    return rez;
}

int main(){
    f>>n>>p;
    afla_prime();
    desc(n);
    g<<cauta();
    f.close();
    g.close();
}
