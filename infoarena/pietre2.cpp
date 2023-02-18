
#include <iostream>
#include <fstream>
#define NMAX 100

using namespace std;

ifstream f("pietre2.in");
ofstream g("pietre2.out");

int n,patrat[NMAX+5][NMAX+5],l[NMAX+5][NMAX+5];
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};

void citire(){
    f>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f>>patrat[i][j];
        }
    }
}

void construieste_l(int i,int j){
    if(l[i][j]>0){
        return;
    }
    int ii,jj;
    for(int k=0;k<4;k++){
        ii=i+dx[k];
        jj=j+dy[k];
        if(ii<=n&&1<=ii&&jj<=n&&1<=jj&&patrat[ii][jj]==patrat[i][j]+1){
            construieste_l(ii,jj);
            l[i][j]=max(l[i][j],l[ii][jj]+1);
        }
    }
}

int main(){
    citire();
    int sol=0,si=0,sj=0;
    for(int i=1;i<=n;i++){
        construieste_l(1,i);
        construieste_l(i,n);
        construieste_l(i,1);
        construieste_l(n,i);
        if(sol<l[1][i]){
            sol=l[1][i];
            si=1;
            sj=i;
        }
        if(sol<l[i][n]){
            sol=l[i][n];
            si=i;
            sj=n;
        }
        if(sol<l[i][1]){
            sol=l[i][1];
            si=i;
            sj=1;
        }
        if(sol<l[n][i]){
            sol=l[n][i];
            si=n;
            sj=i;
        }
    }
    g<<sol<<'\n'<<si<<' '<<sj<<'\n';
    f.close();
    g.close();
}
