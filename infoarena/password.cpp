
#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("password.in");
ofstream fo("password.out");

int n;
char sir[NMAX+5];
int poz[NMAX+5],lp,p;
int aux[NMAX+5],la;

int cmp(int x,int y){
    for(int i=0;i<y-x;i++){
        if(sir[(x+i)%n]<sir[(y+i)%n]){
            return x;
        }
        if(sir[(x+i)%n]>sir[(y+i)%n]){
            return y;
        }
    }
    return x;
}

int main(){
    fi>>sir;
    n=strlen(sir);
    for(int i=0;i<n;i++){
        poz[i]=i;
    }
    lp=n;
    while(lp>1){
        la=0;
        for(int i=0;i<lp;i+=2){
            if(i+1>=lp){
                aux[la++]=poz[i];
            }else{
                p=cmp(poz[i],poz[i+1]);
                aux[la++]=p;
            }
        }
        for(int i=0;i<la;i++){
            poz[i]=aux[i];
        }
        lp=la;
    }
    fo<<poz[0];
    fi.close();
    fo.close();
}
