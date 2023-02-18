
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("pluton.in");
ofstream g("pluton.out");

struct soldat{
    string placuta;
    int j;
} sir[4005];

string aux[4005];
int n,nr_plutoane,nr_max_soldati,nr_soldati,i_pluton,nr_plutoane_max;

bool criteriu(soldat a,soldat b){
    return a.placuta<b.placuta;
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i].placuta;
        aux[i]=sir[i].placuta;
        sort(sir[i].placuta.begin(),sir[i].placuta.end());
        sir[i].j=i;
    }
    sort(sir+1,sir+n+1,criteriu);
    for(int i=1;i<=n;i++){
        if(i==1||sir[i].placuta!=sir[i-1].placuta){
            nr_plutoane++;
            if(nr_soldati>nr_max_soldati){
                nr_max_soldati=nr_soldati;
                i_pluton=i-nr_max_soldati;
                nr_plutoane_max=1;
            }else if(nr_soldati==nr_max_soldati){
                nr_plutoane_max++;
            }
            nr_soldati=1;
        }else{
            nr_soldati++;
        }
    }
    if(nr_soldati>1){
            if(nr_soldati>nr_max_soldati){
                nr_max_soldati=nr_soldati;
                i_pluton=n-nr_max_soldati+1;
                nr_plutoane_max=1;
            }else if(nr_soldati==nr_max_soldati){
                nr_plutoane_max++;
            }
    }
    g<<nr_plutoane<<'\n'<<nr_max_soldati<<'\n'<<nr_plutoane_max<<'\n';
    for(int i=i_pluton;i<=i_pluton+nr_max_soldati-1;i++){
        g<<aux[sir[i].j]<<' ';
    }
    f.close();
    g.close();
}
