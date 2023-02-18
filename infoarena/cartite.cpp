
#include <bits/stdc++.h>
#define NMAX 200
#define GMAX 100

using namespace std;

ifstream fi("cartite.in");
ofstream fo("cartite.out");

int p,m,n,xc,yc,k,x,y,x2,y2,r,g,xg,yg,nrp,nrnod,start;
int mat[NMAX+5][NMAX+5],viz[NMAX+5][NMAX+5];
int dx[]={0,-1,0,1,0,-2,0,0,2,-1,1,-1,1};
int dy[]={0,0,-1,0,1,0,-2,2,0,-1,-1,1,1};
map <pair<int,int>,int> mp;
pair<int,int> invmp[NMAX*NMAX+5];
queue <pair<int,int> > q;
vector <int> G[NMAX*NMAX+5];
pair<int,int> edges[GMAX+5];
bool used[GMAX+5];
int st[GMAX+5],top;
int ans[GMAX+5],lans;

void add_fox(){
    mat[x][y]=-1;
    if(r>=1){
        for(int i=1;i<=4;i++){
            if(1<=x+dx[i]&&x+dx[i]<=n&&1<=y+dy[i]&&y+dy[i]<=m){
                mat[x+dx[i]][y+dy[i]]=-1;
            }
        }
    }
    if(r==2){
        for(int i=5;i<=12;i++){
            if(1<=x+dx[i]&&x+dx[i]<=n&&1<=y+dy[i]&&y+dy[i]<=m){
                mat[x+dx[i]][y+dy[i]]=-1;
            }
        }
    }
}

void lee(){
    if(mat[xc][yc]==-2){
        xg=xc;
        yg=yc;
        nrp=0;
        return;
    }
    q.push(make_pair(xc,yc));
    pair<int,int> aux;
    while(!q.empty()){
        aux=q.front();
        q.pop();
        for(int i=1;i<=4;i++){
            if(mat[aux.first+dx[i]][aux.second+dy[i]]==0){
                mat[aux.first+dx[i]][aux.second+dy[i]]=mat[aux.first][aux.second]+1;
                q.push(make_pair(aux.first+dx[i],aux.second+dy[i]));
            }
            if(mat[aux.first+dx[i]][aux.second+dy[i]]==-2){
                xg=aux.first+dx[i];
                yg=aux.second+dy[i];
                nrp=mat[aux.first][aux.second]+1;
                return;
            }
        }
    }
}

void euler(){
    st[++top]=start;
    int node,edge,next_node;
    while(top){
        node=st[top];
        if(G[node].size()!=0){
            edge=G[node].back();
            G[node].pop_back();
            if(!used[edge]){
                used[edge]=true;
                next_node=node^edges[edge].first^edges[edge].second;
                st[++top]=next_node;
            }
        }else{
            ans[++lans]=node;
            top--;
        }
    }
    for(int i=1;i<=lans;i++){
        fo<<invmp[ans[i]].first<<' '<<invmp[ans[i]].second<<'\n';
    }
}

int main(){
    fi>>p>>n>>m>>xc>>yc;
    fi>>k;
    for(int i=0;i<=n+1;i++){
        mat[i][0]=mat[i][m+1]=-1;
    }
    for(int i=0;i<=m+1;i++){
        mat[0][i]=mat[n+1][i]=-1;
    }
    while(k--){
        fi>>x>>y>>r;
        add_fox();
    }
    fi>>g;
    for(int i=1;i<=g;i++){
        fi>>x>>y>>x2>>y2;
        if(!mp[make_pair(x,y)]){
            mp[make_pair(x,y)]=++nrnod;
            invmp[nrnod]=make_pair(x,y);
        }
        if(!mp[make_pair(x2,y2)]){
            mp[make_pair(x2,y2)]=++nrnod;
            invmp[nrnod]=make_pair(x2,y2);
        }
        if(mat[x][y]==0){
            mat[x][y]=-2;
            if(!start){
                start=mp[make_pair(x,y)];
            }
        }
        if(mat[x2][y2]==0){
            mat[x2][y2]=-2;
            if(!start){
                start=mp[make_pair(x2,y2)];
            }
        }
        x=mp[make_pair(x,y)];
        y=mp[make_pair(x2,y2)];
        G[x].push_back(i);
        G[y].push_back(i);
        edges[i]=make_pair(x,y);
    }
    if(p==1){
        lee();
        fo<<xg<<' '<<yg<<' '<<nrp<<'\n';
    }else{
        euler();
    }
    fi.close();
    fo.close();
}
