
#include <bits/stdc++.h>
#define NMAX 30001
#define KMAX 10
#define MOD 997

using namespace std;

ifstream fi("namlei.in");
ofstream fo("namlei.out");

int n,K,X,Y;
struct matrice{
    int m[KMAX][KMAX];
} aint[4*NMAX],sol;
int cnt,ind,j,k,x,y;
int nj,nk;

matrice inmultire(matrice a,matrice b){
    matrice ret;
    for(int ii=0;ii<K;ii++){
        for(int jj=0;jj<K;jj++){
            ret.m[ii][jj]=0;
            for(int kk=0;kk<K;kk++){
                ret.m[ii][jj]=(ret.m[ii][jj]+a.m[ii][kk]*b.m[kk][jj])%MOD;
            }
        }
    }
    return ret;
}

void get_matrice(int nod){
    fi>>cnt>>j>>k;
    for(int ii=0;ii<K;ii++){
        for(int jj=0;jj<K;jj++){
            aint[nod].m[ii][jj]=1;
        }
    }
    aint[nod].m[j][k]++;
    for(int w=1;w<cnt;w++){
        nj=(j*X+k*w*Y)%K;
        nk=(j*w*X+k*Y)%K;
        j=nj;
        k=nk;
        aint[nod].m[j][k]++;
    }
}

void update_matrice(int nod){
    for(int ii=0;ii<K;ii++){
        for(int jj=0;jj<K;jj++){
            aint[nod].m[ii][jj]=1;
        }
    }
    aint[nod].m[j][k]++;
    for(int w=1;w<cnt;w++){
        nj=(j*X+k*w*Y+1)%K;
        nk=(j*w*X+k*Y+1)%K;
        j=nj;
        k=nk;
        aint[nod].m[j][k]++;
    }
}

void build(int nod,int st,int dr){
    if(st==dr){
        get_matrice(nod);
        return;
    }
    int mij=(st+dr)/2;
    build(nod*2,st,mij);
    build(nod*2+1,mij+1,dr);
    aint[nod]=inmultire(aint[nod*2],aint[nod*2+1]);
}

void update(int nod,int st,int dr,int poz){
    if(st==dr){
        update_matrice(nod);
        return;
    }
    int mij=(st+dr)/2;
    if(poz<=mij){
        update(nod*2,st,mij,poz);
    }else{
        update(nod*2+1,mij+1,dr,poz);
    }
    aint[nod]=inmultire(aint[nod*2],aint[nod*2+1]);
}

void query(int nod,int st,int dr,int i1,int i2){
    if(i1<=st&&dr<=i2){
        sol=inmultire(sol,aint[nod]);
        return;
    }
    int mij=(st+dr)/2;
    if(i1<=mij){
        query(nod*2,st,mij,i1,i2);
    }
    if(mij<i2){
        query(nod*2+1,mij+1,dr,i1,i2);
    }
}

void solve(){
    fi>>n>>K;
    fi>>X>>Y;
    build(1,1,n);
    char cer;
    while(fi>>cer){
        if(cer=='U'){
            fi>>ind>>cnt>>j>>k;
            ind++;
            update(1,1,n,ind);
        }else{
            fi>>ind>>x>>j>>y;
            for(int ii=0;ii<K;ii++){
                for(int jj=0;jj<K;jj++){
                    if(ii==jj){
                        sol.m[ii][jj]=1;
                    }else{
                        sol.m[ii][jj]=0;
                    }
                }
            }
            query(1,1,n,ind+1,j);
            fo<<sol.m[x][y]<<'\n';
        }
    }
}

int main(){
    solve();
    fi.close();
    fo.close();
}