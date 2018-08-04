#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define f first
#define s second
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
using namespace std;
int a[111]={0,2,-1,4,3,5,-1,3,2};
int ltr[111],rtl[111];
int lis(int a[],int n){
    for(int i=0;i<=n;i++)ltr[i]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<a[i]){

                ltr[i]=max(ltr[j]+1,ltr[i]);
            }
        }

    }
    //for(int i=1;i<=n;i++)cout<<ltr[i]<<" ";
    cout<<endl;
    for(int i=0;i<=n;i++)rtl[i]=1;
    for(int i=n-1;i>=1;i--){
        for(int j=n;j>i;j--){
            if(a[j]<a[i]){

                rtl[i]=max(rtl[j]+1,rtl[i]);
            }
        }

    }
    for(int i=1;i<=n;i++)cout<<rtl[i]<<" ";
    cout<<endl;
    int mx=-1;
    for(int i=1;i<=n;i++)
        mx=max(ltr[i]+rtl[i]-1,mx);
    cout<<mx<<endl;
    return mx;
}

void res(int n,int p,int k){

}
int main(){
    int n,k;
    lis(a,8);
    return 0;
}
