
#include <iostream>
#include <fstream>

using namespace std;

int n,matrice[1002][1002],frecventa[1001];

int main() {
    ifstream f("custi.in");
    ofstream g("custi.out");
    int element;
    f>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            f>>matrice[i][j];
            if(matrice[i][j]==1){
                matrice[i][j]=min(matrice[i-1][j],min(matrice[i][j-1],matrice[i-1][j-1]))+1;
                frecventa[matrice[i][j]]++;
            }
        }
    }
    for(int i=n-1;i>=1;i--){
        frecventa[i]=frecventa[i]+frecventa[i+1];
    }
    /*
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            cout<<matrice[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    for(int i=1;i<=n;i++){
        g<<frecventa[i]<<'\n';
    }
    f.close();
    g.close();
}
