
#include <iostream>
#include <fstream>
#define NMAX 10000

using namespace std;

ifstream f("perle.in");
ofstream g("perle.out");

int q,n,sir[NMAX+5];

bool corect(char ch,int& i){
    if(i<=n){
        if(ch=='A'){
            i++;
            return true;
        }else if(ch=='B'){
            int j=i,ok=1;
            if(sir[j]==2){
                j++;
                if(!corect('B',j)){
                    ok=0;
                }
            }else if(sir[j]==1){
                j++;
                if(!corect('A',j)){
                    ok=0;
                }
                if(ok==1&&sir[j]==3){
                    j++;
                    if(!corect('A',j)){
                        ok=0;
                    }
                    if(ok==1&&!corect('C',j)){
                        ok=0;
                    }
                }
            }else{
                ok=0;
            }
            if(ok==1){
                i=j;
                return true;
            }else{
                return false;
            }
        }else if(ch=='C'){
            int j=i,ok=1;
            if(sir[j]==2){
                j++;
            }else if(sir[j]==3){
                j++;
                if(!corect('B',j)){
                    ok=0;
                }
                if(ok==1&&!corect('C',j)){
                   ok=0;
                }
            }else if(sir[j]==1&&sir[j+1]==2){
                j+=2;
                if(!corect('A',j)){
                    ok=0;
                }
            }else{
                ok=0;
            }
            if(ok==1){
                i=j;
                return true;
            }else{
                return false;
            }
        }
    }
    return false;
}

int main(){
    f>>q;
    while(q--){
        f>>n;
        for(int i=1;i<=n;i++){
            f>>sir[i];
        }
        if(n==1){
            g<<1<<'\n';
        }else{
            int j=1,k=1;
            if(corect('B',j)&&j==n+1){
                g<<1<<'\n';
            }else if(corect('C',k)&&k==n+1){
                g<<1<<'\n';
            }else{
                g<<0<<'\n';
            }
        }
    }
    f.close();
    g.close();
}
