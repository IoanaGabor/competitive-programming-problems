
#include <iostream>
#include <fstream>
#include <cmath>
#define VMAX (1LL<<31)-1

using namespace std;

ifstream f("civilizatie.in");
ofstream g("civilizatie.out");

int cerinta,N,M,n,t,x[2004],y[2004],timp[2004][2004],distanta[2004][2004],ies[2004],lmin[2004],jmin[2004],stop[2004];

int main(){
    f>>cerinta>>N>>M>>t;
    if(cerinta==1){
        g<<2LL*t*(t-1)+1LL;
    }else{
        f>>n;
        for(int i=1;i<=n;i++){
            f>>x[i]>>y[i];
            ies[i]=min(min(x[i],N-x[i]+1),min(y[i],M-y[i]+1));
        }
        for(int i=1;i<=n;i++){
            lmin[i]=VMAX;
            for(int j=1;j<=n;j++){
                distanta[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j])+1;
                timp[i][j]=distanta[i][j]/2;
                if(i!=j&&timp[i][j]<lmin[i]){
                    lmin[i]=timp[i][j];
                    jmin[i]=j;
                }
            }
        }
        int contor=0,p,tmin;
        while(contor<n){
            tmin=VMAX;
            for(int i=1;i<=n;i++){
                if(!stop[i]){
                    if(tmin>lmin[i]){
                        tmin=lmin[i];
                        p=i;
                    }
                    if(tmin>ies[i]){
                        tmin=ies[i];
                        p=i;
                    }
                }
            }
            lmin[p]=VMAX;
            contor++;
            stop[p]=tmin;
            for(int j=1;j<=n;j++){
                if(!stop[j]&&timp[p][j]!=stop[p]){
                    timp[p][j]=timp[j][p]=distanta[p][j]-stop[p];
                    if(jmin[j]==p){
                        lmin[j]=VMAX;
                        for(int k=1;k<=n;k++){
                            if(timp[j][k]<lmin[j]&&j!=k){
                                lmin[j]=timp[j][k];
                                jmin[j]=k;
                            }
                        }
                    }
                }
            }
        }
        long long rez1=0;
        int rez2=0;
        for(int i=1;i<=n;i++){
            rez1+=2LL*stop[i]*(stop[i]-1)+1LL;
            rez2=max(rez2,stop[i]);
        }
        rez1=1LL*N*M-rez1;
        g<<rez1<<'\n'<<rez2<<'\n';
    }
    f.close();
    g.close();
}
