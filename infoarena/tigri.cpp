#include <bits/stdc++.h>
#define CMAX 150
#define VMAX (1LL<<31)

using namespace std;

ifstream fi("tigri.in");
ofstream fo("tigri.out");

int n;
string op,X,Y;
long long lei;
long long tigri;
long long x,y;

long long getnumber(string nr){
    int sgn=1,ind=0;
    if(nr[0]=='-'){
        sgn=-1;
        ind=1;
    }
    long long ret=0;
    while(ind<nr.size()){
        if(ret*10LL+nr[ind]-'0'<VMAX){
            ret=ret*10+nr[ind]-'0';
        }else{
            ret=VMAX;
            break;
        }
        ind++;
    }
    ret*=sgn;
    return ret;
}

int main(){
    fi>>n;
    while(n--){
        fi>>op;
        if(op=="depositum"){
            fi>>X;
            x=getnumber(X);
            if(lei+x>0){
                lei+=x;
            }
        }else if(op=="emptum"){
            fi>>X>>Y;
            x=getnumber(X);
            y=getnumber(Y);
            if(tigri+x>=0&&lei-x*y>=0){
                tigri+=x;
                lei-=x*y;
            }
        }else if(op=="vendere"){
            fi>>X>>Y;
            x=getnumber(X);
            y=getnumber(Y);
            if(tigri-x>=0&&lei+x*y>=0){
                tigri-=x;
                lei+=x*y;
            }
        }
        fo<<lei<<' ';
    }
}
