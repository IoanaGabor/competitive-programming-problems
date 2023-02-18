
#include <iostream>
#include <fstream>
#define MAXV 24*60*60

using namespace std;

ifstream f("momente.in");
ofstream g("momente.out");

int teste;
int luni[]={0,31,28,31,30,31,30,31,31,30,31,30,31},l1,l2,z1,z2,h1,h2,m1,m2,s1,s2;
int stanga[24*60*60+5],dreapta[24*60*60+5],sume_luni[15];

int din_secunde_in_ceas(int x){
    int h,m,s;
    s=x%60;
    x=x/60;
    m=x%60;
    x=x/60;
    h=x;
    return h*10000+m*100+s;
}

bool palindrom(int x){
    int ogl=0,cx=x;
    while(x){
        ogl=ogl*10+x%10;
        x/=10;
    }
    return (cx==ogl);
}

int main(){
    stanga[0]=1;
    for(int i=1;i<=MAXV;i++){
        stanga[i]=stanga[i-1]+(int)palindrom(din_secunde_in_ceas(i));
    }
    for(int i=MAXV-1;i>=0;i--){
        dreapta[i]=dreapta[i+1]+(int)palindrom(din_secunde_in_ceas(i));
    }
    for(int i=1;i<=12;i++){
        sume_luni[i]=sume_luni[i-1]+luni[i];
    }
    f>>teste;
    while(teste--){
        f>>l1>>z1>>h1>>m1>>s1>>l2>>z2>>h2>>m2>>s2;
        g<<(luni[l1]-z1+z2-1+sume_luni[l2-1]-sume_luni[l1])*stanga[MAXV]+dreapta[3600*h1+60*m1+s1]+stanga[3600*h2+60*m2+s2]<<'\n';
    }
    f.close();
    g.close();
}
