
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
