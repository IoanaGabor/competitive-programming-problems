#include <iostream>
#include <fstream>
#define NMAX 100000

using namespace std;

ifstream f("disjoint.in");
ofstream g("disjoint.out");

int n,m,op,x,y,parent[NMAX+5],nrelemente[NMAX+5],p1,p2;

int functie(int val){
    if(parent[val]==val){
        return val;
    }else{
        parent[val]=functie(parent[val]);
        return parent[val];
    }
}

int main() {
    f>>n>>m;
    for(int i=1;i<=n;i++){
        parent[i]=i;
        nrelemente[i]=1;
    }
    for(int i=1;i<=m;i++){
        f>>op>>x>>y;
        p1=functie(x);
        p2=functie(y);
        if(op==1){
            if(nrelemente[p1]<=nrelemente[p2]){
                parent[p1]=p2;
                nrelemente[p2]+=nrelemente[p1];
            }
            if(nrelemente[p1]>nrelemente[p2]){
                parent[p2]=p1;
                nrelemente[p1]+=nrelemente[p2];
            }
        }else{
            if(p1==p2){
                g<<"DA"<<'\n';
            }else{
                g<<"NU"<<'\n';
            }
        }
    }
    f.close();
    g.close();
    return 0;
}
