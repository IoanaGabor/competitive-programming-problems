#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("7segmente.in");
ofstream g("7segmente.out");

int p,k,putere[11]={6,2,5,5,4,5,6,3,7,6},cifre_n[30],cifre_rez[30],lcn,lcr,putere_ramasa;
unsigned long long n;
bool ok;

void cerinta_1(){
    unsigned long long cn=n;
    while(cn){
        k+=putere[cn%10];
        cifre_n[++lcn]=cn%10;
        cn/=10;
    }
    reverse(cifre_n+1,cifre_n+lcn+1);
}

int cauta_cifra(int i,int cifn){
    if(ok){
        for(int j=9;j>=1;j--){
            if(putere[j]<=(putere_ramasa-2*(lcr-i))){
                return j;
            }
        }
    }else{
        for(int j=cifn;j>=1;j--){
            if(putere[j]<=(putere_ramasa-2*(lcr-i))){
                if(j<cifn){
                    ok=true;
                }
                return j;
            }
        }
    }
}

void cerinta_2(){
    lcr=min(lcn,p/2);
    putere_ramasa=p;
    ok=false;
    if(lcr<lcn){
        ok=true;
    }
    for(int i=1;i<=lcr;i++){
        cifre_rez[i]=cauta_cifra(i,cifre_n[i]);
        putere_ramasa=putere_ramasa-putere[cifre_rez[i]];
    }
}

int main()
{
    f>>n>>p;
    cerinta_1();
    g<<k<<' ';
    cerinta_2();
    for(int i=1;i<=lcr;i++){
        g<<cifre_rez[i];
    }
    f.close();
    g.close();
    return 0;
}
