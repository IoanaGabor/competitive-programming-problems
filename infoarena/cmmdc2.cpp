
#include <iostream>
#include <fstream>

using namespace std;

long long n,k,x,frecventa[1000001],maxim=-1,contor,cmmdc;

int main(){
    ifstream f("cmmdc2.in");
    ofstream g("cmmdc2.out");
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>x;
        frecventa[x]++;
        maxim=max(maxim,x);
    }
    for(int i=maxim;i>=1;i--){
        contor=0;
        for(int j=i;j<=maxim;j=j+i){
            contor=contor+frecventa[j];
        }
        if(contor>=k){
            cmmdc=i;
            break;
        }
    }
    g<<cmmdc<<'\n';
    for(int i=(maxim/cmmdc)*cmmdc;i>=1&&k;i=i-cmmdc){
        while(frecventa[i]&&k){
            g<<i<<' ';
            frecventa[i]--;
            k--;
        }
    }
    f.close();
    g.close();
}
