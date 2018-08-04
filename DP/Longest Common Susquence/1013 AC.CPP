#include<bits/stdc++.h>
#define pb push_back
#define lli long long int
using namespace std;

void lcs(int t,string s,string ss){
    lli lcs[100][100],nl[100][100],noc[100][100];
    memset(lcs,0,sizeof(lcs));
    memset(nl,0,sizeof(nl));
    memset(noc,0,sizeof(noc));
    noc[0][0]=1;
    int slen=s.length(),sslen=ss.length();
    for(int i=1;i<=ss.length();i++){
        nl[0][i]=i;
        noc[0][i]=1;
    }
    for(int i=1;i<=s.length();i++){

        nl[i][0]=i;
        noc[i][0]=1;
    }
    for(int i=1;i<=s.length();i++){
        for(int j=1;j<=ss.length();j++){

            int l=i-1,m=j-1;
            nl[i][j]=i+j-lcs[i][j];
            if(s[l]==ss[m]){
                lcs[i][j]=lcs[i-1][j-1]+1;
                noc[i][j]=noc[i-1][j-1];
            }
            else{
                if(lcs[i-1][j]>lcs[i][j-1]){
                    lcs[i][j]=lcs[i-1][j];
                    noc[i][j]=noc[i-1][j];
                }
                else if(lcs[i][j-1]>lcs[i-1][j]){
                    lcs[i][j]=lcs[i][j-1];
                    noc[i][j]=noc[i][j-1];
                }
                else{
                    lcs[i][j]=lcs[i][j-1];
                    noc[i][j]=noc[i-1][j]+noc[i][j-1];
                }
            }
            nl[i][j]=i+j-lcs[i][j];
        }
    }
    for(int i=0;i<=s.length();i++){
        for(int j=0;j<= ss.length();j++){
            //cout<<lcs[i][j]<<"/"<<nl[i][j]<<"/"<<noc[i][j]<<"  ";
        }
        //cout<<endl;
    }
    cout<<"Case "<<t<<": "<<nl[slen][sslen]<<" "<<noc[slen][sslen]<<endl;
    //return 1;
}

int main(){
    int t;
    cin>>t;
    string str,str2;
    for(int i=1;i<=t;i++){
        cin>>str;
        cin.ignore();
        cin>>str2;
        lcs(i,str,str2);
        //cout<<endl;
    }
    return 0;

}


