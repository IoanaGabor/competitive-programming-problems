/*
#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 100

using namespace std;

ifstream f("marceland.in");
ofstream g("marceland.out");

int t,n,m,lm,xmin,xmax,ymin,ymax,cnt;
int dx[]={0,1,0,-1,0};
int dy[]={0,0,1,0,-1};
char harta[NMAX+5][NMAX+5];
bool viz[NMAX+5][NMAX+5],gasit_fantana,nuiok;
pair <int,int> marcel[NMAX*NMAX+1],aux,nisip,auxx;
queue <pair<int,int> > q;

bool nu_ies(){
    if((auxx.first<=n)&&(auxx.first>=1)&&(auxx.second<=m)&&(auxx.second>=1)){
        return true;
    }
    return false;
}

int main(){
    f>>t;
    while(t--){
        f>>n>>m;
        xmin=ymin=1;
        xmax=n;
        ymax=m;
        nuiok=false;
        lm=0;
        cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f>>harta[i][j];
                if(harta[i][j]=='M'){
                    marcel[++lm].first=i;
                    marcel[lm].second=j;
                }
            }
        }
        for(int ii=1;ii<=lm;ii++){
            while(!q.empty()){
                q.pop();
            }
            for(int i=xmin;i<=xmax;i++){
                for(int j=ymin;j<=ymax;j++){
                    viz[i][j]=false;
                }
            }
            q.push(marcel[ii]);
            viz[marcel[ii].first][marcel[ii].second]=true;
            gasit_fantana=false;
            nisip.first=-1;
            while(!q.empty()&&!gasit_fantana){
                aux=q.front();
                q.pop();
                for(int d=1;d<=4;d++){
                    auxx.first=aux.first+dx[d];
                    auxx.second=aux.second+dy[d];
                    if(nu_ies()&& harta[auxx.first][auxx.second]!='#'&&viz[auxx.first][auxx.second]==false){
                        if(harta[auxx.first][auxx.second]=='@'){
                            gasit_fantana=true;
                        }else if(harta[auxx.first][auxx.second]=='.'){
                            nisip.first=auxx.first;
                            nisip.second=auxx.second;
                        }
                        q.push(auxx);
                        viz[auxx.first][auxx.second]=true;
                        xmin=min(xmin,auxx.first);
                        ymin=min(ymin,auxx.second);
                        xmax=max(xmax,auxx.first);
                        ymax=max(ymax,auxx.second);
                    }
                }
            }
            if(!gasit_fantana&& nisip.first==-1){
                nuiok=true;
                break;
            }else if(!gasit_fantana){
                harta[nisip.first][nisip.second]='@';
                cnt++;
            }
        }
        if(nuiok){
            g<<-1<<'\n';
        }else{
            g<<cnt<<'\n';
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    g<<harta[i][j];
                }
                g<<'\n';
            }
        }
    }
    f.close();
    g.close();
}
*/
/*
#include <iostream>
#include <fstream>
#define KMAX 100000
#define NMAX 3000

using namespace std;

ifstream f("tablou.in");
ofstream g("tablou.out");

int n,m,matrice[NMAX+5][NMAX+5],sume[NMAX+5][NMAX+5],l1,l2,c1,c2,culoare;
char ch;
int sume_tablouri[KMAX+5],k;
long long rez_tablouri[KMAX+5];

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>ch;
            matrice[i][j]=ch-'0';
            sume[i][j]=sume[i-1][j]+sume[i][j-1]-sume[i-1][j-1]+matrice[i][j];
        }
    }
    f>>k;
    for(int i=1;i<=k;i++){
        f>>l1>>c1>>l2>>c2>>culoare;
        sume_tablouri[i]=culoare*(l2-l1+1)*(c2-c1+1)-(sume[l2][c2]-sume[l1-1][c2]-sume[l2][c1-1]+sume[l1-1][c1-1]);
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<i;j++){
            rez_tablouri[i]+=1LL*n*m*(sume_tablouri[i]-sume_tablouri[j]);
            rez_tablouri[j]+=1LL*n*m*(sume_tablouri[j]-sume_tablouri[i]);
        }
    }
    for(int i=1;i<=k;i++){
        g<<rez_tablouri[i]<<'\n';
    }
    f.close();
    g.close();
}
*/
/*
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream f("panza.in");
ofstream g("panza.out");

int n,m,a[100005],x,y,s,fin;

int main(){
    f>>n>>m>>s>>fin;
    for(int i=1;i<=n;i++){
        f>>a[i];
    }
    if(n==1){
        f>>x>>y;
        if(s<=x){
            g<<x-s+abs(fin-x);
        }else if(s>x&&s<y){
            g<<abs(fin-s);
        }else{
            g<<s-y+abs(fin-y);
        }
    }else{
        g<<9;
    }
    f.close();
    g.close();
}
*/
/*
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("orase.in");
ofstream g("orase.out");

int n,m,dist,l,r1,r2;

int main(){
    f>>m>>n;
    for(int i=1;i<=n;i++){
        f>>dist>>l;
        r1=max(r1,-dist+l);
        r2=max(r2,dist+l);
    }
    g<<r1+r2;
    f.close();
    g.close();
}
*/
/*
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("text.in");
ofstream g("text.out");

int n,viz[10005],sir[10005];

void backtracking(int k){
    if(k==n+1){
        for(int i=1;i<=n;i++){
            g<<sir[i]<<' ';
        }
        g<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(!viz[i]){
            viz[i]=1;
            sir[k]=i;
            backtracking(k+1);
            viz[i]=0;
        }
    }
}

int main(){
    f>>n;
    backtracking(1);
    f.close();
    g.close();
}
*/
/*
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("secv2.in");
ofstream g("secv2.out");

int n,k,x,suma,rez=-25000*50000-1,ii,irez,jrez,total;

int main(){
    f>>n>>k;
    ii=1;
    for(int i=1;i<=n;i++){
        f>>x;
        total+=x;
        if(suma+x>x){
            suma+=x;
        }else{
            ii=i;
            suma=x;
        }
        if(rez<suma&&i-ii+1>=k){
            rez=suma;
            irez=ii;
            jrez=i;
        }
    }
    if(rez<total){
        g<<1<<' '<<n<<' '<<total<<'\n';
    }else{
        g<<irez<<' '<<jrez<<' '<<rez<<'\n';
    }
    f.close();
    g.close();
}
*/
/*
#include <iostream>
#include <fstream>
#define GMAX 10000
#define NMAX 5000

using namespace std;

ifstream f("rucsac.in");
ofstream g("rucsac.out");

int n,G,w[NMAX+1],p[NMAX+1],dp[2][GMAX+1],acum,vechi;

int main(){
    f>>n>>G;
    for(int i=1;i<=n;i++){
        f>>w[i]>>p[i];
    }
    for(int i=1;i<=n;i++){
        acum=i%2;
        vechi=(i-1)%2;
        for(int j=0;j<=G;j++){
            dp[acum][j]=dp[vechi][j];
            if(w[i]<=j){
                dp[acum][j]=max(dp[acum][j],dp[vechi][j-w[i]]+p[i]);
            }
        }
    }
    g<<dp[n%2][G];
    f.close();
    g.close();
}
*/
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("secv2.in");
ofstream g("secv2.out");

int n,k,x,suma,rez=-25000*50000-1,ii,irez,jrez,total;

int main(){
    f>>n>>k;
    ii=1;
    for(int i=1;i<=n;i++){
        f>>x;
        total+=x;
        if(suma+x>x){
            suma+=x;
        }else{
            ii=i;
            suma=x;
        }
        if(rez<suma&&i-ii+1>=k){
            rez=suma;
            irez=ii;
            jrez=i;
        }
    }
    if(rez<total){
        g<<1<<' '<<n<<' '<<total<<'\n';
    }else{
        g<<irez<<' '<<jrez<<' '<<rez<<'\n';
    }
    f.close();
    g.close();
}
