#include<bits/stdc++.h>
using namespace std;
void show(vector<vector<char> >S,string X,int i,int j){
    if(i==-1||j==-1)return;
    else if(S[i][j]=='s'){
        show(S,X,i-1,j-1);
        cout<<X[i];
    }
    else if(S[i][j]=='j'){
        show(S,X,i,j-1);
    }
    else{
        show(S,X,i-1,j);
    }
}
int lcs(string ss,string s){
    int slen=s.length(),sslen=ss.length();
    int dp[slen+3][sslen+3];
    for(int i=0;i<=slen;i++)dp[i][0]=0;
    for(int i=0;i<=sslen;i++)dp[0][i]=0;
    vector<vector<char> >mm;

    for(int i=0;i<=s.length();i++){
        mm.push_back(vector<char>(ss.length()+1));
    }
    for(int i=1;i<=slen;i++){
        for(int j=1;j<=sslen;j++){
            if(s[i-1]==ss[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                mm[i-1][j-1]='s';
            }
            else{
                if(dp[i][j-1]>=dp[i-1][j]) mm[i-1][j-1]='j';
                else mm[i-1][j-1]='i';
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }

    /*for(int i=0;i<=slen;i++){
        for(int j=0;j<=sslen;j++)cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;*/
    show(mm,s,slen-1,sslen-1);
    cout<<endl;

    /*for(int i=0;i<=slen;i++){
        for(int j=0;j<=sslen;j++)cout<< mm[i][j]<<" ";
        cout<<endl;
    }*/
    /*int len=-1,x=slen,y=sslen;
    while(1){
        //cout<<x<<" "<<y<<endl;
        if(x<=0 || y<=0)break;
        if(s[x-1]==ss[y-1]){
            cout<<s[x-1]<<" ";
            x--;y--;
        }
        if(dp[x][y]==dp[x-1][y])x--;
        if(dp[x][y]==dp[x][y-1])y--;
    }*/
    return dp[slen][sslen];
}

int main(){
    string str,st;
    while(cin>>str){
        cin.ignore();
        cin>>st;
        lcs(str,st);
    }
    lcs("AGGTAB","GXTXAYB");
}
