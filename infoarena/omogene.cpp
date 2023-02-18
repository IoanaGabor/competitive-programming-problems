
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("omogene.in");
ofstream g("omogene.out");

int s[3][260][5005],rez=0,contor;
pair<int,int> aux[5005];
int main(){
    int n,m,val;
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>val;
            for(int k=0;k<=2;k++){
                s[k][i][j]=s[k][i-1][j];
            }
            s[val][i][j]++;
        }
    }
    int x,y,z;
    for(int l1=1;l1<=n;l1++){
        for(int l2=l1;l2<=n;l2++){
            x=0;
            y=0;
            z=0;
            aux[0].first=0;
            aux[0].second=0;
            for(int j=1;j<=m;j++){
                x+=(s[0][l2][j]-s[0][l1-1][j]);
                y+=(s[1][l2][j]-s[1][l1-1][j]);
                z+=(s[2][l2][j]-s[2][l1-1][j]);
                aux[j].first=x-y;
                aux[j].second=y-z;
            }
            sort(aux,aux+m+1);
            contor=1;
            for(int i=1;i<=m;i++){
                if(aux[i-1]==aux[i]){
                    contor++;
                }else{
                    rez+=contor*(contor-1)/2;
                    contor=1;
                }
            }
            rez+=contor*(contor-1)/2;
        }
    }
    g<<rez;
    f.close();
    g.close();
}
