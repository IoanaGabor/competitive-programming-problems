
#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

ifstream f("cmmmc.in");
ofstream g("cmmmc.out");

bitset <45000> ciur;
int n,prime[45000],l_prime=0,puteri[45000],baze[45000],l_puteri,a_min,b_min;

void ciurul_lui_erathostene(){
    for(int i=2;i<=45000;i++){
        if(ciur[i]==0){
            prime[++l_prime]=i;
            for(int j=2*i;j<=45000;j+=i){
                ciur[j]=1;
            }
        }
    }
}

void descompune_n(){
    int i=1,p=0;
    while(n!=1&&prime[i]*prime[i]<=n){
        p=0;
        while(n%prime[i]==0){
            p++;
            n=n/prime[i];
        }
        if(p>0){
            puteri[++l_puteri]=p;
            baze[l_puteri]=prime[i];
        }
        i++;
    }
    if(n>1){
        puteri[++l_puteri]=1;
        baze[l_puteri]=n;
    }
}

int rez_a(){
    int rez=1;
    for(int i=1;i<=l_puteri;i++){
        rez*=(2*puteri[i]+1);
    }
    rez++;
    rez/=2;
    return rez;
}

int putere(int x,int y){
    int rez=1;
    while(y){
        if(y%2==0){
            x=x*x;
            y=y/2;
        }else{
            y--;
            rez=rez*x;
        }
    }
    return rez;
}

void rez_b(){
    int suma_min=2000000000,m=1<<l_puteri,a,b,bit;
    for(int i=0;i<m;i++){
        a=1;
        b=1;
        for(int j=0;j<l_puteri;j++){
            bit=(1<<j)&i;
            if(bit==0){
                a*=putere(baze[j+1],puteri[j+1]);
            }else{
                b*=putere(baze[j+1],puteri[j+1]);
            }
        }
        if(a+b<suma_min){
            suma_min=a+b;
            a_min=a;
            b_min=b;
        }
    }
}

int main(){
    int k;
    f>>k;
    ciurul_lui_erathostene();
    while(k--){
        f>>n;
        descompune_n();
        g<<rez_a()<<' ';
        rez_b();
        g<<min(a_min,b_min)<<' '<<max(b_min,a_min)<<'\n';
        l_puteri=0;
    }

    f.close();
    g.close();
}

