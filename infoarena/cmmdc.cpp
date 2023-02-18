
#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b){
    if(b==0){
        if(a==1){
            return 0;
        }
        return a;
    }else{
        return cmmdc(b,a%b);
    }
}

int main(){
    ifstream f("cmmdc.in");
    ofstream g("cmmdc.out");
    int a,b;
    f>>a>>b;
    g<<cmmdc(a,b);
    f.close();
    g.close();
}
