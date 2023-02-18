
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream f("permut.in");
    ofstream g("permut.out");
    long long n,a[100001],b[100001];
    f>>n;
    for(int i=1;i<=n;i++) {
        f>>a[i];
    }
    for(int i=1;i<=n;i++) {
        f>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    long long sol=0;
    for(int i=1;i<=n;i++) {
        sol=sol+a[i]*b[i];
    }
    g<<sol;
    f.close();
    g.close();
}
