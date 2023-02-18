
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("clepsidru.in");
ofstream g("clepsidru.out");

int n,b,k,timp,stare,s,j,bs,bj;
pair <int,int> rez[1005];

int main(){
    f>>n>>b>>k;
    s=0;
    j=0;
    bs=b;
    bj=1;
    for(int i=1;i<=k;i++){
        f>>timp>>stare;
        if(stare==1){
            j+=timp;
            if(j>=n){
                bj=bj+j-n;
                j=n;
                if(bj>=b){
                    s=n;
                    bj=b;
                    bs=1;
                }else{
                    bs=b-bj-n+1;
                    s=0;
                    if(bs<=0){
                        s=-bs+1;
                        bs=1;
                    }
                }
            }else{
                bj=1;
                bs=b-j;
                if(bs<=0){
                    s=-bs+1;
                    bs=1;
                }
            }
        }else{
            s-=timp;
            if(s>0){
                bs=1;
                bj=b-n+s;
                if(bj<=0){
                    j=n+bj-1;
                    bj=1;
                }
            }else{
                bs-=s;
                s=0;
                if(bs>=b){
                    bj=1;
                    j=0;
                    bs=b;
                }else{
                    bj=b-bs-n+1;
                    j=n;
                    if(bj<=0){
                        j=n+bj-1;
                        bj=1;
                    }
                }
            }
        }
    }
    if(s==0&& j==n&& stare==1){
        rez[1].first=bs;
        rez[n].second=bj;
        for(int i=2;i<=n;i++){
            rez[i].first=1;
        }
    }else if(s==0&& j==n&& stare==2){
        rez[1].first=bs;
        rez[n].second=bj;
        for(int i=1;i<n;i++){
            rez[i].second=1;
        }
    }else if(s==0&&j==0){
        rez[1].first=bs;
    }else if(s==n&&j==n){
        rez[n].second=bj;
    }else if(s==0&&j<n&&stare==1){
        rez[1].first=bs;
        for(int i=2;i<=j+1;i++){
            rez[i].first=1;
        }
    }else if(s==0&&j<n&&stare==2){
        rez[1].first=bs;
        for(int i=1;i<=j;i++){
            rez[i].second=1;
        }
    }else if(s>0&&j==n&&stare==1){
        rez[n].second=bj;
        for(int i=s+1;i<=n;i++){
            rez[i].first=1;
        }
    }else if(s>0&&j==n&&stare==2){
        rez[n].second=bj;
        for(int i=s;i<n;i++){
            rez[i].second=1;
        }
    }else if(s>0&&j<n&&stare==1){
        for(int i=s+1;i<=j+1;i++){
            rez[i].first=1;
        }
    }else if(s>0&&j<n&& stare==2){
        for(int i=s;i<=j;i++){
            rez[i].second=1;
        }
    }
    g<<n+b-1<<'\n';
    for(int i=1;i<=n;i++){
        g<<rez[i].first<<' '<<rez[i].second<<'\n';
    }
    f.close();
    g.close();
}
