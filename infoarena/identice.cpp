
#include <iostream>
#include <fstream>
#define NMAX 1000

using namespace std;

ifstream f("identice.in");
ofstream g("identice.out");

int cerinta,n,d,nrunu[NMAX+5][NMAX+5],mars[NMAX+5][NMAX+5];
char mat[NMAX+5][NMAX+5];

long long cerinta_unu(){
    long long ret=0,r;
    int stiva[NMAX+5],top,st[NMAX+5];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mat[i][j]=='1'){
                nrunu[i][j]=1+nrunu[i][j-1];
            }else{
                nrunu[i][j]=0;
            }
        }
    }
    for(int j=1;j<=n;j++){
        stiva[0]=top=st[0]=0;
        for(int i=1;i<=n;i++){
            while(top&&nrunu[stiva[top]][j]>=nrunu[i][j]){
                top--;
            }
            st[i]=nrunu[i][j]*(i-stiva[top])+st[stiva[top]];
            ret+=st[i];
            stiva[++top]=i;
        }
    }
    return ret;
}

long long cerinta_doi(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mars[i][j]=0;
        }
    }
    long long ret=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mars[i][j]+=mars[i-1][j]+mars[i][j-1]-mars[i-1][j-1];
            if((mat[i][j]=='1'&&mars[i][j]%2==1)||(mat[i][j]=='0'&&mars[i][j]%2==0)){
                if(i+d-1>n||j+d-1>n){
                    return -1;
                }
                mars[i][j]++;
                mars[i+d][j+d]++;
                mars[i][j+d]--;
                mars[i+d][j]--;
                ret++;
            }
        }
    }
    return ret;
}

int main(){
    f>>cerinta>>n>>d;
    for(int i=1;i<=n;i++){
        f>>(mat[i]+1);
    }
    if(cerinta==1){
        long long rez=cerinta_unu();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mat[i][j]='0'+'1'-mat[i][j];
            }
        }
        rez+=cerinta_unu();
        g<<rez<<'\n';
    }else if(cerinta==2){
        long long rez1=cerinta_doi(),rez2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mat[i][j]='0'+'1'-mat[i][j];
            }
        }
        rez2=cerinta_doi();
        if(rez1==-1&&rez2==-1){
            g<<-1<<'\n';
        }else if(rez1==-1){
            g<<rez2<<'\n';
        }else if(rez2==-1){
            g<<rez1<<'\n';
        }else{
            g<<min(rez1,rez2)<<'\n';
        }
    }
    f.close();
    g.close();
}
