
#include <iostream>
#include <fstream>
#define nmax 100001

using namespace std;

ifstream f("cautbin.in");
ofstream g("cautbin.out");

int n,m,sir[nmax],x,cerinta,rez;

int zero(){
    int stanga=1,dreapta=n,mijloc;
    while(stanga<dreapta){
        mijloc=(stanga+dreapta+1)/2;
        if(sir[mijloc]<=x){
            stanga=mijloc;
        }else{
            dreapta=mijloc-1;
        }
    }
    return stanga;
}

int doi(){
    int stanga=1,dreapta=n,mijloc;
    while(stanga<dreapta){
        mijloc=(stanga+dreapta)/2;
        if(sir[mijloc]<x){
            stanga=mijloc+1;
        }else{
            dreapta=mijloc;
        }
    }
    return stanga;
}


int main()
{
    f>>n;
    for(int i=1;i<=n;i++) {
        f>>sir[i];
    }
    f>>m;
    for(int i=1;i<=m;i++){
        f>>cerinta>>x;
        if(cerinta==0){
            rez=zero();
            if(sir[rez]!=x){
                g<<-1<<'\n';
            }else{
                g<<rez<<'\n';
            }
        }
        if(cerinta==1){
            g<<zero()<<'\n';
        }
        if(cerinta==2){
            g<<doi()<<'\n';
        }
    }
    f.close();
    g.close();
    return 0;
}
