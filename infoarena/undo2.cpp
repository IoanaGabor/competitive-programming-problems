
#include <iostream>
#include <fstream>
#include <vector>
#define MAXVAL 200000

using namespace std;

ifstream f("undo2.in");
ofstream g("undo2.out");

int m,op,x,top;
vector <int> poz[MAXVAL+3],sir;

int cauta(){
    int pas=1<<20,n=poz[x].size()-1,rez=-1;
    while(pas){
        if(pas+rez<=n&&poz[x][pas+rez]<top){
            rez+=pas;
        }
        pas>>=1;
    }
    return rez+1;
}

int main(){
    f>>m;
    while(m--){
        f>>op>>x;
        if(op==1){
            while(top<sir.size()){
                poz[sir.back()].pop_back();
                sir.pop_back();
            }
            poz[x].push_back(top);
            sir.push_back(x);
            top++;
        }else if(op==2){
            top-=x;
        }else if(op==3){
            top+=x;
        }else{
            g<<cauta()<<'\n';
        }
    }
    f.close();
    g.close();
}
