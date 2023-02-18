
#include <iostream>
#include <fstream>
#include <deque>
#define val first
#define ind second

using namespace std;

ifstream f("deque.in");
ofstream g("deque.out");

int n,k,val;
deque<pair<int,int>> dq;
long long suma;

int main(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>val;
        while(!dq.empty()&&val<=dq.back().val){
            dq.pop_back();
        }
        dq.push_back(make_pair(val,i));
        while(dq.front().ind<i-k+1){
            dq.pop_front();
        }
        if(i>=k){
            suma+=dq.front().val;
        }
    }
    g<<suma;
    f.close();
    g.close();
}
