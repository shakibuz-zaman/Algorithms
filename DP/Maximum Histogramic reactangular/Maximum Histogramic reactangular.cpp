#include<bits/stdc++.h>
using namespace std;
//int hist[11]={0,2,1,2,3,1};
//int hist[]={0,3,2,4,6,4,4,6,1,6,6,6,6,3};
//int hist[11]={0,6,2,5,4,5,1,6};
int hist[44]={0,2,4,6,8,8};
int maxreac(int hist[],int n){
    int top,maxa=-1,i=1;
    stack<int> sv;
    int cura;
    while(i<=n){
        cout<<"i="<<i<<endl;
        if(sv.empty()||hist[i]>=hist[sv.top()]) sv.push(i++);
        else{
            int tp=sv.top();
            sv.pop();

            if(sv.empty()) cura=(i-1)*hist[tp];
            else cura=hist[tp]*(i-sv.top()-1);

            maxa=max(maxa,cura);
        }

    }
    while(!sv.empty()){
            int tp=sv.top();
            sv.pop();

            if(sv.empty()) cura=(i-1)*hist[tp];
            else cura=hist[tp]*(i-sv.top()-1);

            maxa=max(maxa,cura);
    }
    cout<<"maxa="<<maxa<<endl;
    return maxa;
}
int main(){
    maxreac(hist,5);
}
