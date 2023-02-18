
#include <iostream>
#include <fstream>
#define NMAX 5

using namespace std;

ifstream f("magic.in");
ofstream g("magic.out");

int cerinta,n,o[NMAX+3],v[NMAX+3],matrice[NMAX+3][NMAX+3],rmin[NMAX+3][NMAX+3],et[2*NMAX+3],ok,cnt,aux[NMAX+3];
pair <int,int> ind[2*NMAX+3];

bool bine(int k,int nr){
    if(ind[k].second==0){
        for(int i=1;i<=n;i++){
            aux[i]=matrice[ind[k].first][i];
        }
    }else{
        for(int i=1;i<=n;i++){
            aux[i]=matrice[i][ind[k].first];
        }
    }
    for(int i=1;i<=n;i++){
        if(nr&(1<<(n-i))){
            if(aux[i]==1){
                return false;
            }else{
                aux[i]=9;
            }
        }else{
            if(aux[i]==9){
                return false;
            }else{
                aux[i]=1;
            }
        }
    }
    if(ind[k].second==0){
        for(int i=1;i<=n;i++){
            matrice[ind[k].first][i]=aux[i];
        }
    }else{
        for(int i=1;i<=n;i++){
            matrice[i][ind[k].first]=aux[i];
        }
    }
    return true;
}

void sterge(int k){
    if(ind[k].second==0){
        for(int i=1;i<=n;i++){
            if(v[i]>k){
                matrice[ind[k].first][i]=0;
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            if(o[i]>k){
                matrice[i][ind[k].first]=0;
            }
        }
    }
}

void bkt(int k){
    if(k==2*n+1){
        if(!ok){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    rmin[i][j]=matrice[i][j];
                }
            }
            ok=1;
        }
        cnt++;
        return;
    }
    for(int i=et[k-1]+1;i+(2*n-k)<=(1<<n)-1;i++){
        if(bine(k,i)){
            et[k]=i;
            bkt(k+1);
            sterge(k);
        }
    }
}

int main(){
    f>>cerinta>>n;
    for(int i=1;i<=n;i++){
        f>>o[i];
        ind[o[i]].first=i;
        ind[o[i]].second=0;
    }
    for(int i=1;i<=n;i++){
        f>>v[i];
        ind[v[i]].first=i;
        ind[v[i]].second=1;
    }
    et[0]=-1;
    bkt(1);
    if(cerinta==1){
        g<<cnt;
    }else{
        for(int i=1;i<=2*n;i++){
            for(int j=1;j<=n;j++){
                if(ind[i].second==0){
                    g<<rmin[ind[i].first][j];
                }else{
                    g<<rmin[j][ind[i].first];
                }
            }
        }
    }
    f.close();
    g.close();
}
