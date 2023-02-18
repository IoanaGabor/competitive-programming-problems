#include <iostream>
#include <fstream>
#define NMAX 1000000

using namespace std;

ifstream f("nrpits.in");
ofstream g("nrpits.out");

int n,nr,stiva[NMAX+5],top,contor;

int main(){
    f>>n>>nr;
    stiva[++top]=nr;
    for(int i=1;i<n;i++){
        f>>nr;
        while(stiva[top]<nr&&top){
            if(top>=2){
                contor++;
            }
            top--;
        }
        stiva[++top]=nr;
    }
    g<<contor;
    f.close();
    g.close();
}
