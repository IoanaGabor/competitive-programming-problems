#include <iostream>
#include <fstream>
#define NMAX 1501
using namespace std;

ifstream f("pseudobil.in");
ofstream g("pseudobil.out");

int cerinta,n,k,d,x,y,m;
int bile[2*NMAX][2*NMAX];

int nr_bile(){
    int a=x+y-1,b=n+x-y;
    return bile[a+d][b+d]-bile[a+d][b-1]-bile[a-1][b+d]+bile[a-1][b-1];
}

int main(){
    f>>cerinta>>n>>k>>d;
    if(cerinta==1){
        k=(d-2)/2;
        g<<(k+1)*(k+1)+k*k<<'\n';
        f.close();
        g.close();
        return 0;
    }
    for(int i=1;i<=k;i++){
        f>>x>>y;
        bile[x+y-1][n+x-y]++;
    }
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            bile[i][j]=bile[i][j]+bile[i][j-1]+bile[i-1][j]-bile[i-1][j-1];
        }
    }
    f>>m;
    for(int i=1;i<=m;i++){
        f>>x>>y;
        g<<nr_bile()<<'\n';
    }
    f.close();
    g.close();
}
