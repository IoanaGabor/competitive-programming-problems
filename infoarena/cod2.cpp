
#include <iostream>
#include <fstream>
#define NL 26
#define MOD 9901

using namespace std;

ifstream f("cod2.in");
ofstream g("cod2.out");

int n,fr[NL+1],a,b,p1,p2,rez;
char ch;

int main(){
    f>>n;
    while(f>>ch){
        fr[ch-'a']++;
        if(fr[ch-'a']==1){
           a++;
        }else if(fr[ch-'a']==2){
            a--;
            b++;
        }
    }
    p1=1;
    for(int i=a+b;i>=a+b-n+1;i--){
        p1=(p1*i)%MOD;
    }
    p2=1;
    for(int i=a+b-1;i>=a+b-n+2;i--){
        p2=(p2*i)%MOD;
    }
    rez=(p1+(b*p2%MOD)*(n-1)*n/2)%MOD;
    g<<rez;
    f.close();
    g.close();
}
