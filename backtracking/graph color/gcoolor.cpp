#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int>edj[111];
int edmat[111][111];
int no,ed;
int color[111];
void input(){
    cin>>no>>ed;
    memset(edmat,0,sizeof(edmat));
    for(int i=0;i<ed;i++){
        int x,y;
        cin>>x>>y;
        edj[x].pb(y);
        edj[y].pb(x);
        edmat[x][y]=1;
        edmat[y][x]=1;
    }
}
bool issafe(int n,int co){
    for(int i=1;i<=no;i++){
        if(edmat[n][i] && co==color[i])
            return false;
    }
    return true;
}
void print(){
    cout<<"\n";
    for(int i=1;i<=no;i++)cout<<color[i]<<" ";
    cout<<endl;
}
void gcolor(int k,int m){
    for(int i=1;i<=m;i++){

        if(issafe(k,i)){
            color[k]=i;
            if(k==no){
               print();
               return;
            }
            else
                gcolor(k+1,m);
        }
    }
}

int main(){
    input();
    gcolor(1,3);
}
