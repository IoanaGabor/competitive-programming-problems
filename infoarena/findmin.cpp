
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("findmin.in");
ofstream g("findmin.out");

int sir[1000001],rez[1000001],n,minim;

int main(){
    f>>n;
    minim=n+1;
    int x;
    for(int i=1;i<=n;i++){
        f>>x;
        sir[x]=i;
    }
    for(int i=1;i<=n;i++){
        if(minim<sir[i]){
            rez[sir[i]]=minim;
        }else{
            rez[sir[i]]=-1;
            minim=sir[i];
        }
    }
    for(int i=1;i<=n;i++){
        g<<rez[i]<<' ';
    }
    f.close();
    g.close();
}
