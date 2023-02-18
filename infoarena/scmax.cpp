
#include <iostream>
#include <fstream>
#define nmax 100001

using namespace std;

ifstream f("scmax.in");
ofstream g("scmax.out");

int n,val,sir[nmax],aux[nmax],poz,l_aux,aux2[nmax],i_max=1,raspuns[nmax];

int cauta_poz(){
    int inceput=1,sfarsit=l_aux,mijloc,rez;
    while(inceput<=sfarsit){
        mijloc=(inceput+sfarsit)/2;
        if(val<aux[mijloc]){
            rez=mijloc;
            sfarsit=mijloc-1;
        }else{
            inceput=mijloc+1;
        }
    }
    return rez;
}

int main(){
    f>>n>>sir[1];
    aux[1]=sir[1];
    aux2[1]=1;
    l_aux=1;
    for(int i=2;i<=n;i++){
        f>>sir[i];
        val=sir[i];
        if(val==aux[l_aux]){
            continue;
        }
        if(val>aux[l_aux]){
            aux[++l_aux]=val;
            aux2[i]=l_aux;
        }else{
            poz=cauta_poz();
            if(aux[poz-1]==val){
                continue;
            }
            aux[poz]=val;
            aux2[i]=poz;
        }
        if(aux2[i]>aux2[i_max]){
            i_max=i;
        }
    }
    /*for(int i=1;i<=n;i++){
        cout<<sir[i]<<' '<<aux2[i]<<'\n';
    }*/
    g<<aux2[i_max]<<'\n';
    int j=aux2[i_max];
    raspuns[j]=sir[i_max];
    j--;
    for(int i=i_max-1;i>=1&&j;i--){
        if(aux2[i]==j){
            raspuns[j]=sir[i];
            j--;
        }
    }
    for(int i=1;i<=aux2[i_max];i++){
        g<<raspuns[i]<<' ';
    }
    f.close();
    g.close();
}
