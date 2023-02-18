
///am afisat pe ecran in loc sa afisez in fisier:(
#include <bits/stdc++.h>
#define NMAX 50

using namespace std;

ifstream fi("rfinv.in");
ofstream fo("rfinv.out");

int t,n,m;
int mch[NMAX+5][NMAX+5], d[NMAX+5][NMAX+5];
int x,y;

void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mch[i][j]=d[i][j]=0;
        }
    }
}

bool check(){
    bool f;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            f=false;
            for(int k=1;k<=n;k++){
                if(k!=i&&k!=j){
                    if(d[i][j]>d[i][k]+d[k][j]){
                        return false;
                    }
                    if(d[i][j]==d[i][k]+d[k][j]){
                        f=true;
                    }
                }
            }
            if(!f&&!mch[i][j]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    fi>>t;
    while(t--){
        fi>>n>>m;
        init();
        for(int i=1;i<=m;i++){
            fi>>x>>y;
            mch[x][y]=mch[y][x]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                fi>>d[i][j];
            }
        }
        if(check()){
            fo<<"DA"<<'\n';
        }else{
            fo<<"NU"<<'\n';
        }
    }    
    fi.close();
    fo.close();
}
