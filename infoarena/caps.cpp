
#include <iostream>
#include <fstream>
#define KMAX 100000

using namespace std;

ifstream f("caps.in");
ofstream g("caps.out");

int q,ap[60][KMAX+5],apcaps[60][KMAX+5];
long long k,n,ind,aparitii;
bool inv;
string str;
char rez;
void unu(){
    long long grup=(n+k-1)/k;
    ind=n-(grup-1)*k;
    long long cnt=0;
    grup--;
    while(grup){
        grup&=(grup-1);
        cnt++;
    }
    if(cnt%2==0){
        inv=false;
    }else{
        inv=true;
    }
}

char inverseaza(char ch){
    if('a'<=ch&&ch<='z'){
        ch+='A'-'a';
    }else{
        ch+='a'-'A';
    }
    return ch;
}


int transforma(char ch){
    if(ch>='A'&&ch<='Z'){
        return ch-'A';
    }
    return 26+ch-'a';
}


void doi(){
    long long grup=(n+k-1)/k,cnt;
    aparitii=0;
    if(grup%2==1){
        aparitii+=(ap[transforma(rez)][k]+apcaps[transforma(rez)][k])*(grup-1)/2;
    }else{
        aparitii+=(ap[transforma(rez)][k]+apcaps[transforma(rez)][k])*(grup-2)/2;
        long long aux=grup;
        cnt=0;
        grup-=2;
        while(grup){
            grup&=(grup-1);
            cnt++;
        }
        if(cnt%2==0){
            aparitii+=ap[transforma(rez)][k];
        }else{
            aparitii+=apcaps[transforma(rez)][k];
        }
        grup=aux;
    }
    cnt=0;
    grup--;
    while(grup){
        grup&=(grup-1);
        cnt++;
    }
    if(cnt%2==0){
        aparitii+=ap[transforma(rez)][ind];
    }else{
        aparitii+=apcaps[transforma(rez)][ind];
    }
}

int main(){
    f>>k>>q;
    f>>str;
    for(int i=0;i<k;i++){
        ap[transforma(str[i])][i+1]=1;
        apcaps[transforma(inverseaza(str[i]))][i+1]=1;
    }
    for(int i=0;i<=52;i++){
        for(int j=1;j<=k;j++){
            ap[i][j]+=ap[i][j-1];
            apcaps[i][j]+=apcaps[i][j-1];
        }
    }
    while(q--){
        f>>n;
        unu();
        if(inv){
            rez=inverseaza(str[ind-1]);
        }else{
            rez=str[ind-1];
        }
        g<<rez<<' ';
        doi();
        g<<aparitii<<'\n';
    }
    f.close();
    g.close();
}
