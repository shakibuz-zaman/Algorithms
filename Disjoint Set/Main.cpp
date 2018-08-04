#include<bits/stdc++.h>
using namespace std;
int par[1111];
int findr(int s){
    if(par[s]==s)
        return s;
    return par[s]=findr(s);
}

int mkfr(int s,int ss){
    int x=findr(s),y=findr(ss);
    if(x==y)
        return 0; ///already friend
    par[x]=y;
}

int main(){

}
