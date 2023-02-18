#include <bits/stdc++.h>

using namespace std;

ifstream fi("xor.in");
ofstream fo("xor.out");

long long t,p,n,c1,c2,l1,l2;

int nr_1(long long x,int bit){
    x++;
    int pas=(1<<bit);
    int cat=(x/(2*pas));
    int rest=(x%(2*pas));
    int ret=cat*pas;
    if(rest>pas){
        ret+=rest-pas;
    }
    return ret;
}

long long calc(){
    long long ret=0,nr1x,nr1y;
    long long x=(l2-l1+1),y=(c2-c1+1);
    for(int i=29;i>=0;i--){
        nr1x=(nr_1(l2,i)-nr_1(l1-1,i)+p)%p;
        nr1y=(nr_1(c2,i)-nr_1(c1-1,i)+p)%p;
        ret=(ret+(((((((x-nr1x)*nr1y)%p)+(((y-nr1y)*nr1x)%p))%p)*(1<<i))%p))%p;
    }
    return ret;
}

int main(){
    fi>>t>>p;
    while(t--){
        fi>>l1>>c1>>l2>>c2;
        long long sol=calc();
        fo<<sol<<'\n';
    }
    fi.close();
    fo.close();
}