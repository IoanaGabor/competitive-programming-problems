
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("text.in");
    ofstream g("text.out");
    char ch;
    int litere=0,cuvinte=0,cuvant_recent=1;
    while(f.get(ch)){
        if(('a'<=ch && ch<='z') || ('A'<=ch && ch<='Z')){
            litere++;
            cuvant_recent=0;
        }else if(cuvant_recent==0){
            cuvinte++;
            cuvant_recent=1;
        }
    }
    if(cuvant_recent==0){
        cuvinte++;
    }
    g<<litere/cuvinte;
    f.close();
    g.close();
}
