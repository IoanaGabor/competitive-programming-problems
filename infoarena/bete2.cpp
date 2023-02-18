
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("bete2.in");
ofstream g("bete2.out");

int n,sir[3001];

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    sort(sir+1,sir+n+1);
    int contor=0,stanga,dreapta;
    for(int i=3;i<=n;i++){
        stanga=1;
        dreapta=i-1;
        while(stanga<dreapta){
            if(sir[stanga]+sir[dreapta]<sir[i]){
                stanga++;
            }else if(sir[stanga]+sir[dreapta]>sir[i]){
                dreapta--;
            }else{
                contor++;
                stanga++;
                dreapta--;
            }
        }
    }
    g<<contor;
    f.close();
    g.close();
}
