
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("elicop.in");
ofstream g("elicop.out");

int n,m,a[101][101],sume[101][101],k,x1,x2,y1,y2,sus_jos,rez[41],l_rez=0,n1=0;

bool e_ok(){
    int contor=0;
    if(x1>x2){
        swap(x1,x2);
        swap(y1,y2);
    }
    int i,j;
    if(y1<y2&&sus_jos==-1){
        j=y1;
        for(i=x1;i<=x2&&j<=y2;i++){
            contor=contor+sume[i][j]-sume[i][y1-1];
            j++;
        }
    }else if(y1<y2 && sus_jos==1){
        j=y1;
        for(i=x1;i<=x2&&j<=y2;i++){
            contor=contor+sume[i][y2]-sume[i][j-1];
            j++;
        }
    }else if(y2<y1 && sus_jos==-1){
        j=y1;
        for(i=x1;i<=x2&&j>=y2;i++){
            contor=contor+sume[i][y1]-sume[i][j-1];
            j--;
        }
    }else if(y2<y1 && sus_jos==1){
        j=y1;
        for(i=x1;i<=x2&&j>=y2;i++){
            contor=contor+sume[i][j]-sume[i][y2-1];
            j--;
        }
    }
    cout<<contor<<' '<<x1<<' '<<x2<<'\n';
    if(contor>=(x2-x1+1)*(x2-x1+2)/4+((x2-x1+1)*(x2-x1+2)/2)%2){
        if(contor==(x2-x1+1)*(x2-x1+2)/2){
            n1++;
        }
        return true;
    }
    return false;
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>a[i][j];
            sume[i][j]=sume[i][j-1]+a[i][j];
        }
    }
    f>>k;
    for(int i=1;i<=k;i++){
        f>>x1>>y1>>x2>>y2>>sus_jos;
        if(e_ok()==false){
            rez[++l_rez]=i;
        }
    }
    g<<n1<<'\n';
    g<<l_rez<<' ';
    for(int i=1;i<=l_rez;i++){
        g<<rez[i]<<' ';
    }
    f.close();
    g.close();
}
