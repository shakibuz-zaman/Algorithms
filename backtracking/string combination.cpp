#include<bits/stdc++.h>
using namespace std;
void print(string str,int lev){

}
void comutil(map<char,int> cnt,string ch,string res,int pos,int lev){
    if(lev>res.length()){
        //cout<<"Overflow\n";
        return;
    }
    cout<<res.substr(0,lev)<<endl;
    for(int i=pos;i<ch.length();i++){
        if(!cnt[ ch[i] ])
            continue;
        res[lev]=ch[i];
        cnt[ ch[i] ]--;
        comutil(cnt,ch,res,i,lev+1);
        cnt[ ch[i] ]++;
    }
}
void combinate(string str){
    sort(str.begin(),str.end());
    map<char,int> cnt;
    string res=str;
    string strm="";
    for(int i=0;i<str.length();i++){
        if(!cnt[ str[i] ])
            strm+=str[i];
        cnt[ str[i] ]++;
    }
    comutil(cnt,strm,res,0,0);
    cout<<endl<<endl;
}


int main(){
    string s;
    while(cin>>s){
        combinate(s);
    }
}
