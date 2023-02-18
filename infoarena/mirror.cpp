
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream f("mirror.in");
ofstream g("mirror.out");

int cerinta,n,k,sir[100005],ok,ls,nr,p;
string s="";

int afla_l(int &st,int &dr){
    int masca=1,auxdr=0,l=0,contor=0,ok=0;
    do{
        ok=0;
        contor=0;
        for(int i=st;i<=dr;i++){
            if(masca<sir[i]){
                ok=1;
            }
            if((masca&sir[i])>0){
                contor++;
            }else{
                if(contor>l){
                    l=contor;
                    auxdr=i-1;
                }
                contor=0;
            }
        }
        if(contor>l){
            l=contor;
            auxdr=dr;
        }
        masca<<=1;
    }while(ok);
    dr=auxdr;
    st=auxdr-l+1;
    return l;
}

void afla_secventa(){
    int stanga=0,dreapta=0,i=1,l=0,laux,rezst,rezdr;
    while(sir[i]==0&&i<=n){
        i++;
    }
    while(i<=n){
        if(sir[i]!=0){
            if(stanga==0){
                stanga=i;
                dreapta=i;
            }else{
                dreapta++;
            }
        }else{
            if(stanga!=0){
                laux=afla_l(stanga,dreapta);
                if(laux>l){
                    l=laux;
                    rezst=stanga;
                    rezdr=dreapta;
                }
            }
            stanga=0;
        }
        i++;
    }
     if(stanga!=0){
        laux=afla_l(stanga,dreapta);
        if(laux>l){
            l=laux;
            rezst=stanga;
            rezdr=dreapta;
        }
    }
    g<<l<<'\n'<<rezst<<' '<<rezdr<<'\n';
}

int main(){
    f>>cerinta>>n>>k;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    if(cerinta==1){
        for(int i=1;i<=n;i++){
            ok=0;
            for(int j=31;j>=0;j--){
                if(((sir[i]>>j)&1)==1 && ok==0){
                    ok=1;
                }
                if(ok==1){
                    if(((sir[i]>>j)&1)==1){
                        s+="1";
                    }else{
                        s+="0";
                    }
                }
            }
        }
        ls=s.length();
        for(int i=0;i+k-1<ls;i+=k){
            p=1<<(k-1);
            nr=0;
            for(int j=i;j<=i+k-1;j++){
                if(s[j]=='1'){
                    nr+=p;
                }
                p>>=1;
            }
            g<<nr<<' ';
        }
        f.close();
        g.close();
        return 0;
    }else{
        int cif[35],masca,nrcif,aux,contor,q;
        if(k){
            for(int i=1;i<=n;i++){
                masca=1<<30;
                while((masca&sir[i])==0){
                    masca>>=1;
                }
                nrcif=0;
                while(masca){
                    if((masca&sir[i])==0){
                        cif[++nrcif]=0;
                    }else{
                        cif[++nrcif]=1;
                    }
                    masca>>=1;
                }
                aux=1;
                contor=0;
                for(int j=1;j<=nrcif;j++){
                    if(aux!=cif[j]){
                        contor++;
                        if(aux==0){
                            aux=1;
                        }else{
                            aux=0;
                        }
                    }
                }
                if(contor<k){
                    sir[i]=0;
                }else{
                    if(k%2==1){
                        for(int j=1;j<=nrcif;j++){
                            if(cif[j]==1){
                                cif[j]=0;
                            }else{
                                cif[j]=1;
                            }
                        }
                    }
                    contor=0;
                    q=1;
                    while(contor<k&& q<=nrcif){
                        q++;
                        if(cif[q]!=cif[q-1]){
                            contor++;
                        }
                    }
                    if(q>nrcif){
                        sir[i]=0;
                    }else{
                        nr=0;
                        p=1;
                        for(int o=nrcif;o>=q;o--){
                            nr+=p*cif[o];
                            p<<=1;
                        }
                        sir[i]=nr;
                    }
                }
            }
        }
        afla_secventa();
    }
    f.close();
    g.close();
}
