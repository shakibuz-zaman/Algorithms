#include<bits/stdc++.h>
#define lli long long int
using namespace std;
lli ar[]={-3,2,3,-7,2,4,-9,8,7};
lli kadan(lli a[],lli n,lli &x,lli &y){
    lli maxglob;
    lli maxc=maxglob=a[0];
    lli left=0,right=0;
    for(lli i=1;i<n;i++){
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
int arr[100][100]={{2,1,-3,-4,5},
                   {0,6,3,4,1},
                   {2,-2,-1,4,-5},
                   {-3,3,1,0,3}
                  };
lli max2d(int co,int ro){
    lli tar[10000];
    lli left=0,right=0,ml=0,mr=0,mu=0,md=0,maxsum=-999999999;
    for(int i=0;i<co;i++){
        for(int j=0;j<ro;j++)tar[j]=0;
        for(int j=i;j<co;j++){
            for(int k=0;k<ro;k++) tar[k]+=arr[k][j];
            lli rr,cc;
            lli msum=kadan(tar,ro,rr,cc);
            if(msum>maxsum){
                maxsum=msum;mu=rr;md=cc;
                ml=i;mr=j;
            }
            //cout<<ml<<" "<<mr<<endl<<mu<<" "<<md<<endl<<endl;
        }
    }
    //printf("%lld %lld\n%lld %lld\n",ml,mr,mu,md);
    cout<<"MaxSum : "<<maxsum<<"\n";
}
int main(){
    lli x,y;
    lli n;
    lli b[111];
    max2d(5,4);
    while(cin>>n){
        for(lli i=0;i<n;i++) cin>>b[i];
        cout<<kadan(b,n,x,y)<<endl;
    }
    cout<<kadan(ar,9,x,y);
}
