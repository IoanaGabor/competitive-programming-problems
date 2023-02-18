#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 100000
#define KMAX 100

using namespace std;

ifstream f("mostenire3.in");
ofstream g("mostenire3.out");

int n,k,sir[NMAX+5],sume[NMAX+5],minim;
pair <int,int> rez[KMAX+5];

void citeste(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        sume[i]=sume[i-1]+sir[i];
    }
}

bool verifica(int nr){
    int contor=0,ind=0;
    for(int i=1;i<=n;i++){
        if(sume[i]-sume[ind]>=nr){
            ind=i;
            contor++;
        }
    }
    if(contor>=k){
        return true;
    }
    return false;
}

void cauta(){
    int pas=1<<29;
    while(pas){
        if(verifica(minim+pas)){
            minim+=pas;
        }
        pas>>=1;
    }
}

bool criteriu1(pair <int,int> a,pair<int,int> b){
    if(a.first<b.first){
        return true;
    }
    return false;
}

bool criteriu2(pair <int,int> a,pair<int,int> b){
    if(a.second<b.second){
        return true;
    }
    return false;
}


int main(){
    citeste();
    cauta();
    g<<minim<<'\n';
    int ind=0,contor=0;
    for(int i=1;i<=n&&contor<k-1;i++){
        if(sume[i]-sume[ind]>=minim){
            rez[++contor].first=sume[i]-sume[ind];
            rez[contor].second=i;
            ind=i;
        }
    }
    rez[k].first=sume[n]-sume[ind];
    rez[k].second=n;
    sort(rez+1,rez+k+1,criteriu1);
    for(int i=1;i<=k;i++){
        rez[i].first=k-i+1;
    }
    sort(rez+1,rez+k+1,criteriu2);
    rez[0].second=0;
    for(int i=1;i<=k;i++){
        g<<rez[i].first<<' '<<rez[i].second-rez[i-1].second<<'\n';
    }
    f.close();
    g.close();
}
