#include<bits/stdc++.h>
#define pb push_back
#define MAX 10000

using namespace std;
void input();
void show();
int chkbit(int N,int pos){return N&(1<<pos);}

vector<int> edj[MAX];
int parent[MAX],visited[MAX]={0},L[MAX];
int P[MAX][MAX];
int no,ed;
int tpow(int N){
    int con=0;
    while(1){
        int nxt=con+1;
        if(1<<nxt>N)break;
        con++;
    }
    return con;
}
void dfs(int n){
    if(edj[n].size()==0)
        return;
    visited[n]=1;
    for(int i=0;i<edj[n].size();i++){
        int u=edj[n][i];
        if(!visited[u]){
            parent[u]=n;
            L[u]=L[n]+1;
            dfs(u);
        }
    }
}
void ini(){
    L[0]=0;
    dfs(0);
    memset(P,-1,sizeof(P));
    for(int i=1;i<=no;i++)
        P[i][0]=parent[i];
    for(int j=1;(1<<j)<=no;j++){
        for(int i=1;i<=no;i++){
            if (P[i][j - 1] != -1)
                P[i][j]=P[ P[i][j-1] ][j-1];
        }
    }
}
int query(int p,int q){
    int tmp,x,y,next;
    if(L[p]<L[q]){
        tmp=p;
        p=q;
        q=tmp;
    }
    int diff=L[p]-L[q];
    int fnum=0;
    int cnt=0;
    while(fnum<diff){
        if(chkbit(diff,cnt)){
            p=P[p][cnt];     /// let's go to level 2 from 7;as differnt is 5 in binary
            fnum+=(1<<cnt);   /// 5 is 101,we can jump up 5 level by using binary
        }                     /// value that sum up 5;
        cnt++;
    }
    cout<<endl;
    if(p==q)return p;
    int log=tpow(L[p]);
    for(int i=log;i>=0;i--){
        if(P[p][i]!=-1&&P[p][i]!=P[q][i]){
            p=P[p][i];
            q=P[q][i];
        }
    }
    return parent[p];
}

int main(){
    input();
    ini();
    int x,y;
    while(cin>>x>>y){
        cout<<query(x,y)<<endl;
    }
    system("PAUSE");
}
void input(){
    int i,m,s,ww;
    cin>>no>>ed;
    for(i=1;i<=ed;i++){
        cin>>m>>s>>ww;
        edj[m].pb(s);
        edj[s].pb(m);
    }

}
void show(){
    int i,j;
    for(i=0;i<=no;i++){
        cout<<"Node "<<i<<" has cnnection with : ";
        for(j=0;j<edj[i].size();j++){
            cout<<edj[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=no;i++)
        cout<<i<<"  -  "<<L[i]<<" -- "<<parent[i]<<endl;
}

