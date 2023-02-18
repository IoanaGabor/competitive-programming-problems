
#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("diff.in");
ofstream fo("diff.out");

int n,t;
int bf[NMAX+5],s[NMAX+5];
int ap[2*NMAX+5],le[2*NMAX+5],ri[2*NMAX+5];
int mini,maxi,imini,imaxi;
int k;

int main(){
    fi>>n>>t;
    for(int i=1;i<=n;i++){
        fi>>bf[i];
        if(!bf[i]){
            bf[i]--;
        }
        s[i]=s[i-1]+bf[i];
    }
    mini=maxi=0;
    imini=imaxi=0;
    for(int i=1;i<=n;i++){
        if(!ap[NMAX+s[i]-mini]){
            ap[NMAX+s[i]-mini]=1;
            le[NMAX+s[i]-mini]=imini+1;
            ri[NMAX+s[i]-mini]=i;
        }
        if(!ap[NMAX+s[i]-maxi]){
            ap[NMAX+s[i]-maxi]=1;
            le[NMAX+s[i]-maxi]=imaxi+1;
            ri[NMAX+s[i]-maxi]=i;
        }
        if(s[i]<mini){
            mini=s[i];
            imini=i;
        }
        if(s[i]>maxi){
            maxi=s[i];
            imaxi=i;
        }
    }
    while(t--){
        fi>>k;
        if(!ap[NMAX+k]){
            fo<<-1<<'\n';
        }else{
            fo<<le[NMAX+k]<<' '<<ri[NMAX+k]<<'\n';
        }
    }
    fi.close();
    fo.close();
}