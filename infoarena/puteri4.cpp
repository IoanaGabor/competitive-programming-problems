
#include <iostream>
#include <fstream>
#define MAXVAL 1000000000000000000

using namespace std;

ifstream f("puteri4.in");
ofstream g("puteri4.out");

long long ciur[70],t,x,y;

void erathostene(){
    for(int i=2;i<=65;i++){
        if(ciur[i]==0){
            for(int j=i*2;j<=65;j+=i){
                ciur[j]=1;
            }
        }
    }
}

long long putere(long long a,long long b){
    long long rez=1;
    while(b){
        if(b%2==0){
            b=b/2;
            if(MAXVAL/a<a){
                return -1;
            }
            a=a*a;
        }else{
            b--;
            if(MAXVAL/a<rez){
                return -1;
            }
            rez=rez*a;
        }
    }
    return rez;
}

long long cauta(long long val,int e){
    long long rez=0;
    long long pas=(1LL<<60),p;
    while(pas){
        if(rez+pas<val){
            p=putere(rez+pas,e);
            if(p!=-1&&p<=val){
                rez+=pas;
            }
        }
        pas>>=1;
    }
    return rez;
}

long long functie(long long val,int e){
    if(val==0){
        return 0;
    }
    int ret=1;
    long long rad;
    for(int i=2;i<=e-1;i++){
        if(ciur[i]==0){
            rad=cauta(val,i);
            if(rad==1){
                break;
            }
            ret+=rad;
            ret-=functie(rad,i);
        }
    }
    return ret;
}

int main(){
    erathostene();
    f>>t;
    while(t--){
        f>>x>>y;
        g<<functie(y,60)-functie(x-1,60)<<'\n';
    }
    f.close();
    g.close();
}
