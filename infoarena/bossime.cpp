
#include <bits/stdc++.h>
#define nr 111111111

using namespace std;

ifstream fi("bossime.in");
ofstream fo("bossime.out");

int t;
long long a,b,aa,x;

int main(){
    fi>>t;
    while(t--){
        fi>>a>>b;
        if(a<b){
            swap(a,b);
        }
        if((a-b)%9!=0){
            fo<<"Imposibil\n";
        }else{
            aa=10LL*(((a-b)/9)+nr)+1;
            x=aa-a;
            fo<<x<<'\n';
        }
    }
    fi.close();
    fo.close();    
}