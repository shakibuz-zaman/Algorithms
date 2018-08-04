#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> edj[100],df;
int no,ed;
int d[111],f[111];
int timee;
int visited[1000],color[1000],st[1000],en[2000]={0};
int par[1111];
vector<int>task;
void input(){
    memset(visited,0,sizeof(visited));
    //memset(color,0,sizeof(color));
    //memset(par,-1,sizeof(par));
    cin>>no>>ed;
    int x,y;
    for(int i=0;i<ed;i++){
        cin>>x>>y;
        edj[x].pb(y);
    }

}
void print(int no){
    for(int i=1;i<=no;i++){
        cout<<i<<" -- ";
        for(int j=0;j<edj[i].size();j++)
            cout<<edj[i][j]<<" ";
        cout<<endl;
    }
}
void dfs_visit(int u){
    color[u]=1; /// coloring the graph gray
    timee++; ///increasing time
    d[u]=timee; /// setting starting time
    /// visiting all node using dfs
    for(int i=0;i<edj[u].size();i++){
        int v=edj[u][i];
        if(color[v]==0){
            par[v]=u;
            dfs_visit(v);
        }
    }
    color[u]=2; /// coloring black
    timee++;
    task.pb(u);
    f[u]=timee; /// setting finishing color
}

void dfs(){
    ///initializing graph
    for(int i=1;i<=no;i++){
        color[i]=0;
        par[i]=-1;
    }
    timee=0; /// initializing time to zero
    ///iterating through all node in the graph
    for(int i=1;i<=no;i++){
        if(color[i]==0)
            dfs_visit(i); /// iterating the all node connected to that node
    }
}

int main(){
    input();
    print(no);
    dfs();

    //sort(timee+1,time+1+no);
    cout<<endl;
    for(int i=1;i<=no;i++){
        cout<<task[i]<<endl;
    }
}

