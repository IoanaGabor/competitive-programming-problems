#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct interval{
    int a,b;
};

interval intervale[50001];
int n;

bool criteriu(interval x,interval y){
    return x.b<y.b;
}

int main()
{
    ifstream f("int.in");
    ofstream g("int.out");
    f>>n;
    for(int i=1;i<=n;i++){
        f>>intervale[i].a>>intervale[i].b;
    }
    sort(intervale+1,intervale+n+1,criteriu);
    int ultimul=1;
    int contor=1;
    for(int i=1;i<=n;i++){
        if(intervale[i].a>=intervale[ultimul].b){
            ultimul=i;
            contor++;
        }
    }
    g<<contor;
    f.close();
    g.close();
    return 0;
}
