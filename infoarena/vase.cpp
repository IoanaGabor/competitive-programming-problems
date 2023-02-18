
#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream f("vase.in");
ofstream g("vase.out");

struct lichid{
    int volum,nr;
};

deque <lichid> vas;

int n,x;
long long s,k;
char ch;

lichid j;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>j.volum>>ch;
        j.nr=i;
        if(ch=='S'){
            vas.push_front(j);
        }else{
            vas.push_back(j);
        }
        s=s+j.volum;
    }
    f>>x;
    bool gasit=false;
    while(!gasit){
        if(vas.front().nr==x){
            gasit=1;
        }else{
            k=k+vas.front().volum;
            vas.pop_front();
        }
    }
    g<<s/2<<'\n';
    if(k+vas.front().volum<=s/2){
        g<<s/2-k<<" S"<<'\n';
        g<<s/2-k-vas.front().volum<<" S"<<'\n';
    }else if(k+vas.front().volum>s/2&&k<s/2){
        g<<s/2-k<<" S"<<'\n';
        g<<k+vas.front().volum-s/2<<" D"<<'\n';
    }else if(k>=s/2){
        g<<k+vas.front().volum-s/2<<" D"<<'\n';
        g<<k-s/2<<" D"<<'\n';
    }
    f.close();
    g.close();
}
