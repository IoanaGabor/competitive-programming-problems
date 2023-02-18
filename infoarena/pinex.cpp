#include <iostream>
#include <fstream>
#define SQRT 1000000
#define LPRIME 78500

using namespace std;

ifstream f("pinex.in");
ofstream g("pinex.out");

int q,lprime,lfact;
bool ciur[SQRT+5];
long long a,b,rez;
int prime[LPRIME+5];
long long fact[30];

void calc_prime(){
	for(int i=2;i<=SQRT;i++){
		if(!ciur[i]){
			prime[++lprime]=i;
			for(int j=i*2;j<=SQRT;j+=i){
				ciur[j]=true;
			}
		}
	}
}

void descnumar(long long x){
	lfact=0;
	for(int i=1;prime[i]<=x&&i<=lprime;i++){
		if(x%prime[i]==0){
			fact[++lfact]=prime[i];
			while(x%prime[i]==0){
				x/=prime[i];
			}
		}
	}
	if(x!=1){
		fact[++lfact]=x;
	}
}

void numara(){
	rez=0;
	long long div,nr;
	int cnt;
	for(int i=1;i<(1<<lfact);i++){
		div=1;
		cnt=0;
		for(int j=0;j<lfact;j++){
			if((i&(1<<j))){
				div*=1LL*fact[j+1];
				cnt++;
			}
		}
		nr=1LL*a/div;
		if(cnt%2==0){
			rez-=nr;
		}else{
			rez+=nr;
		}
	}
	rez=a-rez;
}

int main(){
   calc_prime();
   f>>q;
   while(q--){
      f>>a>>b;
      descnumar(b);
      numara();
      g<<rez<<'\n';
   }
}
