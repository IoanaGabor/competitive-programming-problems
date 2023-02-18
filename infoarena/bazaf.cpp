
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("bazaf.in");
ofstream g("bazaf.out");

short int cerinta;
long long x;
long long desc[20],ldesc;
long long factorial[]={0,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000};
long long cif[1000005],m;

int cauta(long long x){
    int pas=1<<4,rez=0;
    while(pas){
        if(rez+pas<=17&& factorial[rez+pas]<=x){
            rez+=pas;
        }
        pas>>=1;
    }
    return rez;
}

void unu(){
    int i=cauta(x);
    while(x){
        desc[++ldesc]=x/factorial[i];
        x%=factorial[i];
        i--;
    }
    while(i){
        desc[++ldesc]=0;
        i--;
    }
    g<<ldesc<<' ';
    for(int i=ldesc;i>=1;i--){
        g<<desc[i]<<' ';
    }
}

void doi(){
    int t=0;
    for(int i=1;i<=m;i++){
        cif[i]+=t;
        t=cif[i]/(i+1);
        cif[i]=cif[i]%(i+1);
    }
    if(t>0){
        while(t){
            m++;
            cif[m]=t;
            t=cif[m]/(m+1);
            cif[m]=cif[m]%(m+1);
        }
    }
}

int main(){
    f>>cerinta;
    if(cerinta==1){
        f>>x;
        unu();
    }else{
        //g<<"cred ca m-am prins ce ii gresit si nu mai ii nevoie de mesaj de afisare.sper";
        f>>m;
        for(int i=1;i<=m;i++){
            f>>cif[i];
        }
        doi();
        g<<m<<' ';
        for(int i=1;i<=m;i++){
            g<<cif[i]<<' ';
        }
    }
    f.close();
    g.close();
}
