
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("rafturi.in");
ofstream g("rafturi.out");

int h_max[10001],c,n,a,b,rez[10001];

int main(){
    f>>c>>n;
    for(int i=1;i<=n;i++){
        f>>a>>b;
        h_max[a]=max(h_max[a],b);
    }
    rez[1]=h_max[1];
    rez[2]=max(h_max[1],h_max[2]);
    int aux;
    for(int i=3;i<=c;i++){
        aux=rez[i-1]+h_max[i];
        aux=min(aux,rez[i-2]+max(h_max[i],h_max[i-1]));
        aux=min(aux,rez[i-3]+max(h_max[i],max(h_max[i-1],h_max[i-2])));
        rez[i]=aux;
    }
    g<<rez[c];
    f.close();
    g.close();
}
