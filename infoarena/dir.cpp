
#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

ifstream f("dir.in");
ofstream g("dir.out");

string sir,aux;
set<string> rez;
int ok;

int rezolva(int i,int k){
    while(!isalpha(sir[i])&&!isdigit(sir[i])){
        i++;
    }
    ok=0;
    if(sir[i]<='z'&&sir[i]>='a'){
        ok=1;
    }
    while(isalpha(sir[i])||isdigit(sir[i])){
        aux[k]=sir[i];
        i++;
        k++;
    }
    aux[k++]='\\';
    if(!ok){
        i++;
        while(sir[i]!=')'){
            i=rezolva(i,k);
        }
        i++;
    }else{
        aux.resize(k-1);
        rez.insert(aux);
        aux.resize(sir.size());
    }
    return i;
}

int main(){
    getline(f,sir);
    aux.resize(sir.size());
    rezolva(0,0);
    g<<rez.size()<<'\n';
    for(auto& fisier:rez){
        g<<fisier<<'\n';
    }
    f.close();
    g.close();
}
