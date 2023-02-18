#include <iostream>
#include <fstream>

using namespace std;

ifstream f("submultimi.in");
ofstream g("submultimi.out");

int n,aux;

int main(){
    f>>n;
    aux=(1<<n)-1;
    for(int i=1;i<=aux;i++){
        for(int j=1;j<=n;j++){
            if(((i>>(j-1))&1)==1){
                g<<j<<' ';
            }
        }
        g<<'\n';
    }
    f.close();
    g.close();
}
