
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("flori5.in");
ofstream g("flori5.out");

long long n,k,flori[100005],sume[100005],m,a,b,x,nr_flori,nr_mij;

int main(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>x;
        flori[i]=flori[i-1]+x/k;
        sume[i]=sume[i-1]+x;
    }
    f>>m;
    for(int i=1;i<=m;i++){
        f>>a>>b;
        nr_flori=flori[b]-flori[a-1];
        nr_mij=(sume[b]-sume[a-1])-nr_flori*k;
        if(nr_flori<=nr_mij){
            g<<nr_flori<<'\n';
        }else{
            x=(nr_flori-nr_mij+k)/(k+1);
            g<<nr_flori-x<<'\n';
        }
    }
    f.close();
    g.close();
}
