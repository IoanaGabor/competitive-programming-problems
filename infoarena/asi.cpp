
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define NMAX 1000000000000
#define SQRT 1000000
#define LPUTERI 100000

using namespace std;

ifstream f("asi.in");
ofstream g("asi.out");

int q;
long long puteri[LPUTERI+5],lputeri;
long long a,b,cnt;
bool ciur[SQRT+5];

void constr_ciur(){
    for(int i=2;i<=SQRT;i++){
        if(!ciur[i]){
            long long k=1LL*i;
            while(1LL*k*i<=NMAX){
                k*=i*1LL;
                puteri[++lputeri]=k;
            }
            for(int j=2*i;j<=SQRT;j+=i){
                ciur[j]=true;
            }
        }
    }
}

int cauta(long long val){ ///cea mai mare valoare<=val
    int ret=0;
    int pas=(1<<16);
    while(pas){
        if(ret+pas<=lputeri&&puteri[ret+pas]*1LL<=val){
            ret+=pas;
        }
        pas>>=1;
    }
    return ret;
}

int main() {
    constr_ciur();
    sort(puteri+1,puteri+lputeri+1);
    f>>q;
    while(q--){
        f>>a>>b;
        cnt=cauta(b)-cauta(a-1);
        g<<cnt<<'\n';
    }
    f.close();
    g.close();
}
