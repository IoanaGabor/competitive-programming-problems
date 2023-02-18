#include <bits/stdc++.h>
#define MMAX 100000
#define NMAX 100000

using namespace std;

ifstream fi("saseg.in");
ofstream fo("saseg.out");

int c,n,m;
pair<int,int> sir[MMAX+5];
int stare[MMAX+5];
int cstare[NMAX+5];
int infectabil[NMAX+5];
int neinfectabil[NMAX+5];
int cntintalniri[NMAX+5];
pair<int,int> t[NMAX+5];

int main(){
    fi>>c>>n>>m;
    for(int i=1;i<=n;i++){
        fi>>stare[i];
        infectabil[i]=cstare[i]=stare[i];
    }
    for(int i=1;i<=m;i++){
        fi>>sir[i].first>>sir[i].second;
    }
    for(int i=m;i>=1;i--){
        if(cstare[sir[i].first]==0||cstare[sir[i].second]==0){
            infectabil[sir[i].first]=0;
            infectabil[sir[i].second]=0;
            cstare[sir[i].first]=0;
            cstare[sir[i].second]=0;
        }
    }
    if(c==1){
        for(int i=1;i<=n;i++){
            fo<<infectabil[i];
        }
    }else{
        for(int i=1;i<=n;i++){
            if(infectabil[i]){
                t[i].first=i;
            }
            neinfectabil[i]=1;
        }
        for(int i=1;i<=m;i++){
            if(stare[sir[i].first]&&stare[sir[i].second]){
                pair <int,int> reun;
                reun.first=t[sir[i].first].first;
                reun.second=t[sir[i].second].first;
                if(reun.first==reun.second){
                    reun.second=0;
                }
                if(reun.first==0){
                    reun.first=reun.second;
                    reun.second=0;
                }
                if(reun.second==0){
                    reun.second=t[sir[i].second].second;
                }
                if(reun.second==0){
                    reun.second=t[sir[i].first].second;
                }
                t[sir[i].first]=t[sir[i].second]=reun;
            }
        }        
        for(int i=1;i<=n;i++){
            if(stare[i]&&t[i].first!=0&&t[i].second==0){
                neinfectabil[t[i].first]=0;
            }
        }
        for(int i=1;i<=n;i++){
            fo<<neinfectabil[i];
        }
    }
    fi.close();
    fo.close();
}