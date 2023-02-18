
#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 50000

using namespace std;

ifstream f("tribute.in");
ofstream g("tribute.out");

int n,cx[NMAX+5],cy[NMAX+5],distx,disty,dx,dy,x,y;

int dist(int c[],int dc){
    int sc[NMAX+5],cnt=0;
    sc[NMAX]=0;
    for(int i=NMAX-1;i>=0;i--){
        sc[i]=sc[i+1]+cnt;
        cnt+=c[i];
    }
    int s=sc[dc],rez=sc[dc],st;
    cnt=c[0];
    st=cnt;
    for(int i=1;i<=NMAX-dc;i++){
        s=sc[i+dc]+st;
        cnt+=c[i];
        st+=cnt;
        rez=min(rez,s);
    }
    return rez;
}

int main(){
    f>>n>>dx>>dy;
    for(int i=1;i<=n;i++){
        f>>x>>y;
        cx[x]++;
        cy[y]++;
    }
    distx=dist(cx,dx);
    disty=dist(cy,dy);
    g<<distx+disty<<'\n';
    f.close();
    g.close();
}
