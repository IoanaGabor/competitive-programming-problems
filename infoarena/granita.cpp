
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct pereche{
    int a,b;
};

bool criteriu(pereche x,pereche y){
    if(x.a<y.a){
        return true;
    }else if(x.a==y.a && x.b<y.b) {

        return true;
    }
    return false;
}

int main() {
    ifstream f("granita.in");
    ofstream g("granita.out");
    int n,aux;
    pereche sir[16001];
    f>>n;
    for(int i=1;i<=n;i++) {
        f>>sir[i].a>>sir[i].b;
    }
    sort(sir+1,sir+n+1,criteriu);
    int maxim=0,inutil=0;
    for(int i=1;i<=n;i++) {
        if(sir[i].b>maxim){
            maxim=sir[i].b;
        }else{
            inutil++;
        }
    }
    g<<inutil;
    f.close();
    g.close();
}
