
#include <iostream>
#include <fstream>
#define NMAX 1000

using namespace std;

ifstream f("aiacusarpe.in");
ofstream g("aiacusarpe.out");

int n,m,t,matrice[NMAX+5][NMAX+5],x,y,cnt,start,rez;
char ch;

int main(){
    x=1;
    y=1;
    matrice[x][y]=1;
    start=1;
    f>>n>>m>>t;
    cnt=1;
    for(int i=1;i<=t;i++){
        f>>ch;
        if(ch=='E'){
            y++;
        }else if(ch=='V'){
            y--;
        }else if(ch=='N'){
            x--;
        }else{
            x++;
        }
        if(!(1<=x&&x<=n&&1<=y&&y<=m)){
            break;
        }
        if(matrice[x][y]<start){
            matrice[x][y]=++cnt;
        }else{
            rez=max(rez,cnt-start+1);
            start=matrice[x][y]+1;
            matrice[x][y]=++cnt;
        }
    }
    rez=max(rez,cnt-start+1);
    g<<rez;
    f.close();
    g.close();
}
