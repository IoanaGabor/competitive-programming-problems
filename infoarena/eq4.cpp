
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#define NMAX 100000
#define DIMMAX 1000000
using namespace std;

ifstream f("eq4.in");
ofstream g("eq4.out");

long long cerinta,n,cx,cy,cz,ct,tl,gn,a,b,e,cnt,aux,lv;
char sir[NMAX+5];
long long v[DIMMAX];

void get_number(int& i){
    gn=0;
    while(i<n&&sir[i]<='9'&&sir[i]>='0'){
        gn=gn*10+(sir[i]-'0');
        i++;
    }
    i--;
}

int nrap(int val){
    int pas=1<<30,rez=0;
    while(pas){
        if(rez+pas<=lv&&v[rez+pas]<=val){
            rez+=pas;
        }
        pas>>=1;
    }
    while(v[rez]==val&&rez>=1){
        pas++;
        rez--;
    }
    return pas;
}

int main(){
    f>>cerinta>>sir>>a>>b>>e;
    n=strlen(sir);
    for(int i=0;i<n;i++){
        gn=0;
        if(sir[i]=='-'){
            i++;
            if(sir[i]<='9'&&sir[i]>='0'){
                get_number(i);
                gn=-gn;
                if(i==n-1){
                    tl+=gn;
                    break;
                }
                if(sir[i+1]=='x'){
                    cx+=gn;
                    i++;
                }else if(sir[i+1]=='y'){
                    cy+=gn;
                    i++;
                }else if(sir[i+1]=='z'){
                    cz+=gn;
                    i++;
                }else if(sir[i+1]=='t'){
                    ct+=gn;
                    i++;
                }else{
                    tl+=gn;
                }
            }else{
                gn=-1;
                if(sir[i]=='x'){
                    cx+=gn;
                }else if(sir[i]=='y'){
                    cy+=gn;
                }else if(sir[i]=='z'){
                    cz+=gn;
                }else if(sir[i]=='t'){
                    ct+=gn;
                }
            }
        }else{
            i++;
            if(sir[i]<='9'&&sir[i]>='0'){
                get_number(i);
                if(i==n-1){
                    tl+=gn;
                    break;
                }
                if(sir[i+1]=='x'){
                    cx+=gn;
                    i++;
                }else if(sir[i+1]=='y'){
                    cy+=gn;
                    i++;
                }else if(sir[i+1]=='z'){
                    cz+=gn;
                    i++;
                }else if(sir[i+1]=='t'){
                    ct+=gn;
                    i++;
                }else{
                    tl+=gn;
                }
            }else{
                gn=1;
                if(sir[i]=='x'){
                    cx+=gn;
                }else if(sir[i]=='y'){
                    cy+=gn;
                }else if(sir[i]=='z'){
                    cz+=gn;
                }else if(sir[i]=='t'){
                    ct+=gn;
                }
            }
        }
    }
    if(cerinta==1){
        g<<cx+cy+cz+ct+tl<<'\n';
        f.close();
        g.close();
        return 0;
    }
    for(int i=a;i<=b;i++){
        for(int j=a;j<=b;j++){
            aux=cx*1LL*i+cy*1L*j;
            v[++lv]=aux;
        }
    }
    sort(v+1,v+lv+1);
    for(int i=a;i<=b;i++){
        for(int j=a;j<=b;j++){
            aux=e-tl-cz*1LL*i-ct*1LL*j;
            cnt+=nrap(aux);
        }
    }
    g<<cnt;
    f.close();
    g.close();
}
