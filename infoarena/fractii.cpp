
#include <fstream>

using namespace std;

int main() {
    ifstream f("fractii.in");
    ofstream g("fractii.out");
    int n,euler[1000010];
    long long contor=0;
    f>>n;
    for(int i=2;i<=n;i++) {
        euler[i]=i-1;
    }

    for(int i=2;i<=n;i++) {
        contor=contor+euler[i];
        for(int j=2*i;j<=n;j=j+i){
            euler[j]=euler[j]-euler[i];
        }
    }
    g<<2*contor+1;
    f.close();
    g.close();
}
