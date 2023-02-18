
#include <iostream>
#include <fstream>
#define NMAX 100000
#define VALMAX 100000

using namespace std;

ifstream f("lautari.in");
ofstream g("lautari.out");

int n,p,q,sir[NMAX+5],fr[NMAX+5];

long long numara(int limita){
    int st=1,cnt=0;
    long long rez=0;
    for(int i=1;i<=VALMAX;i++){
        fr[i]=0;
    }
    for(int i=1;i<=n;i++){
        if(fr[sir[i]]==0){
            cnt++;
        }
        fr[sir[i]]++;
        while(cnt>limita){
            fr[sir[st]]--;
            if(fr[sir[st]]==0){
                cnt--;
            }
            st++;
        }
        rez+=(i-st+1);
    }
    return rez;
}

int main(){
    f>>n>>p>>q;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    g<<numara(q)-numara(p-1);
    f.close();
    g.close();
}
