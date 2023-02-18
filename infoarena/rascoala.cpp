
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define NMAX 500

using namespace std;

ifstream f("rascoala.in");
ofstream g("rascoala.out");

struct ceva{
    int val,x,y;
} sir[NMAX*NMAX+5];
int cerinta,n,m,k,mat[NMAX+5][NMAX+5],adaug[NMAX+5][NMAX+5],cat,rest,ultimul,minim,laux,distmax,lmin[NMAX+5],lmax[NMAX+5];
pair <int,int> aux[4*NMAX+5];

bool crit(ceva a,ceva b){
    if(a.val==b.val){
        if(a.x==b.x){
            return a.y<b.y;
        }
        return a.x<b.x;
    }
    return a.val<b.val;
}

void constr(){
    sir[n*m+1].val=(1LL<<31)-1;
    for(int i=1;i<=n*m&&k;i++){
        if(sir[i].val!=sir[i+1].val){
            cat=k/i;
            rest=k%i;
            if(cat>=(sir[i+1].val-sir[i].val)){
                ultimul=i;
                minim=sir[i+1].val;
                k-=(sir[i+1].val-sir[i].val)*i;
            }else{
                if(cat==0){
                    ultimul=max(ultimul,rest);
                    minim=sir[i].val;
                }else{
                    ultimul=i;
                    minim=sir[i].val+cat;
                }
                k=0;
                break;
            }
        }
    }
}

int main(){
    f>>cerinta>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>mat[i][j];
            sir[(i-1)*m+j].val=mat[i][j];
            sir[(i-1)*m+j].x=i;
            sir[(i-1)*m+j].y=j;
        }
    }
    sort(sir+1,sir+n*m+1,crit);
    constr();
    if(cerinta==1){
        g<<ultimul<<'\n'<<minim<<'\n';
    }else{
        for(int i=1;i<=n;i++){
            lmin[i]=(1LL<<31)-1;
        }
        for(int i=1;i<=ultimul;i++){
            lmin[sir[i].x]=min(lmin[sir[i].x],sir[i].y);
            lmax[sir[i].x]=max(lmax[sir[i].x],sir[i].y);
        }
        for(int i=1;i<=n;i++){
            if(lmax[i]){
                for(int j=i+1;j<=n;j++){
                    if(lmax[j]){
                        distmax=max(distmax,j-i+abs(lmin[i]-lmax[j]));
                        distmax=max(distmax,j-i+abs(lmin[j]-lmax[i]));
                    }
                }
            }
        }
        g<<distmax;
    }
    f.close();
    g.close();
}
