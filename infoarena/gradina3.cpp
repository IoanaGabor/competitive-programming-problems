
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("gradina3.in");
ofstream g("gradina3.out");

int n,m,k,x,y,a[1001][1001],s,maxim,contor;

int main(){
    f>>n>>m>>k;
    while(m--){
        f>>x>>y;
        a[x][y]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    for(int i=k;i<=n;i++){
        for(int j=k;j<=n;j++){
            s=a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k];
            if(s>maxim){
                maxim=s;
                contor=1;
            }else if(s==maxim){
                contor++;
            }
        }
    }
    g<<maxim<<'\n'<<contor<<'\n';
    f.close();
    g.close();
}
