
#include <iostream>
#include <fstream>

using namespace std;
bool ciur[2000000];

int rezolvare(int n) {
    int contor=0;
    for(int i=1;i<=n;i++) {
        ciur[i]=true;
    }
    ciur[0]=false;
    ciur[1]=false;
    for(int i=2;i<=n;i++){
        if(ciur[i]==true){
            contor++;
            for(int j=i+i;j<=n;j=j+i){
                ciur[j]=false;
            }
        }
    }
    return contor;
}

int main() {
    ifstream f("ciur.in");
    ofstream g("ciur.out");
    int n;
    f>>n;
    g<<rezolvare(n);
    f.close();
    g.close();
}
