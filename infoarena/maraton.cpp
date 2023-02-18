
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("maraton.in");
ofstream g("maraton.out");

int n,k,semafor,timp,stare;

int main(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>semafor;
        timp+=k;
        stare=timp;
        if(semafor==-2){
            stare+=2;
        }else if(semafor==-1){
            stare+=7;
        }
        stare%=10;
        if(stare>=2){
            timp+=(10-stare);
        }
    }
    timp+=k;
    g<<timp;
    f.close();
    g.close();
}
