#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define pb push_back
#define mp make_pair
typedef vector<ll>vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
void dfs(int s, int *v, vi*g,int *dp,int ant)// dp on trees
{
	for(int i=0;i<g[s].size();i++)
	{
		int p=g[s][i];
		if(p!=ant)
		{
			dfs(p,v,g,dp,s);
			dp[s]+=max(0,dp[p]);
		}
	}
}
void dfs1(int s,int *dp,vi*g,int *ans,int ant)// rerooting
{
	ans[s]=dp[s];
	for(int i=0;i<g[s].size();i++)
	{
		int p=g[s][i];
		if(p!=ant)
		{
			int ss=dp[s];
			int sp=dp[p];
			dp[s]-=max(0,dp[p]);
			dp[p]+=max(0,dp[s]);
			dfs1(p,dp,g,ans,s);
			dp[s]=ss;
			dp[p]=sp;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int v[n+1];
	int dp[n+1];
	int ans[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		if(v[i])
			dp[i]=1;
		else
			dp[i]=-1;
	}
	memset(ans,0,sizeof(ans));
	vi g[n+1];
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,v,g,dp,-1);
	dfs1(1,dp,g,ans,-1);
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	puts("");
}