
#include <iostream>
#include <fstream>
#include <string>
#define NMAX 200

using namespace std;

ifstream f("interesant.in");
ofstream g("interesant.out");

int p,n,dim,adim,bdim,k,lrez;
string sir[NMAX+5],rez1,rez2[NMAX+5];

bool verif(string a,string b){
    adim=a.size();
    bdim=b.size();
    if(adim>bdim||(adim==bdim&&a!=b)){
        return true;
    }
    k=0;
    for(int i=0;i<bdim;i++){
        if(a[k]==b[i]){
            k++;
        }
        if(k==adim){
            return false;
        }
    }
    return true;
}

int main(){
    f>>p>>n;
    if(p==1){
        for(int i=1;i<=n;i++){
            f>>sir[i];
            if(sir[i].size()>dim){
                dim=sir[i].size();
                rez1=sir[i];
            }else if(sir[i].size()==dim&&sir[i]<rez1){
                rez1=sir[i];
            }
        }
        g<<rez1;
    }else{
        for(int i=1;i<=n;i++){
            f>>sir[i];
        }
        int ok;
        for(int i=1;i<=n;i++){
            ok=1;
            for(int j=1;j<=n&&ok;j++){
                if(i!=j){
                    if(!verif(sir[i],sir[j])){
                        ok=0;
                    }
                }
            }
            if(ok){
                rez2[++lrez]=sir[i];
            }
        }
        g<<lrez<<'\n';
        for(int i=1;i<=lrez;i++){
            g<<rez2[i]<<'\n';
        }
    }
    f.close();
    g.close();
}
