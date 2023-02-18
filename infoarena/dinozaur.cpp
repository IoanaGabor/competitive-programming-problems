

#include <fstream>
#include <cstring>

using namespace std;

int frecventa[26];

int main() {
    ifstream f("dinozaur.in");
    ofstream g("dinozaur.out");
    char sir[100001];
    f>>sir;
    int n=strlen(sir),ok=0;
    if(n>26){
        g<<1;
    }else{
        for(int i=0;sir[i];i++) {
            frecventa[sir[i]-'a']++;
            if(frecventa[sir[i]-'a']>1){
                ok=1;
                break;
            }
        }
        g<<ok;
    }
    f.close();
    g.close();
}
