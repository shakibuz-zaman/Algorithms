#include<bits/stdc++.h>
#define pb push_back
#define N 9
using namespace std;

bool issafe(int grid[N+1][N+1],int row,int col,int num){
    int box=sqrt(N),s1=row-((row%box!=0)?row%box:box)+1,s2=s1+box-1;
    int e1=col-((col%box!=0)?col%box:box)+1,e2=e1+box-1;
    for(int i=1;i<=N;i++)
        if(grid[row][i]==num)return false;

    for(int i=1;i<=N;i++)
        if(grid[i][col]==num)return false;

    for(int i=s1;i<=s2;i++)
        for(int j=e1;j<=e2;j++)
            if(grid[i][j]==num)return false;
    return true;
}
bool findnext(int grid[N+1][N+1],int &row,int &col){
    int best=100;
    bool var=false;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            if(grid[i][j]!=-1)continue;
            int co=0;
            for(int k=1;k<=N;k++)
                if(issafe(grid,i,j,k)) co++;
            if(co<best)row=i,col=j,best=co,var=true;

        }
    return var;
}


bool SolveSuduku(int grid[N+1][N+1]){
    int row,col;
    if(!findnext(grid,row,col))return true;
    for(int num=1;num<=N;num++){
        if(issafe(grid,row,col,num)){
            grid[row][col]=num;
            if(SolveSuduku(grid))return true;
            else grid[row][col]=-1;
        }
    }
    return false;
}
void ini_input(int grid[N+1][N+1]){
    char ch;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>ch;
            if(ch=='.')grid[i][j]=-1;
            else grid[i][j]=(int)(ch-'0');
        }
    }
}
void print(int grid[N+1][N+1]){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            cout<<grid[i][j]<<"";
        cout<<endl;
    }
}

int main(){
    int t,grid[N+1][N+1];
    cin>>t;
    for(int i=1;i<=t;i++){
        ini_input(grid);
        printf("Case %d:\n",i);
        SolveSuduku(grid);
        print(grid);
    }
    return 0;
}
