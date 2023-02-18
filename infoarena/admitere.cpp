
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#define NMAX 2001

using namespace std;

ifstream f("admitere.in");
ofstream g("admitere.out");

short int cerinta,n,m,pr[NMAX],pu[NMAX],ir[NMAX],iu[NMAX],ore[NMAX],oum[NMAX],rez[NMAX],aux[NMAX],indr[NMAX],indu[NMAX],maxim,spatiu,adm;
string ch="XRU";

short int cautare(short int sir[],int val){
    if(sir[m]<val){
        return m;
    }
    short int pas=1<<11,r=0;
    while(pas){
        if(r+pas<=m&&sir[r+pas]<val){
            r+=pas;
        }
        pas>>=1;
    }
    return r;
}

bool critre(int a,int b){
    return pr[a]<pr[b];
}

bool critum(int a,int b){
    return pu[a]<pu[b];
}

void contor_real(int x){
    adm=0;
    spatiu=indr[ore[x]];
    memset(aux,0,sizeof aux);
    if(spatiu>0){
        spatiu--;
        adm++;
        aux[ore[x]]=1;
    }
    for(int i=1;i<=n&& spatiu;i++){
        if(pr[oum[i]]>pr[ore[x]]){
            spatiu--;
            adm++;
            aux[oum[i]]=1;
        }
    }
    spatiu=0;
    for(int i=n;i>=1;i--){
        if(indu[oum[i]]>spatiu&& aux[oum[i]]==0){
            aux[oum[i]]=2;
            spatiu++;
            adm++;
        }
    }
}

void contor_uman(int x){
    adm=0;
    spatiu=indu[oum[x]];
    memset(aux,0,sizeof aux);
    if(spatiu>0){
        spatiu--;
        adm++;
        aux[oum[x]]=2;
    }
    for(int i=1;i<=n&& spatiu;i++){
        if(pu[ore[i]]>pu[oum[x]]){
            spatiu--;
            adm++;
            aux[ore[i]]=2;
        }
    }
    spatiu=0;
    for(int i=n;i>=1;i--){
        if(indr[ore[i]]>spatiu&& aux[ore[i]]==0){
            aux[ore[i]]=1;
            spatiu++;
            adm++;
        }
    }
}


int main(){
    f>>cerinta>>n>>m;
    for(int i=1;i<=m;i++){
        f>>ir[i];
    }
    for(int i=1;i<=m;i++){
        f>>iu[i];
    }
    for(int i=1;i<=n;i++){
        f>>pr[i]>>pu[i];
        ore[i]=oum[i]=i;
        indr[i]=cautare(ir,pr[i]);
        indu[i]=cautare(iu,pu[i]);
    }
    sort(ore+1,ore+n+1,critre);
    sort(oum+1,oum+n+1,critum);
    if(cerinta==1){
        int contor1=0;
        for(int i=n;i>=1;i--){
            if(indr[ore[i]]>contor1){
                contor1++;
                rez[ore[i]]=1;
            }
        }
        int contor2=0;
        for(int i=n;i>=1;i--){
            if(indu[oum[i]]>contor2){
                contor2++;
                aux[oum[i]]=2;
            }
        }
        if(contor1<contor2){
            g<<contor2<<'\n';
            for(int i=1;i<=n;i++){
                g<<ch[aux[i]];
            }
        }else{
            g<<contor1<<'\n';
            for(int i=1;i<=n;i++){
                g<<ch[rez[i]];
            }
        }
        f.close();
        g.close();
        return 0;
    }
    for(int i=1;i<=n;i++){
        contor_real(i);
        if(adm>maxim){
            maxim=adm;
            for(int j=1;j<=n;j++){
                rez[j]=aux[j];
            }
        }
        contor_uman(i);
        if(adm>maxim){
            maxim=adm;
            for(int j=1;j<=n;j++){
                rez[j]=aux[j];
            }
        }
    }
    g<<maxim<<'\n';
    for(int i=1;i<=n;i++){
        g<<ch[rez[i]];
    }
    f.close();
    g.close();
}
