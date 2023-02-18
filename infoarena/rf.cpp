
#include <bits/stdc++.h>
#define NMAX 256

using namespace std;

ifstream fi("rf.in");
ofstream fo("rf.out");

int n;
int dist[NMAX+5][NMAX+5];
int nrdr[NMAX+5][NMAX+5];

int main(){
    fi>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            fi>>dist[i][j];
            nrdr[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        nrdr[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(k!=i&&k!=j){
                    if(dist[i][j]>dist[i][k]+dist[k][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                        nrdr[i][j]=nrdr[i][k]+nrdr[k][j];
                    }else if(dist[i][j]==dist[i][k]+dist[k][j]){
                        nrdr[i][j]=max(nrdr[i][k]+nrdr[k][j],nrdr[i][j]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            fo<<dist[i][j]<<' ';
        }
        fo<<'\n';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            fo<<nrdr[i][j]<<' ';
        }
        fo<<'\n';
    }
}