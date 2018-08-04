#include<bits/stdc++.h>
using namespace std;
string lcs(string s,string ss){
    int slen=s.length(),sslen=ss.length();
    int dp[slen+3][sslen+3];
    for(int i=0;i<=slen;i++)dp[i][0]=0;
    for(int i=0;i<=sslen;i++)dp[0][i]=0;

    for(int i=1;i<=slen;i++){
        for(int j=1;j<=sslen;j++){
            if(s[i-1]==ss[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=0;
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    //cout<<endl;
    int len=-1,x=0,y=0;
    for(int i=1;i<=slen;i++){
        for(int j=1;j<=sslen;j++){
            if(dp[i][j]>len){
                len=dp[i][j];
                x=i;y=j;
            }
        }
    }
    string sub=s.substr(x-len,len);
    cout<<"LCS: "<<sub<<endl;
    cout<<"Length: "<<len<<endl;
    return sub;
}

int main(){

    //lcs("abcdaf","3bcdf");
    string s,ss;
    while(cin>>s){
        cin.ignore();
        cin>>ss;
        lcs(s,ss);
    }
    //lcs("abcdghnmdop","abcfghxmdopqr");
}
