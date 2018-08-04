#include<bits/stdc++.h>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
struct info{
    bool endmark;
    info *next[26+1];
    info(){
        endmark=false;
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
    }
}*root;
void insertion(char *str,int len){
    info *curr=root;
    int i;
    for(i=0;i<len;i++){
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id]=new info();
        curr=curr->next[id];
    }
    curr->endmark=true;
}
bool search(char *str,int len)
{
    info *curr=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL) return false;
        curr=curr->next[id];
    }
    return curr->endmark;
}
void del(info *cur){
    for(int i=0;i<26;i++)
        if(cur->next[i])
            del(cur->next[i]);
        delete(cur);
}
int main(){
    int i,j,n,x,y;
    char s[100],ss[100];
    root=new info();
    cout<<"Enter Number of word : ";
    cin>>n;
    FOR(i,n){
        cin>>s;
        insertion(s,strlen(s));
    }
    cout<<"Number of query : ";
    cin>>x;
    for(i=0;i<x;i++){
        cin>>ss;
        //cout<<s<<endl;
        if(search(ss,strlen(ss)))
            cout<<"Found\n";
        else
            cout<<"Not found\n";
    }
    del(root);

}
