
#include <iostream>
#include <fstream>
#define MAXVAL 250000
#define BAZA 12

using namespace std;

ifstream f("zimeria.in");
ofstream g("zimeria.out");

int cerinta,n,complitera[35],frecventa[MAXVAL+5],aux,cnt;
char comp[15],cuv[10];

int getnumber(){
    int nr=0,putere=1;
    for(int i=4;i>=0;i--){
        nr=nr+putere*complitera[cuv[i]-'a'];
        putere=putere*BAZA;
    }
    return nr;
}

void getcuv(int nr){
    for(int i=4;i>=0;i--){
        cuv[i]=comp[(nr%BAZA)];
        nr=nr/BAZA;
    }
}

int main(){
    f>>cerinta>>n;
    f>>comp;
    for(int i=0;i<=30;i++){
        complitera[i]=-1;
    }
    for(int i=0;i<BAZA;i++){
        complitera[comp[i]-'a']=i;
    }
    for(int i=1;i<=n;i++){
        f>>cuv;
        aux=getnumber();
        frecventa[aux]++;
    }
    if(cerinta==1){
        for(int i=0;i<=MAXVAL;i++){
            if(frecventa[i]!=0){
                cnt++;
            }
        }
        g<<cnt;
    }else{
        for(int i=0;i<=MAXVAL;i++){
            if(frecventa[i]!=0){
                getcuv(i);
                while(frecventa[i]){
                    g<<cuv<<'\n';
                    frecventa[i]--;
                }
            }
        }
    }
    f.close();
    g.close();
}
