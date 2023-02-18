
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream f("superp.in");
ofstream g("superp.out");

struct ceva{
    int prefix,frecventa[11];
};
int t;
char num[15];
int fr[11],rez;
queue <ceva> q;

void copiaza(int a[11],int b[11]){
    for(int i=0;i<=9;i++){
        a[i]=b[i];
    }
}

void initq(){
    ceva aux;
    if(fr[2]){
        aux.prefix=2;
        copiaza(aux.frecventa,fr);
        aux.frecventa[2]--;
        aux.frecventa[2]=aux.frecventa[4]=aux.frecventa[6]=aux.frecventa[8]=aux.frecventa[0]=0;
        q.push(aux);
    }
    if(fr[3]){
        aux.prefix=3;
        copiaza(aux.frecventa,fr);
        aux.frecventa[3]--;
        aux.frecventa[2]=aux.frecventa[4]=aux.frecventa[6]=aux.frecventa[8]=aux.frecventa[0]=0;
        q.push(aux);
    }
    if(fr[5]){
        aux.prefix=5;
        copiaza(aux.frecventa,fr);
        aux.frecventa[5]--;
        aux.frecventa[2]=aux.frecventa[4]=aux.frecventa[6]=aux.frecventa[8]=aux.frecventa[0]=0;
        q.push(aux);
    }
    if(fr[7]){
        aux.prefix=7;
        copiaza(aux.frecventa,fr);
        aux.frecventa[7]--;
        aux.frecventa[2]=aux.frecventa[4]=aux.frecventa[6]=aux.frecventa[8]=aux.frecventa[0]=0;
        q.push(aux);
    }
}

bool prim(long long x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

void rezolva(){
    initq();
    ceva aux,auxx;
    while(!q.empty()){
        aux=q.front();
        rez=max(rez,aux.prefix);
        q.pop();
        for(int i=1;i<=9;i+=2){
            if(aux.frecventa[i]){
                if(prim(aux.prefix*10+i)){
                    copiaza(auxx.frecventa,aux.frecventa);
                    auxx.prefix=aux.prefix*10+i;
                    auxx.frecventa[i]--;
                    q.push(auxx);
                }
            }
        }
    }
}

int main(){
    f>>t;
    while(t--){
        f>>num;
        for(int i=0;i<=9;i++){
            fr[i]=0;
        }
        rez=0;
        for(int i=0;num[i];i++){
            fr[num[i]-'0']++;
        }
        rezolva();
        g<<rez<<'\n';
    }
    f.close();
    g.close();
}
