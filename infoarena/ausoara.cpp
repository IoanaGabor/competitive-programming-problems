
#include <bits/stdc++.h>
#define MMAX 1000

using namespace std;

ifstream fi("ausoara.in");
ofstream fo("ausoara.out");

int n,m;
int a[MMAX+5];
int rez[MMAX+5],lr;
int aux[MMAX+5],la;

void cmlsc(){
    int i=1,j=1;
    la=0;
    while(i<=m&&j<=lr){
        if(a[i]==rez[j]){
            aux[++la]=a[i];
            i++;
            j++;
        }else if(a[i]<rez[j]){
            i++;
        }else{
            j++;
        }
    }   
    for(int i=1;i<=la;i++){
        rez[i]=aux[i];
    }
    lr=la;
}

int main(){
    fi>>n;
    for(int i=1;i<=n;i++){
        fi>>m;
        for(int j=1;j<=m;j++){
            fi>>a[j];
        }
        if(i==1){
            for(int j=1;j<=m;j++){
                rez[++lr]=a[j];
            }
        }else{
            cmlsc();
        }
    }
    fo<<lr<<' ';
    for(int i=1;i<=lr;i++){
        fo<<rez[i]<<' ';
    }
    fi.close();
    fo.close();
}