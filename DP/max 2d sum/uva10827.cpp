#include<bits/stdc++.h>
#define lli long long int
using namespace std;
//lli ar[12]={3,3,-3,-5,5,6,-1,2,1};
lli rar[111];
lli rar2d[111][111];
void arrange(lli ar[],lli n){
    lli cum[n+1],sum=0,left=-1,right=0;
    for(int i=0;i<n;i++){
        if(ar[i]<0)cum[i]=sum=sum+ar[i];
        else cum[i]=(i==0)?0:cum[i-1];
    }
    //for(int i=0;i<n;i++) cout<<cum[i]<<" ";
    //cout<<endl;
    lli i=1;
    bool lb;
    if(cum[0]<cum[n-1]) lb=true;
    else left++;
    while(cum[i]>cum[n-1]-cum[i-1]){
        if(lb){break;}
        i++;
        left++;
    }
    if(left==-1)left=n-1;
    lli in=0;
    for(int i=left;i>=0;i--)rar[in++]=ar[i];
    for(int i=n-1;i>left;i--)rar[in++]=ar[i];
    //for(int i=0;i<n;i++) cout<<rar[i]<<" ";
    //cout<<endl;
}
void arrange2d(int a[111][111],int n){
    lli ar[111];
    for(int j=0;j<n;j++){
        lli sum=0;
        for(int i=0;i<n;i++)sum+=a[i][j];
        ar[j]=sum;
    }
    lli cum[n+1],sum=0,left=-1,right=0;
    for(int i=0;i<n;i++){
        if(ar[i]<0)cum[i]=sum=sum+ar[i];
        else cum[i]=(i==0)?0:cum[i-1];
    }
    //for(int i=0;i<n;i++) cout<<cum[i]<<" ";
    //cout<<endl;
    lli i=1;
    bool lb;
    if(cum[0]<cum[n-1]) lb=true;
    else left++;
    while(cum[i]>cum[n-1]-cum[i-1]){
        if(lb){break;}
        i++;
        left++;
    }
    if(left==-1)left=n-1;
    lli in=0;
    for(int i=left;i>=0;i--)rar[in++]=ar[i];
    for(int i=n-1;i>left;i--)rar[in++]=ar[i];
    //for(int i=0;i<n;i++) cout<<rar[i]<<" ";
}
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
lli kadam(lli a[],int n,int &v,int &vv){
    lli x,y,xx,yy;
    arrange(a,n);
    lli kao=kadan(a,n,x,y),kat=kadan(rar,n,xx,yy);
    v=(kao>kat)?x:xx;
    vv=(kao>kat)?y:yy;
    return max(kao,kat);
}
int arr[102][102];
lli max2d(int co,int ro){
    lli tar[10000];
    lli left=0,right=0,ml=0,mr=0,mu=0,md=0,maxsum=-9999999;
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
    //cout<<"MaxSum : "<<maxsum<<"\n";
    return maxsum;
}
/*int main(){
    lli ara[111];
    lli x,y;
    lli n;
    while(cin>>n){
        for(int i=0;i<n;i++)cin>>ara[i];
        arrange(ara,n);
        cout<<kadan(ara,n,x,y)<<"  "<<kadan(rar,n,x,y)<<endl;
        cout<<endl;
    }
    return 0;
}
*/

























/*int main(){
    lli x,y;
    lli n;
    arrange(9);
    cout<<kadan(ar,9,x,y)<<endl;
    cout<<kadan(rar,9,x,y)<<endl;
    while(cin>>n){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>arr[i][j];
        cout<<max2d(n,n)<<endl;
    }
    return 0;
}
*/
