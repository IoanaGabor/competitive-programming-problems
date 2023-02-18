
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("magic2.in");
ofstream g("magic2.out");

int n,patrat[101][101],suma_linii[101],suma_coloane[101],ok=1,aux,l1,l2,c1,c2,v1,v2,frecventa[10001],suma_magica;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f>>patrat[i][j];
            suma_linii[i]+=patrat[i][j];
            suma_coloane[j]+=patrat[i][j];
        }
        if(i>1 && suma_linii[i]!=suma_linii[i-1]){
            ok=0;
        }
    }
    if(ok==1){
        g<<"magic"<<'\n';
        f.close();
        g.close();
        return 0;
    }
    g<<"nu este magic"<<'\n';
    for(int i=1;i<=n;i++){
        frecventa[suma_linii[i]]++;
        frecventa[suma_coloane[i]]++;
    }
    for(int i=1;i<=10000;i++){
        if(frecventa[i]>frecventa[suma_magica]){
            suma_magica=i;
        }
    }
    for(int i=n;i>=1;i--){
        if(suma_linii[i]!=suma_magica){
            l2=l1;
            l1=i;
        }
    }
    for(int i=n;i>=1;i--){
        if(suma_coloane[i]!=suma_magica){
            c2=c1;
            c1=i;
        }
    }
    if(l2){
        if(c2){
            if(suma_linii[l1]!=suma_coloane[c1]){
                swap(c1,c2);
            }
        }else{
            c2=c1;
        }
    }else{
        l2=l1;
        if(c2==0){
            c2=c1;
        }
    }
    if(l1!=l2 && c1!=c2){
        v1=suma_magica-(suma_linii[l1]-patrat[l1][c1]);
        v2=suma_magica-(suma_linii[l2]-patrat[l2][c2]);
    }else{
        if(l1!=l2){
            v1=suma_magica-(suma_linii[l1]-patrat[l1][c1]);
            v2=suma_magica-(suma_linii[l2]-patrat[l2][c2]);
        }else{
            v1=suma_magica-(suma_coloane[c1]-patrat[l1][c1]);
            v2=suma_magica-(suma_coloane[c2]-patrat[l2][c2]);
        }
    }
    g<<l1<<' '<<c1<<' '<<l2<<' '<<c2<<'\n';
    g<<v1<<' '<<v2<<'\n';
    f.close();
    g.close();
}
