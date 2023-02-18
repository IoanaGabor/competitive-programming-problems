
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

map <string,int> m;
string s;
int n,t;

int main(){
    ifstream f("pufu.in");
    ofstream g("pufu.out");
    f>>t;
    while(t--){
        m["ciocolata"]=0;
        m["cascaval"]=0;
        m["sare"]=0;
        f>>n;
        while(n--){
            f>>s;
            m[s]++;
        }
        g<<m["ciocolata"]<<' '<<m["cascaval"]<<' '<<m["sare"]<<'\n';
    }
    f.close();
    g.close();
}
