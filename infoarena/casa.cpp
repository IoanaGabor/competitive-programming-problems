#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#define NMAX 100000

using namespace std;

ifstream f("casa.in");
ofstream g("casa.out");

int cerinta,n,val,ind,lmin,lmax,cmin,cmax,m,viz[NMAX+5],cprima,x,y,xx,yy,contor;
pair <int,int> poz[NMAX+5];
char ch;
int dx[]={0,-1,1,0};
int dy[]={1,0,0,-1};

queue <pair <int,int> > q;

int transforma(char ch){
    if(ch=='E'){
        return 0;
    }
    if(ch=='N'){
        return 1;
    }
    if(ch=='S'){
        return 2;
    }
    if(ch=='V'){
        return 3;
    }
}

char transforma_invers(int i){
    if(i==0){
        return 'E';
    }
    if(i==1){
        return 'N';
    }
    if(i==2){
        return 'S';
    }
    if(i==3){
        return 'V';
    }
}

bool criteriu(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}

int main()
{
    f>>cerinta;
    if(cerinta==1){
        f>>n;
        poz[1].first=0;
        poz[1].second=0;
        lmin=lmax=cmin=cmax=0;
        for(int i=2;i<=n;i++){
            f>>val>>ch;
            ind=transforma(ch);
            poz[i].first=poz[val].first+dx[ind];
            poz[i].second=poz[val].second+dy[ind];
            lmin=min(lmin,poz[i].first);
            lmax=max(lmax,poz[i].first);
            cmin=min(cmin,poz[i].second);
            cmax=max(cmax,poz[i].second);
        }
        if(cmin<=0){
            cmax+=(-cmin)+1;
            for(int i=1;i<=n;i++){
                poz[i].second+=(-cmin)+1;
            }
        }
        if(lmin<=0){
            lmax+=(-lmin)+1;
            for(int i=1;i<=n;i++){
                poz[i].first+=(-lmin)+1;
            }
        }
        g<<lmax<<' '<<cmax<<'\n';
        sort(poz+1,poz+n+1,criteriu);
        int k=1;
        for(int i=1;i<=lmax;i++){
            for(int j=1;j<=cmax;j++){
                if(poz[k].first==i&& poz[k].second==j&&k<=n){
                    g<<1<<' ';
                    k++;
                }else{
                    g<<0<<' ';
                }
            }
            g<<'\n';
        }
    }else{
        f>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f>>val;
                viz[(i-1)*m+j]=-val;
                if(cprima==0&&val==1){
                    cprima=j;
                }
                contor+=val;
            }
        }
        pair <int,int> aux;
        aux.first=1;
        aux.second=cprima;
        q.push(aux);
        viz[cprima]=1;
        int k=1;
        g<<contor<<' '<<cprima<<'\n';
        while(!q.empty()){
            aux=q.front();
            q.pop();
            x=aux.first;
            y=aux.second;
            for(int i=0;i<=3;i++){
                xx=x+dx[i];
                yy=y+dy[i];
                if(xx>=1&&xx<=n&&yy>=1&&yy<=m&& viz[(xx-1)*m+yy]==-1){
                    viz[(xx-1)*m+yy]=++k;
                    g<<viz[(x-1)*m+y]<<' '<<transforma_invers(i)<<'\n';
                    aux.first=xx;
                    aux.second=yy;
                    q.push(aux);
                }
            }
        }
    }
    return 0;
}
