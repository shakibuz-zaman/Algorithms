#include<bits/stdc++.h>
using namespace std;
int ar[]={-3,2,3,-7,2,4,-9,8,7};
int kadan(int a[],int n,int &x,int &y){
    int maxglob;
    int maxc=maxglob=a[0];
    int left=0,right=0;
    for(int i=1;i<n;i++){
        bool f=true;
        if(a[i]>maxc+a[i]){
            maxc=a[i];
            left=i;right=i;
        }
        else maxc=a[i]+maxc;
        if(maxglob<maxc){ maxglob=maxc;right=i;}
    }
    x=left;y=right;
    //cout<<left<<" "<<right<<endl;
    return maxglob;
}
int main(){
    int x,y;
    int n;
    int b[111];
    while(cin>>n){
        for(int i=0;i<n;i++) cin>>b[i];
        cout<<kadan(b,n,x,y)<<endl;
    }
    cout<<kadan(ar,9,x,y);
}
