
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("fotbal.in");
ofstream g("fotbal.out");

struct echipa{
    int nr,golaveraj,goluri_inscrise,puncte;
};
echipa v[6];

int n,x,y,gx,gy;

bool criteriu(echipa a,echipa b){
    if(a.puncte==b.puncte){
        if(a.golaveraj==b.golaveraj){
            return a.goluri_inscrise>=b.goluri_inscrise;
        }else{
            return a.golaveraj>b.golaveraj;
        }
    }else{
        return a.puncte>b.puncte;
    }
}

bool egalitate(echipa a,echipa b){
    if(a.puncte==b.puncte&&a.golaveraj==b.golaveraj&&a.goluri_inscrise==b.goluri_inscrise){
        return true;
    }
    return false;
}

pair <int,int> rez[6];

int main(){
    f>>n;
    int m=(n-1)*n/2;
    for(int i=1;i<=m;i++){
        f>>x>>y>>gx>>gy;
        if(gx<gy){
            v[y].puncte+=3;
        }else if(gx==gy){
            v[x].puncte++;
            v[y].puncte++;
        }else{
            v[x].puncte+=3;
        }
        v[x].goluri_inscrise+=gx;
        v[y].goluri_inscrise+=gy;
        v[x].golaveraj+=gx-gy;
        v[y].golaveraj+=gy-gx;
    }
    for(int i=1;i<=n;i++){
        v[i].nr=i;
    }
    sort(v+1,v+n+1,criteriu);
    for(int i=1;i<=n;i++){
        if(i==1||!egalitate(v[i],v[i-1])){
            rez[v[i].nr].first=i;
        }else{
            rez[v[i].nr].first=rez[v[i-1].nr].first;
        }
    }
    for(int i=n;i>=1;i--){
        if(i==n||!egalitate(v[i],v[i+1])){
            rez[v[i].nr].second=i;
        }else{
            rez[v[i].nr].second=rez[v[i+1].nr].second;
        }
    }
    for(int i=1;i<=n;i++){
        g<<rez[i].first<<' '<<rez[i].second<<'\n';
    }
    f.close();
    g.close();
}
