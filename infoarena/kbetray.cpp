
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream f("kbetray.in");
    ofstream g("kbetray.out");
    int n,k,a,b,minim[100001],maxim[100001];
    long long rez=0;
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>a>>b;
        minim[i]=min(a,b);
        maxim[i]=max(a,b);
        rez=rez+maxim[i];
    }
    sort(maxim+1,maxim+n+1);
    sort(minim+1,minim+n+1);
    reverse(minim+1,minim+n+1);
    for(int i=1;i<=n && k>0;i++){
        if(maxim[i]<minim[i]){
            k--;
            rez=rez+(minim[i]-maxim[i]);
        }
    }
    g<<rez;
    f.close();
    g.close();
}
