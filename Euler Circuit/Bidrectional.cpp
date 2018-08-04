#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> edj[100],df,revedj[100];
vector<int>scv[111];
int deg[100];
int no,ed;
void input(){
    memset(deg,0,sizeof(deg));
    cin>>no>>ed;
    int x,y;
    for(int i=0;i<ed;i++){
        cin>>x>>y;
        edj[x].pb(y);
        edj[y].pb(x);
        deg[x]++,deg[y]++;
    }

}
int main(){

}
