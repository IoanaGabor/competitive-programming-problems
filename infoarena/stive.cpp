#include <iostream>
#include <fstream>

using namespace std;

ifstream f("stive.in");
ofstream g("stive.out");

int n,p,nr,cnt;

int main() {
    f>>n;
    p=1;
    while(p<=n){
        p<<=1;
        nr++;
    }
    g<<nr<<'\n';
    for(int p=1;p<=n;p<<=1){
        cnt=0;
        for(int i=1;i<=n;i++){
            if((p&i)>0){
                cnt++;
            }
        }
        g<<cnt<<' ';
        for(int i=1;i<=n;i++){
            if((p&i)>0){
                g<<i<<' ';
            }
        }
        g<<p;
        g<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
