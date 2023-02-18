
#include <iostream>
#include <fstream>
#define NMAX 10000005

using namespace std;

ifstream f("sipet.in");
ofstream g("sipet.out");

int teste,p1,p2,p3,n,aux,rrez,arez,brez,crez,orez;

pair <int,int> sir[NMAX];
bool ceva[NMAX];

bool e_prim(int x){
    if(x%2==0){
        return false;
    }
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    f>>teste;
    while(teste--){
        f>>n>>p1;
        p2=p1+1;
        while(!e_prim(p2)){
            p2++;
        }
        p3=p2+1;
        while(!e_prim(p3)){
            p3++;
        }
        for(int a=0;a*p1<=n;a++){
            for(int b=0;a*p1+b*p2<=n&&b<=p1;b++){
                ceva[a*p1+b*p2]=true;
                sir[a*p1+b*p2].first=a;
                sir[a*p1+b*p2].second=b;
            }
        }
        rrez=-1;
        for(int r=0;r<p1&&rrez==-1;r++){
            for(int c=0;c*p3+r<=n&&c<=p1;c++){
                aux=n-c*p3-r;
                if(ceva[aux]&&(rrez==-1||(rrez!=-1&&arez+brez+crez<sir[aux].first+sir[aux].second+c))){
                    arez=sir[aux].first;
                    brez=sir[aux].second;
                    crez=c;
                    rrez=r;
                }
            }
        }
        g<<arez+brez+crez<<' '<<arez<<' '<<brez<<' '<<crez<<' '<<rrez<<'\n';
        for(int a=0;a*p1<=n;a++){
            for(int b=0;a*p1+b*p2<=n&&b<=p1;b++){
                ceva[a*p1+b*p2]=false;
            }
        }
    }
    f.close();
    g.close();
}
