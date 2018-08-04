#include<bits/stdc++.h>
#define lli long long int
using namespace std;
long long int DD(int n){
    if(n==0||n==2)
        return 1;
    if(n==1)
        return 0;
    ///Use DP Table to save data
    return (n-1)*D(n-2)+(n-1)*D(n-1);
}
lli fact(int n){
    lli sum=1;
    for(int i=1;i<=n;i++)
        sum*=i;
    return sum;
}
lli comb(int n,int r){
    return (fact(n)/(fact(n-r)*fact(r)));
}
lli D(int n){
    lli sum=0;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            sum+=(comb(n,i)*fact(n-i));
            continue;
        }
        sum-=(comb(n,i)*fact(n-i));
    }
    //printf("Fact(%d)=%lld  Sum=%lld  Ans : %lld\n",n,fact(n),sum,fact(n)-sum);
    return fact(n)-sum;
}
int main(){
    int N,M;
    lli sum;
    while(cin>>N>>M){
        sum=0;
        //sum+=D(N);
        for(lli i=0;i<=M;i++){
            lli dd=D(N-i);

            sum+=(comb(N,i)*dd);
            //cout<<"D("<<N-i<<")="<<dd<<"  Sum="<<(comb(N,i)*dd)<<endl<<endl;
            //printf("D(%d-%d)=%lld\n\n",N,i,dd);
        }
        cout<<sum<<endl;
    }
    return 0;
}
