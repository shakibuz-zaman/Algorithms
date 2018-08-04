#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> edj[100],df;
int no,ed;
int visited[1000];
void input(){
    memset(visited,0,sizeof(visited));
    cin>>no>>ed;
    int x,y;
    for(int i=0;i<ed;i++){
        cin>>x>>y;
        edj[x].pb(y);
    }
}

void dfs(int src){
    df.pb(src);
    visited[ src ]=1;
    cout<<src<<" ";
    if(edj[src].empty())
        return;
    for(int i=0;i<edj[src].size();i++){
        if(!visited[ edj[src][i] ]){

            dfs(edj[src][i]);
        }
    }
}
int main(){
    input();
    dfs(1);
}
