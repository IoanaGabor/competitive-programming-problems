
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#define NMAX 255

using namespace std;

ifstream f("ecuatii2.in");
ofstream g("ecuatii2.out");

int n,a,b,l,egal,pm;
char ec[NMAX+5];
double rez;
void rezolva(){
    l=strlen(ec);
    int nr;
    egal=1;
    a=0;
    b=0;
    for(int i=0;i<l;i++){
        nr=0;
        if(i==0){
            pm=1;
        }else if(ec[i-1]=='='){
            pm=1;
            egal=-1;
        }else if(ec[i-1]=='+'){
            pm=1;
        }else{
            pm=-1;
        }
        while(ec[i]!='+'&&ec[i]!='-'&&ec[i]!='='&&ec[i]){
            if(ec[i]=='x'){
                if(nr==0){
                    nr=1;
                }
                a+=egal*pm*nr;
            }else{
                nr=nr*10+(ec[i]-'0');
            }
            i++;
        }
        if(ec[i-1]!='x'){
            b+=egal*pm*nr;
        }
    }
}

int main(){
    f>>n;
    while(n){
        f>>ec;
        rezolva();
        if(a==0&&b==0){
            g<<"infinit"<<'\n';
        }else if(a==0&&b!=0){
            g<<"imposibil"<<'\n';
        }else{
            rez=(double)(b)/a;
            rez=rez*(-1);
            g<<setprecision(4)<<fixed<<rez;
            g<<'\n';
        }
        n--;
    }
    f.close();
    g.close();
}
