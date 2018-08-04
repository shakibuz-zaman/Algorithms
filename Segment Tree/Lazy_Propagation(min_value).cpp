#include<bits/stdc++.h>
#define mx 1000
#define INFINITE 99999999
using namespace std;
int ar[mx]={0,1,2,3,-1,0,6,4,10,56,7,8,0,-3,45},len=14;
int tree[mx*3],lazy[mx*3];
void ini(int node,int st,int en){
    if(st==en){
        tree[node]=ar[st];
        lazy[node]=0;
        return;
    }
    int left=node<<1,right=(node<<1)+1,mid=(st+en)/2;
    ini(left,st,mid);
    ini(right,mid+1,en);
    tree[node]=min(tree[left],tree[right]);
    lazy[node]=lazy[left]+lazy[right];
}
void update(int node,int st,int en,int p,int r,int x){
    if(en<p||st>r)
        return;
    int left=node<<1,right=(node<<1)+1,mid=(st+en)/2;
    if(lazy[node]){
        tree[node]+=lazy[node];
        if(st!=en){
            lazy[left]=lazy[node];
            lazy[right]=lazy[node];
        }
        lazy[node]=0;
    }
    if(st>=p&&en<=r){
        tree[node]+=x;
        if(st!=en){
            lazy[left]+=x;
            lazy[right]+=x;
        }
        return;
    }
    update(left,st,mid,p,r,x);
    update(right,mid+1,en,p,r,x);
    tree[node]=min(tree[left],tree[right]);
}
int query(int node,int st,int en,int p,int r){
    if(en<p||st>r)
        return INFINITE;
    int left=node<<1,right=(node<<1)+1,mid=(st+en)/2;
    if(lazy[node]){
        tree[node]+=lazy[node];
        if(st!=en){
            lazy[left]=lazy[node];
            lazy[right]=lazy[node];
        }
        lazy[node]=0;
    }
    if(st>=p&&en<=r){
        return tree[node];
    }
    int p1=query(left,st,mid,p,r);
    int p2=query(right,mid+1,en,p,r);
    return min(p1,p2);
}
int main(){
    ini(1,1,len);
    //update(1,1,len,1,len,2);
    int addition=3;
    update(1,1,len,1,len,addition); //addition will be added to all element between 1 to len
    /*for(int i=0;i<=42;i++)
        cout<<lazy[i]<<" ";
        cout<<endl;*/
    int p,r;
    while(cin>>p>>r){
        cout<<query(1,1,len,p,r)<<endl;
    }
}
