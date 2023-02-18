
#include <iostream>
#include <fstream>
#define NMAX 10000

using namespace std;

ifstream f("egipt.in");
ofstream g("egipt.out");

int n,sir[NMAX+5],cnt[4],sir1[NMAX+5],sir2[NMAX+5],sir3[NMAX+5],nr2,nr3,nr1,lrez;
pair<int,int> rez[NMAX+5];

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        cnt[sir[i]]++;
    }
    for(int i=1;i<=cnt[1];i++){
        if(sir[i]==2){
            sir2[++nr2]=i;
        }else if(sir[i]==3){
            sir3[++nr3]=i;
        }
    }
    for(int i=cnt[1]+1;i<=n&&nr1<nr2+nr3;i++){
        if(sir[i]==1){
            sir1[++nr1]=i;
        }
    }
    for(int i=1;i<=nr2;i++){
        rez[++lrez].first=sir2[i];
        rez[lrez].second=sir1[i];
        swap(sir[sir1[i]],sir[sir2[i]]);
    }
    for(int i=1;i<=nr3;i++){
        rez[++lrez].first=sir3[i];
        rez[lrez].second=sir1[nr2+i];
        swap(sir[sir1[nr2+i]],sir[sir3[i]]);
    }
    nr3=0;
    for(int i=cnt[1]+1;i<=cnt[1]+cnt[2];i++){
        if(sir[i]==3){
            sir3[++nr3]=i;
        }
    }
    nr2=0;
    for(int i=cnt[1]+cnt[2]+1;i<=n;i++){
        if(sir[i]==2){
            rez[++lrez].first=sir3[++nr2];
            rez[lrez].second=i;
        }
    }
    g<<lrez<<'\n';
    for(int i=1;i<=lrez;i++){
        g<<rez[i].first<<' '<<rez[i].second<<'\n';
    }
    f.close();
    g.close();
}
