
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("romb.in");
ofstream g("romb.out");

struct punct{
    double x,y;
};

bool trigon(punct a,punct b,punct c){
    return((a.x*b.y+b.x*c.y+c.x*a.y-c.x*b.y-a.x*c.y-b.x*a.y)>0);
}

int t,dx,dy,k,cx,cy;
long long rez;
punct unu,doi,trei,patru,v1,v2,v3,v4,oras,centrnou;

bool inside(punct a,punct b,punct c,punct d){
    if(trigon(oras,a,b)&&trigon(oras,b,c)&&trigon(oras,c,d)&&trigon(oras,d,a)){
        return true;
    }
    return false;
}

void divetimp(punct cen,double xd,double yd,long long nrord,int cnt){
    if(cnt<=k){
        unu.x=(double)((2*cen.x-xd)/2);
        unu.y=(double)((2*cen.y+yd)/2);
        doi.x=(double)((2*cen.x+xd)/2);
        doi.y=(double)((2*cen.y+yd)/2);
        trei.x=(double)((2*cen.x-xd)/2);
        trei.y=(double)((2*cen.y-yd)/2);
        patru.x=(double)((2*cen.x+xd)/2);
        patru.y=(double)((2*cen.y-yd)/2);
        v1.x=(double)(cen.x);
        v1.y=(double)(cen.y+yd);
        v2.x=(double)(cen.x-xd);
        v2.y=(double)(cen.y);
        v3.x=(double)(cen.x);
        v3.y=(double)(cen.y-yd);
        v4.x=(double)(cen.x+xd);
        v4.y=(double)(cen.y);
        if(inside(v1,unu,cen,doi)){
            centrnou.x=cen.x;
            centrnou.y=(double)((2*cen.y+yd)/2);
            rez=4LL*nrord-3;
            divetimp(centrnou,(double)(xd/2),(double)(yd/2),rez,cnt+1);
        }else if(inside(unu,v2,trei,cen)){
            centrnou.x=(double)((2*cen.x-xd)/2);
            centrnou.y=(double)(cen.y);
            rez=4LL*nrord-2;
            divetimp(centrnou,(double)(xd/2),(double)(yd/2),rez,cnt+1);
        }else if(inside(cen,trei,v3,patru)){
            centrnou.x=(double)(cen.x);
            centrnou.y=(double)((2*cen.y-yd)/2);
            rez=4LL*nrord-1;
            divetimp(centrnou,(double)(xd/2),(double)(yd/2),rez,cnt+1);
        }else if(inside(doi,cen,patru,v4)){
            centrnou.x=(double)((2*cen.x+xd)/2);
            centrnou.y=(double)(cen.y);
            rez=4LL*nrord;
            divetimp(centrnou,(double)(xd/2),(double)(yd/2),rez,cnt+1);
        }
    }
}

int main(){
    f>>t;
    while(t--){
        f>>dx>>dy>>k>>cx>>cy;
        oras.x=cx;
        oras.y=cy;
        rez=1;
        centrnou.x=0;
        centrnou.y=0;
        divetimp(centrnou,dx,dy,1,1);
        g<<rez<<'\n';
    }
    f.close();
    g.close();
}
