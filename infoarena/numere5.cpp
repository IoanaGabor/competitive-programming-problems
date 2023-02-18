
#include <iostream>
#include <fstream>

using namespace std;

int frecventa[1000001];

int main() {
    ifstream f("numere5.in");
    ofstream g("numere5.out");
    int n,x,a,b;
    f>>n;
    for(int i=1;i<=n*n;i++){
        f>>x;
        frecventa[x]++;
    }
    for(int i=1;i<=n*n;i++){
        if(frecventa[i]==0){
            a=i;
            break;
        }
    }
    for(int i=n*n;i>=1;i--){
        if(frecventa[i]==0){
            b=i;
            break;
        }
    }
    g<<a<<' '<<b;
    f.close();
    g.close();
}
