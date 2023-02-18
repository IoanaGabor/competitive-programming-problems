
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("abx.in");
ofstream g("abx.out");

int nr_prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61},nr;
long long n,m,val,dif,sol,p;

long long putere(long long baza,int exp){
    long long rez=1;
    while(exp){
        if(exp%2==0){
            if(m/baza<baza){
                return m+1;
            }
            exp/=2;
            baza*=baza;
        }else{
            if(m/rez<baza){
                return m+1;
            }
            exp--;
            rez*=baza;
        }
    }
    return rez;
}

long long cauta(int exp){
    long long pas,rez=0,aux;
    for(pas=1;pas<n;pas<<=1);
    while(pas){
        aux=putere(rez+pas,exp);
        if(aux<=n){
            p=aux;
            rez+=pas;
        }
        pas>>=1;
    }
    return rez;
}

int main(){
    f>>nr>>m;
    while(nr--){
        f>>n;
        dif=sol=m+1;
        for(int i=0;i<=17;i++){
            val=cauta(nr_prime[i]);
            if(n-p<dif){
                dif=n-p;
                sol=p;
            }else if(n-p==dif){
                sol=min(sol,p);
            }
            p=putere(val+1,nr_prime[i]);
            if(p<=m){
                if(p-n<dif){
                    dif=p-n;
                    sol=p;
                }else{
                    sol=min(sol,p);
                }
            }
        }
        g<<sol<<'\n';
    }
    f.close();
    g.close();
}
