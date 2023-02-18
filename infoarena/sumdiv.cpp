
#include <iostream>
#include <fstream>
#define NMAX 50000000
#define SQRT 8000
#define MOD 9901

using namespace std;

ifstream f("sumdiv.in");
ofstream g("sumdiv.out");

int a,b,ciur[SQRT+5],prime[SQRT+5],lprime,cnt1,cnt2;
long long expprime[SQRT+5],rez,aux1,aux2;

void init_ciur(){
    for(int i=2;i<=SQRT;i++){
        if(ciur[i]==0){
            prime[++lprime]=i;
            for(int j=2*i;j<=SQRT;j+=i){
                ciur[j]=1;
            }
        }
    }
}

void desc(int n){
    int cn=n;
    for(int i=1;prime[i]<=cn&&i<=lprime;i++){
        while(cn%prime[i]==0){
            expprime[i]++;
            cn/=prime[i];
        }
        expprime[i]=1LL*b*expprime[i];
    }
    if(cn!=1){
        prime[++lprime]=cn;
        expprime[lprime]=b;
    }
}

long long putere(long long aa,long long bb){
    long long ret=1;
    while(bb){
        if(bb%2==1){
            ret=(1LL*ret*aa)%MOD;
            bb--;
        }else{
            aa=(1LL*aa*aa)%MOD;
            bb/=2;
        }
    }
    return ret;
}

int main(){
    f>>a>>b;
    init_ciur();
    desc(a);
    rez=1;
    for(int i=1;i<=lprime;i++){
        //cout<<i<<' '<<prime[i]<<' '<<expprime[i]<<'\n';
        if(expprime[i]>0){
            //cout<<prime[i]<<' '<<expprime[i]<<'\n';
            if((prime[i]-1)%MOD==0){
                rez=(1LL*rez*(expprime[i]+1))%MOD;
            }else{
                aux1=(putere(prime[i]%MOD,expprime[i]+1)+MOD-1)%MOD;
                rez=(1LL*rez*aux1)%MOD;
                aux2=putere((prime[i]-1)%MOD,MOD-2);
                rez=(1LL*rez*aux2)%MOD;
            }
        }
    }
    if(a==0&&b==0){
        g<<0<<'\n';
    }else if(cnt1-cnt2!=0){
        g<<0<<'\n';
    }else{
        g<<rez<<'\n';
    }
    f.close();
    g.close();
}
