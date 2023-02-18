#include <bits/stdc++.h>
#define NMAX 100000
#define SQRTMAX 1000

using namespace std;

ifstream fi("rangemode.in");
ofstream fo("rangemode.out");

struct query{
    int x,y,ord;
};

vector<query> buckets[SQRTMAX+5];
int n,m,lq;
int sir[NMAX+5];
int radical;
int fv[NMAX+5];
int sol[NMAX+5];
int best,bbest;

priority_queue<pair<int,int> > pq;

bool crit(query a,query b){
    return a.y<b.y;
}

int main(){
    fi>>n>>m;
    radical=sqrt(n);
    for(int i=1;i<=n;i++){
        fi>>sir[i];
    }
    int st,dr;
    for(int i=1;i<=m;i++){
        fi>>st>>dr;
        if(dr-st+1<=radical+1){
            best=0;
            for(int j=st;j<=dr;j++){
                fv[sir[j]]++;
                if(fv[best]<fv[sir[j]]||(fv[best]==fv[sir[j]]&&sir[j]<best)){
                    best=sir[j];
                }
            }
            sol[i]=best;
            for(int j=st;j<=dr;j++){
                fv[sir[j]]--;
            }
        }else{
            if(st%radical){
                buckets[st/radical+1].push_back({st,dr,i});
            }else{
                buckets[st/radical].push_back({st,dr,i});
            }
        }
    }
    int l=0;
    int r=0;
    int lastr,capat;
    for(int i=1;i<=radical+1;i++){
        if(buckets[i].size()){
            sort(buckets[i].begin(),buckets[i].end(),crit);
            lastr=-1;
            capat=min(i*radical,n);
            best=0;
            for(int ii=0;ii<buckets[i].size();ii++){
                l=buckets[i][ii].x;
                r=buckets[i][ii].y;
                for(int j=max(capat,lastr+1);j<=r;j++){
                    //cout<<j<<' '<<best<<' '<<fv[best]<<'\n';
                    fv[sir[j]]++;
                    if(fv[best]<fv[sir[j]]||(fv[best]==fv[sir[j]]&&sir[j]<best)){
                        best=sir[j];
                        //cout<<j<<' ';
                    }                
                }
                bbest=best;
                for(int j=l;j<capat;j++){
                    fv[sir[j]]++;
                    if(fv[bbest]<fv[sir[j]]||(fv[bbest]==fv[sir[j]]&&sir[j]<bbest)){
                        bbest=sir[j];
                    }           
                }

                //cout<<r<<' '<<best<<' '<<fv[best]<<'\n';
                //cout<<"****"<<'\n';
               // cout<<best<<' '<<fv[best]<<' '<<bbest<<' '<<fv[bbest]<<'\n';
                sol[buckets[i][ii].ord]=bbest;
                for(int j=l;j<capat;j++){
                    fv[sir[j]]--;
                }
                lastr=r;
            }
            for(int j=1;j<=n;j++){
                fv[sir[j]]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        fo<<sol[i]<<'\n';
    }
    fi.close();
    fo.close();
}