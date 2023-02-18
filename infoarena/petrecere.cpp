
#include <iostream>
#include <fstream>
#define NMAX 2000
#define NCIF 3000
#define BAZA 10000

using namespace std;

ifstream f("petrecere.in");
ofstream g("petrecere.out");

int s1[NCIF+5],s2[NCIF+5],s[NCIF+5],n;

void adunare(int rez[NCIF+5],int a[NCIF+5],int b[NCIF+5]){
    if(a[0]<b[0]){
        for(int i=a[0]+1;i<=b[0];i++){
            a[i]=0;
        }
        a[0]=b[0];
    }else{
        for(int i=b[0]+1;i<=a[0];i++){
            b[i]=0;
        }
        b[0]=a[0];
    }
    int t=0;
    for(int i=1;i<=a[0];i++){
        rez[i]=a[i]+b[i]+t;
        t=rez[i]/BAZA;
        rez[i]%=BAZA;
    }
    rez[0]=a[0];
    while(t){
        rez[++rez[0]]=t%BAZA;
        t=t/BAZA;
    }
}

void inmultire(int a[NCIF+5],int val){
    int t=0;
    for(int i=1;i<=a[0];i++){
        a[i]=a[i]*val+t;
        t=a[i]/BAZA;
        a[i]%=BAZA;
    }
    while(t){
        a[++a[0]]=t%BAZA;
        t=t/BAZA;
    }
}

void copiaza(int a[NCIF+5],int b[NCIF+5]){
    for(int i=1;i<=b[0];i++){
        a[i]=b[i];
    }
    a[0]=b[0];
}

void afiseaza(int a[NCIF+5]){
    g<<a[a[0]];
    for(int i=a[0]-1;i>=1;i--){
        if(a[i]>=BAZA/10){
            g<<a[i];
        }else if(a[i]>BAZA/100){
            g<<"0"<<a[i];
        }else if(a[i]>BAZA/1000){
            g<<"00"<<a[i];
        }else if(a[i]>BAZA/10000){
            g<<"000"<<a[i];
        }else{
            g<<"0000";
        }
    }
}

int main(){
    f>>n;
    if(n==1){
        g<<1<<'\n';
    }else if(n==2){
        g<<2;
    }else{
        s1[0]=1;
        s1[1]=1;
        s2[0]=1;
        s2[1]=1;
        for(int i=3;i<=n+1;i++){
            inmultire(s2,i-2);
            adunare(s,s1,s2);
            copiaza(s2,s1);
            copiaza(s1,s);
        }
    }
    afiseaza(s1);
    f.close();
    g.close();
}
