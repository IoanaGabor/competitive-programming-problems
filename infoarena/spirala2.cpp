
#include <iostream>
#include <fstream>
#define NMAX 50
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("spirala2.in");
ofstream g("spirala2.out");

int n,k,permutare[NMAX*NMAX+5],viz[NMAX*NMAX+5],grupe[NMAX*NMAX+5],ngr,exp_max[NMAX*NMAX+5],exp[NMAX*NMAX+5],baza[NMAX*NMAX+5],l,mprim;
int rez;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void construieste_permutare(){
    int m1[NMAX+5][NMAX+5],m2[NMAX+5][NMAX+5];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i%2==1){
                m1[i][j]=(i-1)*n+j;
                m2[i][j]=(i-1)*n+j;
            }else{
                m1[i][j]=(i-1)*n+(n-j+1);
                m2[i][j]=(i-1)*n+(n-j+1);
            }
        }
    }
    int x=1,y=1,ii,jj,d=0,val;
    m1[1][n+1]=m1[n+1][n]=m1[n][0]=-1;
    for(int i=1;i<=n*n;i++){
        ii=(i+n-1)/n;
        jj=i-(ii-1)*n;
        if(ii%2==1){
            val=m2[ii][jj];
            m2[ii][jj]=m1[x][y];
        }else{
            jj=n-jj+1;
            val=m2[ii][jj];
            m2[ii][jj]=m1[x][y];
        }
        permutare[m2[ii][jj]]=val;
        m1[x][y]=-1;
        if(m1[x+dx[d]][y+dy[d]]==-1){
            d++;
            d%=4;
        }
        x+=dx[d];
        y+=dy[d];
    }
}

bool ok(int numar){
    int cnt=0;
    for(int i=1;i<=ngr;i++){
        if(numar%grupe[i]==0){
            cnt+=grupe[i];
        }
    }
    return (cnt==k);
}

void genereaza(int j,int numar){
    if(numar>rez){
        return;
    }
    if(j==l+1){
        if(ok(numar)){
            rez=min(rez,numar);
        }
    }else{
        for(int i=0;i<=exp[j];i++){
            genereaza(j+1,numar);
            if(numar<=rez/baza[j]){
                numar*=baza[j];
            }else{
                return;
            }
        }
    }
}

int main(){
    f>>n>>k;
    construieste_permutare();
    for(int i=1;i<=n*n;i++){
        if(!viz[i]){
            int aux=i,cnt;
            ngr++;
            while(!viz[aux]){
                viz[aux]=1;
                aux=permutare[aux];
                grupe[ngr]++;
            }
            aux=grupe[ngr];
            for(int j=2;aux!=1&&j*j<=aux;j++){
                cnt=0;
                if(aux%j==0){
                    mprim=max(mprim,j);
                }
                while(aux%j==0){
                    cnt++;
                    aux=aux/j;
                }
                exp_max[j]=max(exp_max[j],cnt);
            }
            if(aux!=1){
                mprim=max(mprim,aux);
                exp_max[aux]=max(exp_max[aux],1);
            }
        }
    }
    rez=MAXVAL;
    for(int i=2;i<=mprim;i++){
        if(exp_max[i]!=0){
            exp[++l]=exp_max[i];
            baza[l]=i;
        }
    }
    genereaza(1,1);
    g<<rez;
    f.close();
    g.close();
}
