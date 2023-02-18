
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("numar4.in");
ofstream g("numar4.out");

int parte_intreaga[2001],parte_zecimala[2001],ni,nz,a[2001],b[2001];

void constuieste_a_b(){
    f>>ni>>nz;
    for(int i=1;i<=ni;i++){
        f>>parte_intreaga[i];
    }
    for(int i=1;i<=nz;i++){
        f>>parte_zecimala[i];
    }
    int j=1;
    while(j<=ni&&parte_intreaga[j]==0){
        j++;
    }
    while(nz>=1&&parte_zecimala[nz]==0){
        nz--;
    }
    for(j;j<=ni;j++){
        a[++a[0]]=parte_intreaga[j];
    }
    for(int i=1;i<=nz;i++){
        a[++a[0]]=parte_zecimala[i];
    }
    b[0]=b[1]=1;
    while(b[0]<=nz){
        b[++b[0]]=0;
    }
}

void imparte(int nr[],int x){
    int t=0;
    for(int i=1;i<=nr[0];i++){
        nr[i]=(t*10+nr[i]);
        t=nr[i]%x;
        nr[i]/=x;
    }
}

int main(){
    constuieste_a_b();
    if(a[0]==0){
        g<<1<<'\n'<<0<<'\n'<<1<<'\n'<<1;
    }else{
        while(a[a[0]]%2==0&&b[b[0]]%2==0){
            imparte(a,2);
            imparte(b,2);
        }
        while(a[a[0]]%5==0&&b[b[0]]%5==0){
            imparte(a,5);
            imparte(b,5);
        }
        int ia=1,ib=1;
        while(a[ia]==0&&ia<a[0]){
            ia++;
        }
        while(b[ib]==0&&ib<b[0]){
            ib++;
        }
        g<<a[0]-ia+1<<'\n';
        for(int i=ia;i<=a[0];i++){
            g<<a[i];
        }
        g<<'\n';
        g<<b[0]-ib+1<<'\n';
        for(int i=ib;i<=b[0];i++){
            g<<b[i];
        }
    }
    f.close();
    g.close();
}
