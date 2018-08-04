#include<bits/stdc++.h>
#define pb push_back
#define lli long long int
#define f first
#define s second
#define CI( x ) scanf("%d",&x)
#define CL( x ) scanf("%lld",&x)
#define CD( x ) scanf("%lf",&x )
#define CII( x,y ) scanf("%d%d",&x,&y)
#define CLL( x,y ) scanf("%lld%lld",&x,&y)
#define CDD( x,y ) scanf("%lf%lf",&x,&y )
#define MOD 1000000007
#define M 11
using namespace std;
int n,grid[M][M],mx;
vector<pair<int,int> >pos;
template < typename T > std::string to_string( const T& n ){
    ostringstream stm ;
    stm << n ;
    return stm.str() ;
}

bool issafe(int mgrid[M][M],int x,int y){
    return (grid[x][y]==1&&mgrid[x][y]==-1);
}


void fillgrid(int x,int y,int in){
    for(int i=1;i<=y;i++)grid[in][x+i]=1;
}
void print(){
    cout<<endl;
    for(int i=1;i<=7;i++){
        for(int j=1;j<=7;j++)cout<<grid[i][j];
        cout<<endl;
    }
    cout<<endl;
}
int SolveUtil(int kt[M][M],int x,int y,int num){
    //cout<<x<<" "<<y<<"->"<<num<<endl;
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    //cout<<num<<" "<<mx<<endl;
    int tt=-1;
    for(int i=0;i<8;i++){
        int nx=x+xMove[i],ny=y+yMove[i];
        if( issafe(kt,nx,ny) ){
            kt[nx][ny]=num;
            int tm=SolveUtil(kt,nx,ny,num+1);
            if(tm>mx){
                mx=tm;
                //return mx;
            }
            kt[nx][ny]=-1;
        }
    }
    return num-1;
}
void MainUtil(){
    int kt[M][M];
    memset(kt,-1,sizeof(kt));
    mx=1;
    kt[1][1]=1;
    int res=SolveUtil(kt,1,pos[0].f+1,2);
}

int main(){
    int x,y,sq,t=1;
    while(CI(n)){
        if(n==0)break;
        pos.clear();
        memset(grid,0,sizeof(grid));
        sq=0;
        if(!n)break;
        for(int i=1;i<=n;i++)cin>>x>>y, sq+=y, pos.pb(make_pair(x,y)), fillgrid(x,y,i);
        MainUtil();
        int rr=sq-mx;//<<endl;
        printf("Case %d, %d ",t,rr);
        if(rr==1)cout<<"square can not be reached.\n";//,t,rr);
        else cout<<"squares can not be reached.\n";
        t++;
    }
    return 0;
}
