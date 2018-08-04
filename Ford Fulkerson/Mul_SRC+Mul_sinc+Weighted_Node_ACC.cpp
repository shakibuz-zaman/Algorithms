#include<bits/stdc++.h>
#define pb push_back
#define f firs
#define s second
#define MAX 1000
using namespace std;
bool bfs(int src,int sinc);
void print_path(vector<vector<int> > v);
void vclear();
void wini();
void print(vector<int> edjj[],int no);

vector<int>edj[MAX],cost[MAX];
int no,ed,nsrc,nend;
int rcap[MAX][MAX],cap[MAX][MAX],par[MAX],ncap[MAX],in[MAX],out[MAX],cn[MAX];

void pr_p(vector<int>v){
    cout<<endl;
    for(int i=0;i<v.size();i++)cout<<v[i]<<"->";
    cout<<endl;
}
void input(){
    for(int i=0;i<ed;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edj[ cn[x] ].pb(y),edj[y].pb(cn[x]);
        cap[ cn[x] ][y]=w,rcap[ cn[x] ][y]=w;
    }
}
void reshape(vector<int>vsrc,vector<int>vend){
    int v;
    ncap[0]=INT_MAX,ncap[2*no+1]=INT_MAX;
    for(int i=0;i<vsrc.size();i++){
        v=vsrc[i];
        edj[0].pb(v),edj[v].pb(0);
        cap[0][ v ]=INT_MAX,rcap[0][ v ]=INT_MAX;
    }

    for(int i=0;i<vend.size();i++){
        v=cn[ vend[i] ];
        edj[v].pb(2*no+1),edj[2*no+1].pb(v);
        cap[v][ 2*no+1 ]=INT_MAX,rcap[v][ 2*no+1 ]=INT_MAX;
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
            //cout<<tmp<<" ";
            vp=par[tmp];
            path.pb(tmp);
            flow=min(rcap[vp][tmp],flow);
            //printf("rcap[%d][%d]=%d\nFlow=%d\n",vp,tmp,rcap[vp][tmp],flow);
            tmp=vp;
        }
        //cout<<endl;
        path.pb(src);
        reverse(path.begin(),path.end());
        //pr_p(path);
        aug_path.pb(path);
        //cout<<"Flow="<<flow<<endl;
        max_flow+=flow;

        tmp=sinc;
        while(tmp!=src){
            vp=par[tmp];
            rcap[vp][tmp]-=flow;
            rcap[tmp][vp]+=flow;
            //tmp[]
            tmp=vp;
        }

    }
    //print_path(aug_path);
    vclear();
    return max_flow;
}
int main(){

    int t,st,en,x;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>no;
        wini();
        for(int j=1;j<=no;j++){
            cin>>x;
            edj[j].pb(cn[j]);
            edj[ cn[j] ].pb(j);
            rcap[j][ cn[j] ]=x;
        }
        cin>>ed;
        input();
        //print(edj,2*no);
        cin>>nsrc>>nend;
        vector<int>vsrc,vend;
        for(int j=0;j<nsrc;j++)cin>>x,in[x]=INT_MAX,vsrc.pb(x);
        for(int j=0;j<nend;j++)cin>>x,out[x]=INT_MAX,vend.pb(x);
        reshape(vsrc,vend);
        //print(edj,2*no);

        int ff=ford_fulkerson(0,2*no+1);
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
    //cout<<"Found\n";
    return findaug;
}

void wini(){
    memset(rcap,0,sizeof(rcap));
    memset(cap,0,sizeof(cap));
    for(int i=1;i<=no;i++)cn[i]=no+i;
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

void print(vector<int> edjj[],int no){
    cout<<endl<<endl;
    for(int i=0;i<=no;i++){
        cout<<i<<" -- ";
        for(int j=0;j<edjj[i].size();j++)
            cout<<edjj[i][j]<<"("<<rcap[i][ edjj[i][j] ]<<")  ";
        cout<<endl;
    }
    cout<<endl<<endl;
}
