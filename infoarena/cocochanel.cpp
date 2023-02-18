#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream f("cocochanel.in");
    ofstream g("cocochanel.out");
    int gaina[100001],cocos[100001],n,m;
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>cocos[i];
    }
    for(int i=1;i<=m;i++){
        f>>gaina[i];
    }
    sort(gaina+1,gaina+m+1);
    int ultima_gaina=gaina[m],rez=0,n_gaini_ramase=m;
    for(int i=1;i<=n;i++){
        while(cocos[i]<=ultima_gaina && n_gaini_ramase>0){
            rez++;
            cocos[i]=cocos[i]*2;
            n_gaini_ramase--;
        }
        g<<rez<<'\n';
        rez=0;
        n_gaini_ramase=m;
    }
    f.close();
    g.close();
    return 0;
}
