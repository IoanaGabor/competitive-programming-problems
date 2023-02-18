
#include <iostream>
#include <fstream>
#include <cstring>
#define NMAX 2000000
#define REZMAX 1000

using namespace std;

ifstream f("strmatch.in");
ofstream g("strmatch.out");

char a[NMAX+5],b[NMAX+5];
int la,lb,pi[NMAX+5],k,lrez,rez[REZMAX+5];

void init(){
    k=0;
    pi[1]=0;
    for(int i=2;i<=la;i++){
        while(k!=0&&a[k+1]!=a[i]){
            k=pi[k];
        }
        if(a[k+1]==a[i]){
            k++;
        }
        pi[i]=k;
    }
}

int main(){
    f>>a>>b;
    la=strlen(a);
    lb=strlen(b);
    for(int i=la;i>=0;i--){
        a[i+1]=a[i];
    }
    for(int i=lb;i>=0;i--){
        b[i+1]=b[i];
    }
    init();
    k=0;
    for(int i=1;i<=lb;i++){
        while(k!=0&&a[k+1]!=b[i]){
            k=pi[k];
        }
        if(a[k+1]==b[i]){
            k++;
        }
        if(k==la){
            lrez++;
            if(lrez<=REZMAX){
                rez[lrez]=i-la;
            }
            k=pi[k];
        }
    }
    g<<lrez<<'\n';
    lrez=min(lrez,REZMAX);
    for(int i=1;i<=lrez;i++){
        g<<rez[i]<<' ';
    }
    f.close();
    g.close();
}
