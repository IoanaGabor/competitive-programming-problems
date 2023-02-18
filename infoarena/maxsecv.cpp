
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("maxsecv.in");
    ofstream g("maxsecv.out");
    int n,el,maxsecv1=-1,maxsecv2=-1,contor=0;
    f>>n;
    for(int i=1;i<=n+1;i++) {
        if(i<=n){
            f>>el;
        }else{
            el=0;
        }
        if(el==1) {
            contor++;
        }else{
            if(contor>maxsecv1) {
                maxsecv2=maxsecv1;
                maxsecv1=contor;
            }else if(contor>maxsecv2) {
                maxsecv2=contor;
            }
            contor=0;
        }
    }
    g<<maxsecv1+maxsecv2;
    f.close();
    g.close();
}
