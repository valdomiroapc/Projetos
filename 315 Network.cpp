#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define pb push_back
#define mp make_pair
typedef vector<int>vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
vi le()
{
	char c;
	vi ret;
	int x=0;
	while(1)
	{
		c=getchar();
		if(c=='\n')
		{
			if(x!=0)ret.pb(x);
			break;
		}
		if(c==' ')
		{
			if(x!=0)ret.pb(x);
			x=0;
			continue;
		}
		x*=10;
		x+=(c-'0');
	}

	return ret;
}
int dfs_num[101];
int dfs_low[101];
int anterior[101];
int articulacao[101];
int dfs_it;
int aux;
void dfs(int s,vi*g)
{
	dfs_num[s]=dfs_it;
	dfs_low[s]=dfs_it;
	dfs_it++;
	for(int i=0;i<g[s].size();i++)
	{
		int p=g[s][i];
		if(dfs_num[p] == -1)
		{
			anterior[p]=s;
			if(s==1)
				aux++;
			dfs(p,g);
			if((s!=1 && dfs_low[p]>=dfs_num[s]) || (s==1 && aux>1 && dfs_low[p]>=dfs_num[s]))
				articulacao[s]=1;;
			dfs_low[s]=min(dfs_low[s],dfs_low[p]);
		}
		else if(anterior[s]!=p)
			dfs_low[s]=min(dfs_low[s],dfs_num[p]);
	}
}
int main()
{
	int n;
	while(scanf("%d",&n) , n)
	{
		vi g[n+1];
		int p;
		while(scanf("%d",&p),p)
		{
			vi co=le();
			for(int i=0;i<co.size();i++)
			{
				g[p].pb(co[i]);
				g[co[i]].pb(p);
			}
		}
		memset(dfs_num,-1,sizeof(dfs_num));
		memset(dfs_low,-1,sizeof(dfs_low));
		memset(anterior,-1,sizeof(anterior));
		memset(articulacao,0,sizeof(articulacao));
		dfs_it=0;
		aux=0;
		dfs(1,g);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(articulacao[i])
				ans++;
		}
		cout<<ans<<endl;
	}
}