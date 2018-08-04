#include<bits/stdc++.h>
#define N 8
#define pb push_back
using namespace std;
bool issafe(int kt[N+1][N+1],int x,int y){
    return (x<=N&&x>=1&&y<=N&&y>=1&&kt[x][y]==-1);
}

/* A utility function to print solution matrix sol[N][N] */
void printSol(int sol[N+1][N+1]){
    cout<<endl;
    for (int x = 1; x<=N; x++)
    {
        for (int y = 1; y<=N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
    cout<<endl;
}
bool SolveUtil(int kt[N+1][N+1],int x,int y,int num){
    //cout<<x<<" "<<y<<"->"<<num<<endl;
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    if(num>N*N)return true;
    for(int i=0;i<8;i++){
        int nx=x+xMove[i],ny=y+yMove[i];
        if( issafe(kt,nx,ny) ){
            kt[nx][ny]=num;
            if(SolveUtil(kt,nx,ny,num+1))return true;
            else kt[nx][ny]=-1;
        }
    }
    return false;
}
void MainUtil(){
    int kt[N+1][N+1];
    memset(kt,-1,sizeof(kt));
    kt[1][1]=1;
    if(!SolveUtil(kt,1,1,2)) cout<<"Solution Not exists\n";
    else printSol(kt);

}

int main(){
    MainUtil();
}
