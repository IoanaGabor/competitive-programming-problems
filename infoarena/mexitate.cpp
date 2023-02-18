///int in loc de long long
#include <iostream>
#include <fstream>
#include <vector>
#define MAXVAL 400000
#define RADICAL 633
#define MOD 1000000007

using namespace std;

ifstream f("mexitate.in");
ofstream g("mexitate.out");

int n,m,k,l;
vector <vector<int> > matrice;
int este[MAXVAL+5],bucati_rad[RADICAL+5],x,y,mex;
long long produs;

void adauga(int val){
    este[val]++;
    if(este[val]==1){
        bucati_rad[val/RADICAL]++;
    }
}

void sterge(int val){
    if(este[val]){
        este[val]--;
    }
    if(este[val]==0){
        bucati_rad[val/RADICAL]--;
    }
}

int cauta(){
    for(int i=0;i<=RADICAL;i++){
        if(bucati_rad[i]!=RADICAL){
            for(int j=i*RADICAL+1;j<(i+1)*RADICAL;j++){
                if(!este[j]){
                    return j;
                }
            }
        }
    }
}

int main(){
    f>>n>>m>>k>>l;
    if(k>l){
        swap(k,l);
        swap(n,m);
        matrice.resize(n+1, vector<int>(m+1));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                f>>matrice[j][i];
            }
        }
    }else{
        matrice.resize(n+1, vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f>>matrice[i][j];
            }
        }
    }
    produs=1;
    for(int i=k;i<=n;i++){
        if(i==k){
            for(int i=1;i<=k;i++){
                for(int j=1;j<=l;j++){
                    adauga(matrice[i][j]);
                }
            }
            mex=cauta();
            produs=(1LL*produs*mex)%MOD;
        }else{
            for(int j=1;j<=l;j++){
                sterge(matrice[i-k][j]);
                adauga(matrice[i][j]);
            }
            mex=cauta();
            produs=(1LL*produs*mex)%MOD;
        }
        for(int j=l+1;j<=m;j++){
            for(int ii=i-k+1;ii<=i;ii++){
                sterge(matrice[ii][j-l]);
                adauga(matrice[ii][j]);
            }
            mex=cauta();
            produs=(1LL*produs*mex)%MOD;
        }
        i++;
        if(i<=n){
            for(int j=1;j<=l;j++){
                sterge(matrice[i-k][m-l+j]);
                adauga(matrice[i][m-l+j]);
            }
            mex=cauta();
            produs=(1LL*produs*mex)%MOD;
            for(int j=m;j>l;j--){
                for(int ii=i-k+1;ii<=i;ii++){
                    sterge(matrice[ii][j]);
                    adauga(matrice[ii][j-l]);
                }
                mex=cauta();
                produs=(produs*mex)%MOD;
            }
        }
    }
    g<<produs;
    f.close();
    g.close();
}

