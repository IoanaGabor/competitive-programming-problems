
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("aiacuxor.in");
ofstream g("aiacuxor.out");
int n,q,m,s[1001],v[1000001],sume_partiale[1000001],aux[1000001],rez[1000001],x,y,A,B,C,D,Z;

void afla_intrebare(){
    int x_nou,y_nou;
    x_nou=(x*A+y*B)%n+1;
    y_nou=(y*C+(Z%n)*D)%n+1;
    if(x_nou>y_nou){
        swap(x_nou,y_nou);
    }
    x=x_nou;
    y=y_nou;
}

int main(){
    f>>n>>q>>m;
    for(int i=0;i<m;i++){
        f>>s[i];
    }
    f>>x>>y>>A>>B>>C>>D;
    for(int i=0;i<n;i++){
        v[i]=(s[i/m]^s[i%m])+i;
        sume_partiale[i+1]=sume_partiale[i]^v[i];
    }
    for(int i=1;i<=n;i++){
        aux[i]=aux[i-1]^sume_partiale[i-1]^sume_partiale[n-i+1];
    }
    for(int i=1;i<=n;i++){
        rez[i]=rez[i-1]^aux[i];
    }
    while(q--){
        Z=rez[x-1]^rez[y];
        g<<Z<<'\n';
        afla_intrebare();
    }
    f.close();
    g.close();
}
