
#include <bits/stdc++.h>
#define NMAX 2000

using namespace std;

ifstream fi("parc.in");
ofstream fo("parc.out");

int X,Y;
int xg,yg,xp,yp;
int m,n,stm,stn;
pair<int,int> ver[NMAX+5],oriz[NMAX+5];
int dpo,dpv,dx,dy;
int pietx[NMAX+5],piety[NMAX+5];
int nrsol;

int main(){
    fi>>X>>Y;
    fi>>xg>>yg>>xp>>yp;
    if(yg>yp){
        swap(xg,xp);
        swap(yg,yp);
    }
    fi>>m;
    for(int i=1;i<=m;i++){
        fi>>ver[i].first>>ver[i].second;
        if(ver[i].first>ver[i].second){
           swap(ver[i].first,ver[i].second);
        }
    }
    fi>>n;
    for(int i=1;i<=n;i++){
        fi>>oriz[i].first>>oriz[i].second;
        if(oriz[i].first>oriz[i].second){
           swap(oriz[i].first,oriz[i].second);
        }
    }
    if(xg>xp){
        xg=X-xg;
        xp=X-xp;
        for(int i=1;i<=m;i++){
            swap(ver[i].first,ver[i].second);
            ver[i].first=X-ver[i].first;                    
            ver[i].second=X-ver[i].second;
        }       
    }
    sort(ver+1,ver+m+1);
    sort(oriz+1,oriz+n+1);
    for(int i=1;i<=m;i++){
        if(xg<=ver[i].first&&ver[i].second<=xp){
            dpo+=ver[i].second-ver[i].first;
        }
    }
    for(int i=1;i<=n;i++){
        if(yg<=oriz[i].first&&oriz[i].second<=yp){
            dpv+=oriz[i].second-oriz[i].first;
        }
    }
    while(xp<=ver[m].first){
        m--;
    }
    while(yp<=oriz[n].first){
        n--;
    }
    stm=stn=1;
    while(ver[stm].second<=xg){
        stm++;
    }
    while(oriz[stn].second<=yg){
        stn++;
    }
    pietx[stm]=ver[stm].first-xg;
    piety[stn]=oriz[stn].first-yg;
    for(int i=stm+1;i<=m;i++){
        pietx[i]=pietx[i-1]+ver[i].first-ver[i-1].second;
    }
    for(int i=stn+1;i<=n;i++){
        piety[i]=piety[i-1]+oriz[i].first-oriz[i-1].second;
    }
    dx=xp-xg-dpo;
    dy=yp-yg-dpv;
    double lung=sqrt(double(dx*dx+dy*dy))+dpo+dpv;
    fo<<fixed<<setprecision(6)<<lung<<'\n';
    nrsol=1;
    while(stn<=n&&stm<=m){
        if(pietx[stm]*dy==piety[stn]*dx){
            stn++;
            stm++;
            nrsol*=2;
        }else if(pietx[stm]*dy<piety[stn]*dx){
            stm++;
        }else if(pietx[stm]*dy>piety[stn]*dx){
            stn++;
        }
    }
    fo<<nrsol<<'\n';
    fi.close();
    fo.close();
}