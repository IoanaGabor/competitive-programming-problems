
#include <iostream>
#include <fstream>
#define LGMAX 100000

using namespace std;

ifstream f("jocul.in");
ofstream g("jocul.out");

int n,lung,sumatot;
bool ok[LGMAX+5];

int main(){
    f>>n;
    ok[0]=1;
    for(int i=1;i<=n;i++){
        f>>lung;
        for(int j=sumatot;j>=0;j--){
            if(ok[j]){
                ok[j+lung]=1;
            }
        }
        sumatot+=lung;
    }
    for(int i=sumatot/2;i>=0;i--){
        if(ok[i]){
            g<<i<<' '<<sumatot-i;
            return 0;
        }
    }
}
