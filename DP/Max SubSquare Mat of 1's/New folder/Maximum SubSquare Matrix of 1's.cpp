#include<bits/stdc++.h>
using namespace std;
int mat[23][23]={{0,0,1,1,1},
                 {1,0,1,1,1},
                 {0,1,1,1,1},
                 {1,0,1,1,1}
                };
int res(int ro,int col){
    int tmat[23][23];
    for(int i=0;i<col;i++)
        tmat[0][i]=0;
    for(int i=0;i<ro;i++)
        tmat[i][0]=0;
    int tt=-99999999;
    for(int i=1;i<=ro;i++){
        for(int j=1;j<=col;j++){
            if(mat[i-1][j-1]==1)tmat[i][j]=min(tmat[i-1][j],min(tmat[i-1][j-1],tmat[i][j-1]))+1;
            else tmat[i][j]=0;
            tt=max(tt,tmat[i][j]);
        }
        //cout<<endl;
    }
    return tt;
}
int main(){
    cout<<res(4,5); //4 for row and 5 for column
}
