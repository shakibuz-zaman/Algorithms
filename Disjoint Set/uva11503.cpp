#include<bits/stdc++.h>
using namespace std;
map<string,string> par;
map<string,int>dm;
string findr(string s);
int makefr(string s1,string sm);
int main(){

    int i,j,t,n;
    string s1,s2,stmp;
    cin>>t;
    for(i=1;i<=t;i++){
        par.clear();
        dm.clear();
        cin>>n;
        for(j=1;j<=n;j++){
            cin>>s1>>s2;
            if(!dm[s1]){
                par[s1]=s1;
                dm[s1]=1;
            }
            if(!dm[s2]){
                par[s2]=s2;
                dm[s2]=1;
            }
            cout<<makefr(s1,s2)<<endl;;
        }
    }
}
string findr(string s){
    if(par[s]==s)
        return s;
    par[s]=findr(par[s]);
    return par[s];
}
int makefr(string s1,string sm){
    string s=findr(s1),ss=findr(sm);
    if(s==ss)
        return dm[s];
    par[s]=ss;
    dm[ss]+=dm[s];dm[s]+=dm[s];
    return dm[ss];
}
