
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("risc2.in");
ofstream g("risc2.out");

int n,h[100005],cerinta,imax,ok,a[100005],b[100005];

int main(){
    f>>cerinta;
    f>>n;
    for(int i=1;i<=n;i++){
        f>>h[i];
        if(h[imax]<h[i]){
            imax=i;
        }
    }
    if(cerinta==1){
        ok=1;
        for(int i=imax+1;i<n;i++){
            if(h[i]<h[i+1]){
                ok=0;
            }
        }
        for(int i=1;i<imax-1;i++){
            if(h[i]>h[i+1]){
                ok=0;
            }
        }
        if(ok&& imax!=n&&imax!=1&& h[n]<h[imax-1]){
            ok=0;
        }
            if(ok==0){
                g<<-1;
            }else{
                g<<imax;
            }
    }else{
        for(int i=1;i<=n;i++){
            a[h[i]]++;
        }
        for(int i=1;i<=h[imax];i++){
            a[i]+=a[i-1];
        }
        for(int i=1;i<=n;i++){
            b[a[h[i]]]=h[i];
        }
        int j=1,crescvf=0,crescn=0,descr=0;
        for(int i=1;i<=n;i++){
            if(h[i]==b[j]){
                j++;
                crescn++;
            }
            if(h[i]==h[imax]){
                crescvf=crescn;
            }
        }
        j=n;
        for(int i=imax;i<=n;i++){
            if(h[i]==b[j]){
                descr++;
                j--;
            }
        }
        g<<n-max(crescvf+descr,crescn);
    }
    f.close();
    g.close();
}
