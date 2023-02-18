
#include <iostream>
#include <fstream>
#define NMAX 15000

using namespace std;

ifstream f("reactii.in");
ofstream g("reactii.out");

int m,n,top,x;
pair <int,int> st[NMAX+5],nou;

bool ok(){
    if(nou.first==st[top].second+1){
        return true;
    }
    if(nou.second+1==st[top].first){
        return true;
    }
    return false;
}

int main(){
    f>>n>>m;
    while(m--){
        top=0;
        for(int i=1;i<=n;i++){
            f>>x;
            nou.first=nou.second=x;
            while(top&&ok()){
                if(nou.first==st[top].second+1){
                    nou.first=st[top].first;
                }else if(nou.second+1==st[top].first){
                    nou.second=st[top].second;
                }
                top--;
            }
            st[++top]=nou;
        }
        if(top==1){
            g<<1<<'\n';
        }else{
            g<<0<<'\n';
        }
    }
    f.close();
    g.close();
}
