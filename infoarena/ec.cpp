
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

ifstream f("ec.in");
ofstream g("ec.out");

int n,k,rez[250001],tip,a,b,c,d,contor_a1,contor_b1,contor_a2,contor_b2,ok,x,x1,x2,oricat,azero;
char ecuatie[101];

void prelucrare_ecuatie(){
    int cif,i=0;
    a=0;
    b=0;
    c=0;
    d=0;
    while(ecuatie[i]!='x'){
        cif=ecuatie[i]-'0';
        a=a*10+cif;
        i++;
    }
    i++;
    if(ecuatie[i]=='^'){
        tip=2;
        i=i+3;
        if(a==0){
            azero=1;
        }
        while(ecuatie[i]!='x'){
            cif=ecuatie[i]-'0';
            b=b*10+cif;
            i++;
        }
        i+=2;
        while(ecuatie[i]!='='){
            cif=ecuatie[i]-'0';
            c=c*10+cif;
            i++;
        }
        i++;
        while(ecuatie[i]!='\0'){
            cif=ecuatie[i]-'0';
            d=d*10+cif;
            i++;
        }
        if(azero){
            a=b;
            b=c;
            c=d;
        }
    }else{
        tip=1;
        i++;
        while(ecuatie[i]!='='){
            cif=ecuatie[i]-'0';
            b=b*10+cif;
            i++;
        }
        i++;
        while(ecuatie[i]!='\0'){
            cif=ecuatie[i]-'0';
            c=c*10+cif;
            i++;
        }
    }

}

void rez_ec_1(){
    b=b-c;
    if(a==0){
        ok=0;
        return;
    }
    if((-b)%a==0){
        ok=1;
        x=(-b)/a;
    }else{
        ok=0;
    }
}

void rez_ec_2(){
    c=c-d;
    int delta=(int)sqrt(b*b-4*a*c);
    if(delta>=0&&(b*b-4*a*c)==delta*delta){
        if(delta==0){
            if((-b)%(2*a)==0){
                ok=1;
                x1=x2=(-b)/(2*a);
            }else{
                ok=0;
            }
        }else{
            if((-b+delta)%(2*a)==0&&(-b-delta)%(2*a)==0){
                x1=(-b+delta)/(2*a);
                x2=(-b-delta)/(2*a);
                ok=1;
            }else{
                ok=0;
            }
        }
    }else{
        ok=0;
    }
}

bool gasit(int val){
    int pas=1<<18,i=0;
    while(pas){
        if(i+pas<=n*n&&rez[i+pas]<=val){
            i+=pas;
        }
        pas>>=1;
    }
    if(rez[i]==val){
        return true;
    }
    return false;
}

int main(){
    f>>n>>k;
    for(int i=1;i<=n*n;i++){
        f>>rez[i];
    }
    sort(rez+1,rez+n*n+1);
    for(int i=1;i<=k;i++){
        f>>ecuatie;
        ok=0;
        azero=0;
        prelucrare_ecuatie();
        if(azero){
            contor_a2++;
            rez_ec_1();
            if(ok){
                if(gasit(x)){
                    contor_b2++;
                }
            }
            continue;
        }
        if(tip==1){
            contor_a1++;
            rez_ec_1();
            if(ok){
                if(gasit(x)){
                    contor_b1++;
                }
            }
        }else{
            contor_a2++;
            rez_ec_2();
            if(ok&&gasit(x1)&&gasit(x2)){
                contor_b2++;
            }
        }
    }
    g<<contor_a1<<' '<<contor_b1<<'\n'<<contor_a2<<' '<<contor_b2<<'\n';
    f.close();
    g.close();
}
