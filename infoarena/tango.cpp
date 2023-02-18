#include <iostream>
#include <fstream>
#include <algorithm>
#define MOD 999983

using namespace std;

ifstream f("tango.in");
ofstream g("tango.out");

int n,k,sir[100010],aux[9];

int putere(int nr){
    int p=k/8,rez=1;
    while(p){
        if(p%2==0){
            nr=(1LL*nr*nr)%MOD;
            p/=2;
        }else{
            rez=(1LL*rez*nr)%MOD;
            p--;
        }
    }
    return rez;
}

int main()
{
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    sort(sir+1,sir+n+1);
    aux[0]=1;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=n&&sir[j]<=i;j++){
            aux[i]=(aux[i]+aux[i-sir[j]])%MOD;
        }
    }
    g<<putere(aux[8]);
    f.close();
    g.close();
    return 0;
}
