#include<bits/stdc++.h>
using namespace std;
map<string,string> par;
map<string,int>dm;
string findr(string s);
vector<string> vd;
int makefr(string s1,string sm);
int main(){

    int i,j,t,n,maxi,r;
    string s1,s2,stmp;
    while(1){
        cin>>n>>r;
        if(n+r==0)
            break;
        maxi=1;
        par.clear();
        dm.clear();
        for(j=1;j<=n;j++){
            cin>>s1;
            par[s1]=s1;
            dm[s1]=1;
        }
        for(j=1;j<=r;j++){
            cin>>s1>>s2;
            maxi=max(maxi,makefr(s1,s2));
        }
        cout<<maxi<<endl;
    }
    return 0;
}
string findr(string s){
    if(par[s]==s)
        return s;
    par[s]=findr(par[s]);
    return par[s];
}
int makefr(string s1,string sm){
    int m=0;
    string s=findr(s1),ss=findr(sm);
    if(s==ss)
        return dm[s];
    par[s]=ss;

    dm[ss]+=dm[s];//dm[s]+=dm[s];

    return dm[ss];
}

