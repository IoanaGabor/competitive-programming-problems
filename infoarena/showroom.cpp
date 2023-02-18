
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#define MMAX 50000
#define MOD 9001

using namespace std;

ifstream f("showroom.in");
ofstream g("showroom.out");

int n,a,r,k,dim,ncuv,parent[MMAX+5],frecventa[MMAX+5],ngr,lc,rez1,rez2,sir[MMAX+5],nrmodele[MMAX+5],ciur[MMAX+5],prime[MMAX+5],exp[MMAX+5],lprime;
string linie,cuvant,cuvinte[105];
map<string,int> mp;
map<string,int>::iterator it;

int parinte(int x){
    if(parent[x]==x){
        return x;
    }
    parent[x]=parinte(parent[x]);
    return parent[x];
}

int putere(int baza,int exp){
    int r=1;
    while(exp){
        if(exp%2==0){
            exp/=2;
            baza=(baza*baza)%MOD;
        }else{
            exp--;
            r=(r*baza)%MOD;
        }
    }
    return r;
}

int combinari(int nn,int kk){
    int aux1=1,aux2=1,cnt=0,ci;
    for(int i=2;i<=nn;i++){
        if(i<=kk&&i<=nn-kk){
            if(i%MOD==0){
                ci=i;
                while(ci%MOD==0){
                    cnt--;
                    ci=ci/MOD;
                }
                aux1=(aux1*ci)%MOD;
            }else{
                aux1=(aux1*i)%MOD;
            }
        }else if(i>kk&&i>(nn-kk)){
            if(i%MOD==0){
                ci=i;
                while(ci%MOD==0){
                    cnt++;
                    ci=ci/MOD;
                }
                aux2=(aux2*ci)%MOD;
            }else{
                aux2=(aux2*i)%MOD;
            }
        }
    }
    if(cnt!=0){
        return 0;
    }
    aux1=putere(aux1,MOD-2);
    return (aux1*aux2)%MOD;
}

int main(){
    f>>n>>a>>r>>k;
    f.get();
    for(int i=1;i<=MMAX;i++){
        parent[i]=i;
    }
    for(int i=1;i<=n;i++){
        getline(f,linie);
        dim=linie.size();
        lc=0;
        for(int j=0;j<dim;j++){
            if(linie[j]!=' '){
                cuvant.push_back(linie[j]);
            }else{
                if(j+1!=dim&&linie[j+1]!=' '){
                    cuvinte[++lc]=cuvant;
                    cuvant.clear();
                }
            }
        }
        if(cuvant!=""){
            cuvinte[++lc]=cuvant;
            cuvant.clear();
        }
        if(mp[cuvinte[1]]==0){
            mp[cuvinte[1]]=++ncuv;
        }
        ngr=parinte(mp[cuvinte[1]]);

        for(int j=2;j<=lc;j++){
            if(mp[cuvinte[j]]==0){
                mp[cuvinte[j]]=++ncuv;
            }
            if(parent[mp[cuvinte[j]]]!=ngr){
                int p1=parinte(mp[cuvinte[j]]);
                if(p1<ngr){
                    parent[ngr]=p1;
                    ngr=p1;
                }else{
                    parent[p1]=ngr;
                }
            }
        }
    }
    for(it=mp.begin();it!=mp.end();it++){
        if(frecventa[parinte((*it).second)]==0){
            rez1++;
        }
        frecventa[parent[(*it).second]]++;
    }
    g<<rez1<<'\n';
    rez1=0;
    for(int i=1;i<=MMAX;i++){
        if(frecventa[i]){
            nrmodele[++rez1]=frecventa[i];
        }
    }
    rez2=1;
    for(int i=1;i<=rez1;i++){
        if(nrmodele[i]>=a){
            rez2=(rez2*combinari(nrmodele[i],a))%MOD;

        }
        a=(a+r)%k;
    }
    g<<rez2<<'\n';
    f.close();
    g.close();
}

