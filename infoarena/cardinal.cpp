
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream f("cardinal.in");
    ofstream g("cardinal.out");
    int q,n;
    f>>q;
    while(q--){
        f>>n;
        if(n%8==7){
            g<<"URDRDLU";
            n=n-7;
            for(int i=1;i<=n/8;i++){
                g<<"RULDLDRU";
            }
        }else if(n%8==0){
            for(int i=1;i<=n/8;i++){
                g<<"URDLDLUR";
            }
        }else{
            g<<"IMPOSIBIL";
        }
        g<<'\n';
    }
    f.close();
    g.close();
}
