
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("split.in");
ofstream g("split.out");

int n,a[5005],irez,jrez,krez,costrez,minst[5005],mindr[5005],maxst[5005],maxdr[5005],ii,jj,kk,maxij,minij,costij,maxjk,minjk,costjk;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>a[i];
        minst[i]=min(minst[i-1],a[i]);
        maxst[i]=max(maxst[i-1],a[i]);
        if(i==1){
            minst[i]=a[i];
            maxst[i]=a[i];
        }
    }
    for(int i=n;i>=1;i--){
        mindr[i]=min(mindr[i+1],a[i]);
        maxdr[i]=max(maxdr[i+1],a[i]);
        if(i==n){
            mindr[i]=a[i];
            maxdr[i]=a[i];
        }
    }
    for(jj=4;jj<=n-4;jj++){
        maxij=max(a[jj-1],a[jj]);
        minij=min(a[jj-1],a[jj]);
        costij=costjk=-1;
        for(int i=jj-2;i>=2;i--){
            if((maxij-minij+maxst[i]-minst[i])>=costij){
                ii=i;
                costij=maxij-minij+maxst[i]-minst[i];
            }
            maxij=max(maxij,a[i]);
            minij=min(minij,a[i]);
        }
        maxjk=a[jj+1];
        minjk=a[jj+1];
        for(int i=jj+2;i<=n-2;i++){
            maxjk=max(maxjk,a[i]);
            minjk=min(minjk,a[i]);
            if((maxjk-minjk+maxdr[i+1]-mindr[i+1])>costjk){
                kk=i;
                costjk=maxjk-minjk+maxdr[i+1]-mindr[i+1];
            }
        }
        if(costij+costjk>costrez){
            costrez=costij+costjk;
            irez=ii;
            jrez=jj;
            krez=kk;
        }else if(costij+costjk==costrez&& ((ii<irez)||(ii==irez&&jj<jrez)||(ii==irez&&jj==jrez&&kk<krez))){
            irez=ii;
            jrez=jj;
            krez=kk;
        }
    }
    g<<costrez<<'\n'<<irez<<' '<<jrez<<' '<<krez<<'\n';
    f.close();
    g.close();
}
