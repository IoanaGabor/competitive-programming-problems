/*
#include <iostream>
#include <fstream>
#define NMAX 1000
#define MMAX 5000

using namespace std;

ifstream f("robot3.in");
ofstream g("robot3.out");

int n,m,

int main(){

    f.close();
    g.close();
}
*/
/*
#include <iostream>
#include <fstream>
#define MMAX 100000

using namespace std;

ifstream f("cevaculiste.in");
ofstream g("cevaculiste.out");

long long n,m,liste[MMAX+3],k,rez;

bool gata(){
    if(n==0||n<liste[m]||m==0){
        return true;
    }
    return false;
}

void cauta_capat_nou(){
    long long pas=1<<17,mnou=0;
    while(pas){
        if(mnou+pas<=m&&liste[mnou+pas]<=n){
            mnou+=pas;
        }
        pas>>=1;
    }
    m=mnou;
}

int main(){
    f>>n>>m;
    for(int i=1;i<=m;i++){
        f>>liste[i];
    }
    cauta_capat_nou();
    while(!gata()){
        k=(n-liste[m])/m;
        n=n-(k+1)*m;
        rez+=k+1;
        cauta_capat_nou();
        cout<<n<<' '<<m<<' '<<liste[m]<<'\n';
    }
    g<<rez;
    f.close();
    g.close();
}
*/
/*
#include <iostream>

using namespace std;

int s,dp[100][11];

int rezolva(int s,int k){
    if(s<0){
        return 0;
    }
    if(k==0&&s==0){
        return 1;
    }
    if(k==0&&s!=0){
        return 0;
    }
    if(dp[s][k]!=-1){
        return dp[s][k];
    }
    int rez=0;
    for(int i=0;i<=9;i++){
            rez+=rezolva(s-i,k-1);
    }
    dp[s][k]=rez;
    return rez;
}

int main(){
    cin>>s;
    for(int i=0;i<=100;i++){
        for(int j=1;j<=10;j++){
            dp[i][j]=-1;
        }
    }
    if(s==1){
        cout<<10;
    }else{
        cout<<rezolva(s,9);
    }
}
*/
#include <iostream>
#include <fstream>
#define NMAX 512

using namespace std;

ifstream f("pav.in");
ofstream g("pav.out");

int n,x,y,matrice[NMAX+5][NMAX+5],cnt;

void rezolva(int l1,int c1,int l2,int c2,int xvid,int yvid){
    int xmij=(l1+l2)/2,ymij=(c1+c2)/2;
    if(xvid<=xmij&&yvid<=ymij){
        cnt++;
        matrice[xmij+1][ymij]=cnt;
        matrice[xmij+1][ymij+1]=cnt;
        matrice[xmij][ymij+1]=cnt;
        if(xmij!=l1&&ymij!=c1){
            rezolva(l1,c1,xmij,ymij,xvid,yvid);
            rezolva(l1,ymij+1,xmij,c2,xmij,ymij+1);
            rezolva(xmij+1,c1,l2,ymij,xmij+1,ymij);
            rezolva(xmij+1,ymij+1,l2,c2,xmij+1,ymij+1);
        }
    }else if(xvid<=xmij&&yvid>ymij){
        cnt++;
        matrice[xmij+1][ymij]=cnt;
        matrice[xmij+1][ymij+1]=cnt;
        matrice[xmij][ymij]=cnt;
        if(xmij!=l1&&ymij!=c1){
            rezolva(l1,c1,xmij,ymij,xmij,ymij);
            rezolva(l1,ymij+1,xmij,c2,xvid,yvid);
            rezolva(xmij+1,c1,l2,ymij,xmij+1,ymij);
            rezolva(xmij+1,ymij+1,l2,c2,xmij+1,ymij+1);
        }
    }else if(xvid>xmij&&yvid<=ymij){
        cnt++;
        matrice[xmij][ymij+1]=cnt;
        matrice[xmij+1][ymij+1]=cnt;
        matrice[xmij][ymij]=cnt;
        if(xmij!=l1&&ymij!=c1){
            rezolva(l1,c1,xmij,ymij,xmij,ymij);
            rezolva(l1,ymij+1,xmij,c2,xmij,ymij+1);
            rezolva(xmij+1,c1,l2,ymij,xvid,yvid);
            rezolva(xmij+1,ymij+1,l2,c2,xmij+1,ymij+1);
        }
    }else if(xvid>xmij&&yvid>ymij){
        cnt++;
        matrice[xmij][ymij+1]=cnt;
        matrice[xmij][ymij]=cnt;
        matrice[xmij+1][ymij]=cnt;
        if(xmij!=l1&&ymij!=c1){
            rezolva(l1,c1,xmij,ymij,xmij,ymij);
            rezolva(l1,ymij+1,xmij,c2,xmij,ymij+1);
            rezolva(xmij+1,c1,l2,ymij,xmij+1,ymij);
            rezolva(xmij+1,ymij+1,l2,c2,xvid,yvid);
        }
    }
}

int main(){
    f>>n>>x>>y;
    matrice[x][y]=0;
    rezolva(1,1,(1<<n),(1<<n),x,y);
    for(int i=1;i<=(1<<n);i++){
        for(int j=1;j<=(1<<n);j++){
            g<<matrice[i][j]<<' ';
        }
        g<<'\n';
    }
    f.close();
    g.close();
}
