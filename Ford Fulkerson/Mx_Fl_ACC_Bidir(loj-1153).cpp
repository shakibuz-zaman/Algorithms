#include<bits/stdc++.h>
#define pb push_back
#define f firs
#define s second
#define MAX 1000
using namespace std;
bool bfs(int src,int sinc);
void print_path(vector<vector<int> > v);
void vclear();

vector<int>edj[MAX],cost[MAX];
int no,ed;
int rcap[MAX][MAX],cap[MAX][MAX],par[MAX];

void input(){
    memset(rcap,0,sizeof(rcap));
    memset(cap,0,sizeof(cap));

    for(int i=0;i<ed;i++){
        int x,y,w;
        cin>>x>>y>>w;

        if(rcap[x][y]){
            rcap[x][y]+=w,rcap[y][x]+=w;
            cap[MAX][MAX]+=w;
            continue;
        }
        edj[x].pb(y),edj[y].pb(x);
        cap[MAX][MAX]=w;
        rcap[x][y]=w,rcap[y][x]=w;
    }
}
int ford_fulkerson(int src,int sinc){
    int max_flow=0;
    vector<vector<int> >aug_path;
    while(bfs(src,sinc)){
        vector<int>path;
        int tmp=sinc,vp;
        int flow=INT_MAX;
        while(tmp!=src){
            vp=par[tmp];
            path.pb(tmp);
            flow=min(rcap[vp][tmp],flow);
            tmp=vp;
        }
        path.pb(src);
        reverse(path.begin(),path.end());
        aug_path.pb(path);

        max_flow+=flow;

        tmp=sinc;
        while(tmp!=src){
            vp=par[tmp];
            rcap[vp][tmp]-=flow;
            rcap[tmp][vp]+=flow;
            tmp=vp;
        }

    }
    //print_path(aug_path);
    vclear();
    return max_flow;
}
int main(){

    int t,st,en;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>no>>st>>en>>ed;
        input();
        int ff=ford_fulkerson(st,en);
        printf("Case %d: %d\n",i,ff);

    }
    return 0;
}

bool bfs(int src,int sinc){
    queue<int> Q;
    int vis[MAX];
    memset(vis,0,sizeof(vis));
    memset(par,0,sizeof(par));
    Q.push(src);
    vis[src]=1;
    bool findaug=false;
    while(!Q.empty()){
        int u=Q.front();
        if(u==sinc){
            findaug=true;
            break;
        }
        for(int i=0;i<edj[u].size();i++){
            int v=edj[u][i];
            if(!vis[v] && rcap[u][v]>0){
                Q.push(v);
                vis[v]=1;
                par[v]=u;
            }
        }
        Q.pop();
    }
    return findaug;
}

void print_path(vector<vector<int> > v){
    cout<<endl;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<"->";
        cout<<endl;
    }
    cout<<endl;
}
void vclear(){
    for(int i=0;i<=no;i++)edj[i].clear(),cost[i].clear();
}
