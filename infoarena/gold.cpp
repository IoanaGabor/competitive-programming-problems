
#include <bits/stdc++.h>
#define NMAX 1024
#define inf 33000

using namespace std;

ifstream fi("gold.in");
ofstream fo("gold.out");

struct punct{
    int x,y,sus,val;
    double m;
} pcte[NMAX+5],pcte2[NMAX+5];
int n,l,p,s[3];
int cnt;

bool crit(punct a,punct b){
    return a.m<b.m;
}

bool trigon(int a,int b,int c){
    return ((pcte2[a].x*pcte2[b].y+pcte2[c].x*pcte2[a].y+pcte2[b].x*pcte2[c].y-pcte2[c].x*pcte2[b].y-pcte2[b].x*pcte2[a].y-pcte2[a].x*pcte2[c].y)>0);
}

bool ok(){
    if(abs(s[0]-s[1])<=p){
        return true;
    }
    return false;
}

int main(){
    fi>>n>>p;
    for(int i=1;i<=n;i++){
        fi>>pcte[i].val;
    }
    for(int i=1;i<=n;i++){
        fi>>pcte[i].x>>pcte[i].y;

    }
    for(int i=1;i<=n;i++){
        pcte2[1]=pcte[i];
        l=1;
        for(int j=1;j<=n;j++){
            if(i!=j){
                pcte2[++l]=pcte[j];
                if(pcte2[l].x!=pcte2[1].x){
                    pcte2[l].m=(double)((pcte2[l].y-pcte2[1].y)/((double)(pcte2[l].x-pcte2[1].x)));
                }else{
                    pcte2[l].m=inf;
                }
            }
        }
        sort(pcte2+2,pcte2+n+1,crit);
        s[1]=s[0]=0;
        for(int j=3;j<=n;j++){
            if(trigon(1,2,j)){
                pcte2[j].sus=1;
                s[1]+=pcte2[j].val;
            }else{
                pcte2[j].sus=0;
                s[0]+=pcte2[j].val;
            }
        }
        if(ok()){
            cnt++;
        }
        pcte2[2].sus=1;
        for(int j=3;j<=n;j++){
            pcte2[j-1].sus=1-pcte2[j-1].sus;
            s[pcte2[j-1].sus]+=pcte2[j-1].val;
            s[pcte2[j].sus]-=pcte2[j].val;
            if(ok()){
                cnt++;
            }
        }
    }
    fo<<cnt/2<<'\n';
    fi.close();
    fo.close();
}