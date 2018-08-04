#include<bits/stdc++.h>
#define mem(N,i) memset(N,i,sizeof(N))
using namespace std;

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int w[20][20];
int n;
int dp[(1<<15)+2];
int call(int mask)
{
    cout<<"Masks="<<mask<<endl;
	if(mask==(1<<n)-1) return 0;
	if(dp[mask]!=-1) return dp[mask];
	int mn=1<<28;
	for(int i=0;i<n;i++)
	{
		if(check(mask,i)==0)
		{
			int price=w[i][i];
			for(int j=0;j<n;j++)
			{
				if(i!=j && check(mask,j)!=0)
				{
					price+=w[i][j];
				}
			}
			int ret=price+call(Set(mask,i));
			mn=min(mn,ret);

		}
	}
	cout<<"Maske="<<mask<<endl;
	return dp[mask]=mn;
}
int main()
{
		mem(dp,-1);
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&w[i][j]);

			}
		}

		int ret=call(0);
		printf("%d\n",ret);


	return 0;
}
