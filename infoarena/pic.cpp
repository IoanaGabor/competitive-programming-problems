
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("pic.in");
ofstream g("pic.out");

long long n,cerinta,pahare[55][55],picaturi[55][55],suma,suma_max=-1,nivel;

long long nu_sunt_umplute(long long cant){
    long long sol=0;
    for(int i=1;i<=54;i++){
        for(int j=1;j<=54;j++){
            picaturi[i][j]=0;
        }
    }
    picaturi[1][1]=cant;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(picaturi[i][j]<pahare[i][j]){
                return -1;
            }
            picaturi[i+1][j]+=(picaturi[i][j]-pahare[i][j])/2+(picaturi[i][j]-pahare[i][j])%2;
            picaturi[i+1][j+1]+=(picaturi[i][j]-pahare[i][j])/2;
            if(i==n){
                sol=sol+picaturi[i][j]-pahare[i][j];
            }

        }
    }
    return sol;
}

long long cauta(){
    long long pas=1LL<<60,rez=1LL<<60;
    while(pas){
        if(nu_sunt_umplute(rez-pas)>0){
            rez=rez-pas;
        }
        pas=pas/2;
    }
    return rez;
}

int main(){
    f>>cerinta>>n;
    for(int i=1;i<=n;i++){
        suma=0;
        for(int j=1;j<=i;j++){
            f>>pahare[i][j];
            suma=suma+pahare[i][j];
        }
        if(suma>suma_max){
            suma_max=suma;
            nivel=i;
        }
    }
    if(cerinta==1){
        g<<nivel<<'\n';
        f.close();
        g.close();
        return 0;
    }
    long long rez=cauta();
    g<<rez<<' '<<nu_sunt_umplute(rez);
    f.close();
    g.close();
}

