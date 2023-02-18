
#include <iostream>
#include <fstream>

using namespace std;
bool ciur[1300000];

void initializare(int n) {
    for(int i=1;i<=n;i++) {
        ciur[i]=true;
    }
    ciur[0]=false;
    ciur[1]=false;
    for(int i=2;i<=n;i++){
        if(ciur[i]==true){
            for(int j=i+i;j<=n;j=j+i){
                ciur[j]=false;
            }
        }
    }
}

int main() {
    ifstream f("prim.in");
    ofstream g("prim.out");
    int k;
    f>>k;
    initializare(1300000);
    int contor_prim=0;
    unsigned long long rez;
    for(unsigned long long i=2;i<=1300000,contor_prim<k+1;i++) {
        if(ciur[i]==true){
            contor_prim++;
        }
        if(contor_prim==k+1){
            rez=i*i;
        }
    }
    g<<rez;
    f.close();
    g.close();
}
