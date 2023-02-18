
#include <iostream>
#include <fstream>
#include <cmath>
#define NMAX 100000
#define KMAX 1000
#define SMAX 1000

using namespace std;

ifstream f("telecab.in");
ofstream g("telecab.out");

int n,k,s,h[NMAX+5],nextt[NMAX+5],lung,t[KMAX+5][SMAX+5];
int stiva[NMAX+5],top;

int calc_dist(int x1,int y1,int x2,int y2){
    return (int)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int timp(int c,int b){
    if(b<0){
        return (1<<30);
    }
    if(c>=k){
        return 0;
    }
    if(t[c][b]){
        return t[c][b];
    }
    if(h[c]<=h[nextt[c]]){
        t[c][b]=timp(nextt[c],b-(h[nextt[c]]-h[c]))+calc_dist(c,h[c],nextt[c],h[nextt[c]]);
    }else{
        t[c][b]=min(timp(nextt[c],b+(h[nextt[c]]-h[c]))+1,timp(nextt[c],b)+calc_dist(c,h[c],nextt[c],h[nextt[c]]));
    }
    return t[c][b];
}

int main(){
    f>>n>>k>>s;
    for(int i=1;i<=n;i++){
        f>>h[i];
        nextt[i]=i+1;
    }
    stiva[++top]=1;
    for(int i=2;i<=n;i++){
        while(top&&h[i]>h[stiva[top]]){
            nextt[stiva[top]]=i;
            top--;
        }
        stiva[++top]=i;
    }
    for(int i=1;i<n;i=nextt[i]){
        lung+=calc_dist(i,h[i],nextt[i],h[nextt[i]]);
    }
    g<<lung<<'\n';
    g<<timp(1,s);
    f.close();
    g.close();
}
