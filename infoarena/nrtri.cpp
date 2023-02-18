
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream f("nrtri.in");
    ofstream g("nrtri.out");
    int n,sir[801],contor=0,ok=1;
    f>>n;
    for(int i=1;i<=n;i++) {
        f>>sir[i];
    }
    sort(sir+1,sir+n+1);
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            ok=1;
            for(int k=j+1;k<=n && ok;k++){
                if(sir[i]+sir[j]>=sir[k]){
                    contor++;
                }else{
                    ok=0;
                }
            }
        }
    }
    g<<contor;
    f.close();
    g.close();
}
