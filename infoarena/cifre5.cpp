
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cifre5.in");
ofstream g("cifre5.out");

int nr_segmente[10]={6,2,5,5,4,5,6,3,7,6},cerinta;
unsigned long long n;
int nr_cifre_formabile_mai_mari[10]={1,5,1,2,2,3,1,2,0,0};
int nr_cifre_formabile[10]={1,6,1,2,2,3,1,4,0,1};
int rez1(){
    int rez=0;
    while(n){
        rez=rez+nr_segmente[n%10];
        n=n/10;
    }
    return rez;
}

unsigned long long rez2(){
    unsigned long long rez=0,uc,aux=1;
    while(n){
        uc=n%10;
        rez=rez+nr_cifre_formabile_mai_mari[uc]*aux;
        aux=aux*(nr_cifre_formabile[uc]+1);
        n=n/10;
    }
    return rez;
}

int main()
{
    f>>cerinta>>n;
    if(cerinta==1){
        g<<rez1();
    }else{
        g<<rez2();
    }
    f.close();
    g.close();
    return 0;
}
