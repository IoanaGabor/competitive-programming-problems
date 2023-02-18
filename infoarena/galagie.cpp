
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("galagie.in");
ofstream g("galagie.out");

long long s[100001],sir[100001];

int main() {
    int n;
    f>>n;
    for(int i=1;i<=n;i++) {
        f>>sir[i];
    }
    sort(sir+1,sir+n+1);
    for(int i=1;i<=n;i++) {
        s[i]=s[i-1]+sir[i];
    }
    long long rez=0;
    for(int i=1;i<=n;i++){
        rez=rez-s[i-1]+(i-1)*sir[i]+(s[n]-s[i])-(n-i)*sir[i];
        rez=rez%1000000007;
    }
    g<<rez<<'\n';
    f.close();
    g.close();
}
