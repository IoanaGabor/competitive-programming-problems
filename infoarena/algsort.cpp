
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    ifstream f("algsort.in");
    ofstream g("algsort.out");
    int sir[500001],n;
    f>>n;
    for(int i=1;i<=n;i++) {
        f>>sir[i];
    }
    sort(sir+1,sir+n+1);
    for(int i=1;i<=n;i++) {
        g<<sir[i]<<' ';
    }
    f.close();
    g.close();
}
