
#include <iostream>
#include <fstream>
#include <cstring>
#define NMAX 200
#define MOD 1000003
#define MAXVAL (1LL<<30)-1

using namespace std;

ifstream f("text2.in");
ofstream g("text2.out");

char sir[NMAX+5];
int n,nrp[NMAX+5][NMAX+5],arm[NMAX+5][NMAX+5],prec[NMAX+5][NMAX+5],l,rez1,uv[NMAX+5];

bool vocala(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='y'){
        return true;
    }
    return false;
}


void afis(int x,int nr){
    if(nr!=0){
        afis(prec[x][nr],nr-1);
        for(int i=prec[x][nr]+1;i<=x;i++){
            g<<sir[i];
        }
        g<<' ';
    }
}


int main(){
    f>>(sir+1);
    f>>n;
    l=strlen(sir+1);
    for(int i=1;i<=l;i++){
        for(int j=0;j<=n;j++){
            arm[i][j]=MAXVAL;
            arm[0][j]=MAXVAL;
        }
        if(i==1){
            if(vocala(sir[i])){
                uv[i]=1;
            }else{
                uv[i]=-1;
            }
        }else{
            if(vocala(sir[i])){
                uv[i]=i;
            }else{
                uv[i]=uv[i-1];
            }
        }
    }
    nrp[0][0]=1;
    arm[0][0]=0;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=l;i++){
            if(uv[i]!=-1&&i-uv[i]+1<=20){
                for(int ii=max(1,i-19);ii<=uv[i];ii++){
                    nrp[i][j]=(nrp[i][j]+nrp[ii-1][j-1])%MOD;
                    if(arm[i][j]>arm[ii-1][j-1]+(i-ii+1)*(i-ii+1)){
                        arm[i][j]=arm[ii-1][j-1]+(i-ii+1)*(i-ii+1);
                        prec[i][j]=ii-1;
                    }
                }
            }
        }
    }
    g<<nrp[l][n]<<'\n';
    g<<arm[l][n]<<'\n';
    afis(l,n);
    f.close();
    g.close();
}
