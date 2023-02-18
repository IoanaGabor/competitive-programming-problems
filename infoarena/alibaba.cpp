#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n,k,nr,l_rez;
char rez[10001];

int main()
{
    ifstream f("alibaba.in");
    ofstream g("alibaba.out");
    f>>n>>k>>rez[1];
    int z=n-k;
    l_rez=1;
    char ch;
    for(int i=1;i<=n-1;i++){
        f>>ch;
        while(rez[l_rez]<ch && k>0 && l_rez>0){
            k--;
            l_rez--;
        }
        l_rez++;
        rez[l_rez]=ch;
    }
    for(int i=1;i<=z;i++){
        g<<rez[i];
    }
    f.close();
    g.close();
    return 0;
}
