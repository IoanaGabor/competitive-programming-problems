
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("betasah.in");
ofstream g("betasah.out");

int n,d,k,tabla[1005][1005],contor=0,rez1=-1,rez2=0;

struct coord{
    int x,y;
};

coord dame[1005];

int dx[]={0,1,0,-1,-1,1,1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};

int calculeaza(int i){
    int a=dame[i].x,b=dame[i].y,auxa,auxb,rez=0;
    for(i=0;i<=7;i++){
        auxa=a+dx[i];
        auxb=b+dy[i];
        while(tabla[auxa][auxb]>=0){
            if(tabla[auxa][auxb]==0){
                rez++;
                tabla[auxa][auxb]=2;
            }
            auxa+=dx[i];
            auxb+=dy[i];
        }
    }
    return rez;
}

int main(){
    f>>n>>d>>k;
    for(int i=1;i<=d;i++){
        f>>dame[i].x>>dame[i].y;
        tabla[dame[i].x][dame[i].y]++;
    }
    int a,b;
    for(int i=1;i<=k;i++){
        f>>a>>b;
        tabla[a][b]=-1;
    }
    for(int i=1;i<=n;i++){
        contor=0;
        for(int j=1;j<=i;j++){
            if(tabla[i][j]!=-1){
                contor++;
            }
        }
        rez1=max(rez1,contor);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n+1;j++){
            tabla[i][j]=-2;
        }
    }
    for(int i=0;i<=n+1;i++){
        tabla[0][i]=-2;
        tabla[n+1][i]=-2;
        tabla[i][0]=-2;
        tabla[i][n+1]=-2;
    }
    for(int i=1;i<=d;i++){
        if(tabla[dame[i].x][dame[i].y]==1){
            rez2=rez2+calculeaza(i);
        }
    }
    g<<rez1<<'\n';
    g<<rez2<<'\n';
    f.close();
    g.close();
}
