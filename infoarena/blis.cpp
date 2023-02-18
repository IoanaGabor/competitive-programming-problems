
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#define NMAX 100000
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("blis.in");
ofstream g("blis.out");

int n,k,best[NMAX+5],lb;
vector <pair<int,int> > update[NMAX+5];
char sir[NMAX+5];

void unu(){
    int nr=0,rez=0;
    for(int i=1;i<=min(n,k);i++){
        nr=(nr<<1)+(sir[i]-'0');
        best[i]=MAXVAL;
    }
    if(n<=k){
        g<<nr<<'\n';
        return;
    }
    rez=nr;
    for(int i=k+1;i<=n;i++){
        if((nr>>(k-1))&1){
            nr=nr-(1<<(k-1));
            best[i]=MAXVAL;
        }
        nr=(nr<<1)+(sir[i]-'0');
        rez=max(rez,nr);
    }
    g<<rez<<'\n';
    return;
}

int cauta_poz(int nr){
    int pas=(1<<17),ret=0;
    while(pas){
        if(ret+pas<=lb&&best[ret+pas]<=nr){
            ret+=pas;
        }
        pas>>=1;
    }
    return ret;
}

void doi(){
    int nr,p;
    best[0]=-1;
    for(int i=1;i<=n;i++){
        nr=0;
        for(int j=i;j<=min(i+k-1,n);j++){
            nr=(nr<<1)+(sir[j]-'0');
            p=cauta_poz(nr);
            if(best[p]!=nr){
                update[j].push_back(make_pair(p+1,nr));
            }
        }
        for(int j=0;j<update[i].size();j++){
            if(update[i][j].first>lb&&update[i][j].second!=best[lb]){
                //cout<<i<<' '<<update[i][j].first<<' '<<update[i][j].second<<'\n';
                best[++lb]=update[i][j].second;
            }else if(best[update[i][j].first]>update[i][j].second&&best[update[i][j].first-1]!=update[i][j].second){
                best[update[i][j].first]=update[i][j].second;
            }
        }
    }
    //for(int i=1;i<=lb;i++){
        //cout<<i<<' '<<best[i]<<'\n';
    //}
    g<<lb<<'\n';
}

int main(){
    f>>k;
    f>>(sir+1);
    n=strlen(sir+1);
    unu();
    doi();
    f.close();
    g.close();
}
