
#include <iostream>
#include <queue>
#include <fstream>
#define NMAX 100000
#define TMAX 50000

using namespace std;

ifstream f("fabrica.in");
ofstream g("fabrica.out");

priority_queue<pair <int,int> > heapa,heapb;
int n,ma,mb,A[NMAX+5],B[NMAX+5],ta[TMAX+5],tb[TMAX+5],rez;

int main(){
    f>>n>>ma>>mb;
    for(int i=1;i<=ma;i++){
        f>>ta[i];
        heapa.push(make_pair(-ta[i],i));
    }
    for(int i=1;i<=mb;i++){
        f>>tb[i];
        heapb.push(make_pair(-tb[i],i));
    }
    for(int i=1;i<=n;i++){
        pair <int,int> p;
        p=heapa.top();
        heapa.pop();
        A[i]=-p.first;
        p.first=p.first-ta[p.second];
        heapa.push(p);
    }
    g<<A[n]<<' ';
    for(int i=1;i<=n;i++){
        pair <int,int> p;
        p=heapb.top();
        heapb.pop();
        B[i]=-p.first;
        p.first=p.first-tb[p.second];
        heapb.push(p);
    }
    for(int i=1;i<=n;i++){
        rez=max(A[i]+B[n-i+1],rez);
    }
    g<<rez<<'\n';
    f.close();
    g.close();
    return 0;
}
