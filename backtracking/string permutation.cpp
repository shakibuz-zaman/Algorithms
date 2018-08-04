#include<bits/stdc++.h>
using namespace std;
void permututil(map<char,int>cnt,string ch,char res[],int level,int slen){
    if(level==slen){
        res[level]='\0';
        cout<<res<<endl;
        return;
    }

    for(int i=0;i<ch.length();i++){
        if(cnt[ ch[i] ]){
            res[level]=ch[i];
            cnt[ ch[i] ]--;
            permututil(cnt,ch,res,level+1,slen);
            cnt[ ch[i] ]++;
        }
    }
}
void permut(string str){
    sort(str.begin(),str.end());
    map<char,int> cnt;
    char res[111];
    string strm="";
    for(int i=0;i<str.length();i++){
        if(!cnt[ str[i] ])
            strm+=str[i];
        cnt[ str[i] ]++;
    }
    ///for(int i=0;i<strm.length();i++)
        ///cout<<strm[i]<<"   "<<cnt[ strm[i] ]<<endl;

    permututil(cnt,strm,res,0,str.length());
    cout<<endl<<endl;
}

int main(){
    string str;
    while(cin>>str){
        permut(str);
    }
}
