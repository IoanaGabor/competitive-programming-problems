
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define NMAX 10000
#define MAXVAL 10000

using namespace std;

ifstream f("drept3.in");
ofstream g("drept3.out");

struct ceva{
    int x,y,d;
} patr[NMAX+5];
int n,cx[2*NMAX+5],lx,fv[MAXVAL+5],ind,prec,maxim,arie,nr,s;
vector<int> coord[MAXVAL+5];
bool crit(ceva a,ceva b){
    if(a.x==b.x){
        return a.d<b.d;
    }
    return a.x<b.x;
}

int main() {
    f>>n;
    for(int i=1;i<=n;i++){
        f>>patr[i].x>>patr[i].y>>patr[i].d;
        coord[patr[i].x].push_back(i);
        coord[patr[i].x+patr[i].d].push_back(-i);
        cx[++lx]=patr[i].x;
        cx[++lx]=patr[i].x+patr[i].d;
    }
    sort(cx+1,cx+lx+1);
    cx[0]=-1;
    for(int i=1;i<=lx;i++){
        if(cx[i]!=cx[i-1]){
            nr=0;
            s=0;
            for(int j=0;j<=MAXVAL;j++){
                s+=fv[j];
                if(s>0){
                    nr++;
                }
                maxim=max(maxim,s);
            }
            arie+=nr*(cx[i]-prec);
            for(int j=0;j<coord[cx[i]].size();j++){
                ind=coord[cx[i]][j];
                if(ind>0){
                    fv[patr[ind].y]++;
                    fv[patr[ind].y+patr[ind].d]--;
                }else{
                    ind=-ind;
                    fv[patr[ind].y]--;
                    fv[patr[ind].y+patr[ind].d]++;
                }
            }
            prec=cx[i];
        }
    }
    g<<arie<<'\n'<<maxim<<'\n';
    f.close();
    g.close();
    return 0;
}
