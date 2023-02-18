
#include <iostream>
#include <fstream>
#include <vector>
#define MOD 666173

using namespace std;

ifstream f("hashuri.in");
ofstream g("hashuri.out");

int n,op,x;
vector <int> h[MOD];
vector <int>:: iterator itt;
vector <int>:: iterator cauta(){
    vector <int>:: iterator it;
    for(it=h[x%MOD].begin();it!=h[x%MOD].end();it++){
        if(*it==x){
            return it;
        }
    }
    return h[x%MOD].end();
}

void sterge(){
    vector <int>:: iterator it;
    it=cauta();
    if(it!=h[x%MOD].end()){
        h[x%MOD].erase(it);
    }
}

void adauga(){
    vector <int>:: iterator it;
    it=cauta();
    if(it==h[x%MOD].end()){
        h[x%MOD].push_back(x);
    }
}

int main(){
    f>>n;
    while(n--){
        f>>op>>x;
        if(op==1){
            adauga();
        }
        if(op==2){
            sterge();
        }
        if(op==3){
            itt=cauta();
            if(itt==h[x%MOD].end()){
                g<<0<<'\n';
            }else{
                g<<1<<'\n';
            }
        }
    }
    f.close();
    g.close();
}
