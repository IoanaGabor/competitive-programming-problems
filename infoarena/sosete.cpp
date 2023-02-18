
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("sosete.in");
ofstream g("sosete.out");

int c[1005],n[1005],rez[2005];

void citire(){
    string numar;
    f>>numar;
    n[0]=numar.length();
    for(int i=1;i<=n[0];i++){
        n[n[0]-i+1]=numar[i-1]-'0';
    }
    f>>numar;
    c[0]=numar.length();
    for(int i=1;i<=c[0];i++){
        c[c[0]-i+1]=numar[i-1]-'0';
    }
}

void inmultire_cu_numar_mic(int x,int nr[]){
    int t=0;
    for(int i=1;i<=nr[0];i++){
        nr[i]=nr[i]*x+t;
        t=nr[i]/10;
        nr[i]%=10;
    }
    while(t){
        nr[++nr[0]]=t%10;
        t/=10;
    }
}

void scade_cifra(int nr[],int cif){
    if(nr[1]>=cif){
        nr[1]-=cif;
    }else{
        nr[1]=10+nr[1]-cif;
        int i=2;
        while(nr[i]==0){
            nr[i]=9;
            i++;
        }
        nr[i]--;
    }
}

void inmulteste_numere_mari(){
    for(int i=1;i<=n[0];i++){
        for(int j=1;j<=c[0];j++){
            rez[i+j-1]+=n[i]*c[j];
        }
    }
    rez[0]=n[0]+c[0]-1;
    int t=0;
    for(int i=1;i<=rez[0];i++){
        rez[i]=rez[i]+t;
        t=rez[i]/10;
        rez[i]%=10;
    }
    while(t){
        rez[++rez[0]]=t;
        t/=10;
    }
}

void aduna_cifra(int nr[],int x){
    if(nr[1]+x<10){
        nr[1]+=x;
    }else{
        nr[1]+=x;
        int t=nr[1]/10;
        nr[1]%=10;
        for(int i=2;i<=nr[0];i++){
            nr[i]+=t;
            t=nr[i]/10;
            nr[i]%=10;
        }
        while(t){
            nr[++nr[0]]=t;
            t=t/10;
        }
    }
}

void afis_rez(){
    for(int i=rez[0];i>=1;i--){
        g<<rez[i];
    }
}

int main(){
    citire();
    inmultire_cu_numar_mic(2,n);
    scade_cifra(n,5);
    inmulteste_numere_mari();
    aduna_cifra(rez,1);
    afis_rez();
    f.close();
    g.close();
}
