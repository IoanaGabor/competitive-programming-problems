
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("permutari.in");
ofstream g("permutari.out");

int n,viz[10],sir[10];

void backtracking(int k){
    if(k==n+1){
        for(int i=1;i<=n;i++){
            g<<sir[i]<<' ';
        }
        g<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(!viz[i]){
            viz[i]=1;
            sir[k]=i;
            backtracking(k+1);
            viz[i]=0;
        }
    }
}

int main(){
    f>>n;
    backtracking(1);
    f.close();
    g.close();
}
