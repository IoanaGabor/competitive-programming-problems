
#include <iostream>
#include <fstream>
#define NMAX 20000

using namespace std;

ifstream f("text3.in");
ofstream g("text3.out");

string sir[NMAX+5];
int n,p,u,l['z'-'a'+5],poz['z'-'a'+5],prec[NMAX+5],maxim,inceput,rez[NMAX+5];

int main(){
    while(f>>sir[++n]&&sir[n]!=""){
        p=sir[n][0]-'a';
        u=sir[n][sir[n].size()-1]-'a';
        if(l[u]<l[p]+1){
            l[u]=l[p]+1;
            prec[n]=poz[p];
            poz[u]=n;
            if(l[u]>maxim){
                maxim=l[u];
                inceput=n;
            }
        }
    }
    n--;
    g<<n<<'\n'<<n-maxim<<'\n';
    for(int i=1;i<=maxim;i++){
        rez[i]=inceput;
        inceput=prec[inceput];
    }
    for(int i=maxim;i>=1;i--){
        g<<sir[rez[i]]<<'\n';
    }
    f.close();
    g.close();
}
