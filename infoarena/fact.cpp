
#include <iostream>
#include <fstream>

using namespace std;

int nr_de_5(int n) {
    int rez=0;
    while(n%5==0){
        rez++;
        n=n/5;
    }
    return rez;
}

int nr_de_5_pana_la_n_factorial(int n) {
    int k=5,contor=0;
    while(k<=n) {
        contor=contor+n/k;
        k=k*5;
    }
    return contor;
}

int main() {
    ifstream f("fact.in");
    ofstream g("fact.out");
    int p;
    f>>p;
    if(p==0) {
        g<<1;
    }else{


        int minim=1,maxim=5*p;
        int mijloc=(((minim+maxim)/2)/5)*5;

        while(maxim-minim>5) {
            if(p<nr_de_5_pana_la_n_factorial(mijloc)){
                maxim=mijloc;
                mijloc=(((minim+maxim)/2)/5)*5;
            }else if(p>nr_de_5_pana_la_n_factorial(mijloc)){
                minim=mijloc;
                mijloc=(((minim+maxim)/2)/5)*5;
            }else{
                g<<mijloc;
                f.close();
                g.close();
                return 0;
            }
        }
        bool gasit=false;
        for(int i=minim;i<=maxim;i++) {
            if(nr_de_5_pana_la_n_factorial(i)==p){
                gasit=true;
                g<<i;
                f.close();
                g.close();
                return 0;
            }
        }
        if(gasit==false){
            g<<-1;
        }
    }
    f.close();
    g.close();
}
