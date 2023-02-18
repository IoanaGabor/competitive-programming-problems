

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

long long divizori[1000000],n=0,nr;

long long cmmdc(long long a,long long b){
    long long c;
    while(b) {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

long long cmmmc(long long a,long long b) {
    return a*b/cmmdc(a,b);
}

void afla_divizorii(){
    for(int i=1;i*i<=nr;i++) {
        if(nr%i==0) {
            if(i*i==nr){
                n++;
                divizori[n]=i;
            }else{
                n++;
                divizori[n]=i;
                n++;
                divizori[n]=nr/i;
            }
        }
    }
}

int main() {
    ifstream f("perechi.in");
    ofstream g("perechi.out");
    f>>nr;
    afla_divizorii();
    int aux;
    sort(divizori+1,divizori+n+1);
    for(int i=1;i<=n;i++) {
        cout<<divizori[i]<<' ';
    }
    cout<<'\n';
    int contor=0,j;
    for(int i=1;i<=n;i++) {
        j=n;
        while(divizori[i]*divizori[j]>=nr && i<=j) {
            if(cmmmc(divizori[i],divizori[j])==nr) {
                contor++;
            }
            j--;
        }
    }
    g<<contor;
    f.close();
    g.close();
}
