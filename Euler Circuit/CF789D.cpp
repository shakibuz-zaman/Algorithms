#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int cir=0,n,m,st,to,d[1000010]={0},sn[1000010],g=0,l[1000010];
long long ans;
int f(int a){
	return sn[a]==a?a:sn[a]=f(sn[a]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) sn[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&st,&to);
		l[st]=l[to]=1;
		if(st==to){
			cir++;
			continue;
		}
		sn[f(st)]=f(to);
		d[st]++,d[to]++;
	}
	for(int i=1;i<=n;i++){
		if(l[i]&&f(i)!=g)
		if(g==0) g=f(i);
		else{
			printf("0");
			return 0;
		}
	}
	//cout<<"cir"<<cir<<'\n';
	ans=1ll*cir*(m-cir)+1ll*cir*(cir-1)/2;
	for(int i=1;i<=n;i++) ans+=1ll*d[i]*(d[i]-1)/2;
	printf("%lld",ans);
	return 0;
}
