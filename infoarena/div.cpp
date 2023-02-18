
#include <iostream>
#include <fstream>
#define NMAX 5000

using namespace std;

ifstream f("div.in");
ofstream g("div.out");

int k,n,numar[NMAX+5],p[NMAX+5],u[NMAX+5],zece[NMAX+5],xrez=-1,yrez,x,y,gata;
char ch;

bool ok(){
    if(x==1&&y<n&&numar[y+1]==0){
        return false;
    }
    if((p[x-1]*zece[n-y]+u[y+1])%k==0){
        return true;
    }
    return false;
}

bool compara(){
    int aux1,aux2,l=n-y+x-1;
    for(int i=1,aux1=1,aux2=1;i<=l;i++,aux1++,aux2++){
        if(aux1==xrez){
            aux1=yrez+1;
        }
        if(aux2==x){
            aux2=y+1;
        }
        if(numar[aux1]<numar[aux2]){
            return true;
        }else if(numar[aux1]>numar[aux2]){
            return false;
        }
    }
    return false;
}

int main(){
    f>>k;
    while(f>>ch&&ch!='\n'){
        numar[++n]=ch-'0';
    }
    zece[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=(p[i-1]*10+numar[i])%k;
        zece[i]=(zece[i-1]*10)%k;
    }
    for(int i=n;i>=1;i--){
        u[i]=(numar[i]*zece[n-i]+u[i+1])%k;
    }
    if(p[n]==0){
        g<<0<<' '<<0;
        f.close();
        g.close();
    }
    for(int i=1;i<=n&&!gata;i++){
     for(int j=1;j+i-1<=n;j++){
            x=j;
            y=j+i-1;
            if(ok()){
                if(xrez==-1){
                    xrez=x;
                    yrez=y;
                    gata=1;
                }else{
                    if(compara()){
                        xrez=x;
                        yrez=y;
                    }
                }
            }
        }
    }
    g<<xrez<<' '<<yrez;
    f.close();
    g.close();
}
