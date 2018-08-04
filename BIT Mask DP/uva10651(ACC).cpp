#include<bits/stdc++.h>
using namespace std;
int n=12;
int Set(int N,int pos){return N=N |(1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool chkb(int N,int pos){ return (bool)(N&(1<<pos));}
int dp[16900];
int call(int mask){
    bool bk=true;
    int co=0;
    if(dp[mask]!=-1){
        return dp[mask];
    }
    for(int i=0;i<n-2;i++){
        if(chkb(mask,i))co++;
        if(chkb(mask,i)==1&&chkb(mask,i+1)==1&&chkb(mask,i+2)==0){
                bk=false;}
        else if(chkb(mask,i)==0&&chkb(mask,i+1)==1&&chkb(mask,i+2)==1){
            bk=false;
        }

    }
    if(chkb(mask,n-2))co++;
    if(chkb(mask,n-1))co++;
    if(bk){
        return co;
    }
    int mn=1<<28,dmask=mask;
    for(int i=0;i<n-1;i++){
        int x,xx;
        if(chkb(mask,i)&&chkb(mask,i+1)){
            if(i-1>=0&& !chkb(mask,i-1)){
                int tmask=mask;
                tmask=reset(tmask,i);tmask=reset(tmask,i+1);
                x=call(Set(tmask,i-1));
                mn=min(mn,x);
            }
            if(i+2<n&& chkb(mask,i+2)==0){
                int tmas=mask;
                tmas=reset(tmas,i);tmas=reset(tmas,i+1);
                xx=call(Set(tmas,i+2));
                mn=min(mn,xx);
            }
        }
    }
    dp[mask]=mn;
    return dp[mask];
}

int main(){
    memset(dp,-1,sizeof(dp));
    char ch;
    int mask;
    int t;cin>>t;
    while(t--){
        mask=0;
        for(int i=0;i<12;i++){
            cin>>ch;
            if(ch=='o'){mask=Set(mask,i);
            }
        }
        cout<<call(mask)<<endl;
    }
    return 0;
}
