
#include <iostream>
#include <fstream>

using namespace std;

int matrice[301][301],n,m,x;

int main(){
    ifstream f("placare.in");
    ofstream g("placare.out");
    f>>n>>m;
    int j;
    for(int i=1;i<=n;i++){
        j=1;
        while(j<=m){
            if(matrice[i][j]==0){
            f>>x;
                if(x!=0){
                    if(x>0){
                        for(int k=1;k<=x;k++){
                            matrice[i][j]=x;
                            j++;
                        }
                    }else{
                        for(int k=1;k<=-x;k++){
                            matrice[i+k-1][j]=-x;
                        }
                        j++;
                    }
                }
            }else{
                j++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            g<<matrice[i][j]<<' ';
        }
        g<<'\n';
    }
    f.close();
    g.close();
}
