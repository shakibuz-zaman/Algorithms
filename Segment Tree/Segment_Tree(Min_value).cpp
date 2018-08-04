#include<bits/stdc++.h>
#define MAX 100
#define inf 99999999999
using namespace std;

int res=99999999;
int ar[MAX]={0,1,2,3,-1,0,6,4,10,56,7,8,0,-3,45};
int tree[MAX],len=14;
void ini(int node,int st,int en);
void update(int node,int st,int en,int p,int x);
int query(int node,int st,int en,int p,int r);

int main(){
    ini(1,1,len);
    int pos=13,x=14;
    update(1,1,len,pos,x); //position pos will be replaced with x
    cout<<query(1,1,len,13,14);
}
void ini(int node,int st,int en){
    if(st==en){
        tree[node]=ar[st];
        return;
    }
    int left=2*node,right=2*node+1,mid=(st+en)/2;
    ini(left,st,mid);
    ini(right,mid+1,en);
    tree[node]=min(tree[left],tree[right]);
}
int query(int node,int st,int en,int p,int r){
    if(st>r||en<p)
        return INT_MAX;
    if(st>=p&&en<=r){
        //res=max(res,tree[node]);
        return tree[node];
    }
    int left=2*node,right=2*node+1,mid=(st+en)/2;
    int p1=query(left,st,mid,p,r);
    int p2=query(right,mid+1,en,p,r);
    return min(p1,p2);
}
void update(int node,int st,int en,int p,int x){
    int left=2*node,right=2*node+1,mid=(st+en)/2;
    if(st==p&&en==p){
        tree[node]=x;
        return;
    }
    if(st>p||en<p)
        return;
    update(left,st,mid,p,x);
    update(right,mid+1,en,p,x);
    tree[node]=max(tree[left],tree[right]);
}
