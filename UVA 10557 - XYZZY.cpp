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
typedef pair<int, string> istr;
typedef vector<istr> vistr;
class unionfind
{
	private:
		int *ancestor;
		int *rank;
	public:
		unionfind(int tam)
		{
			ancestor=new int[tam];
			rank=new int[tam];
			for(int i=0;i<tam;i++)
			{
				ancestor[i]=i;
				rank[i]=0;
			}
		}
		int _find(int x)
		{
			if(x==ancestor[x])
				return x;
			return ancestor[x]=_find(ancestor[x]);
		}
		void _union(int x,int y)
		{
			x=_find(x);
			y=_find(y);
			if(rank[x]>rank[y])
			{
				ancestor[y]=x;
				rank[x]++;
			}
			else
			{
				ancestor[x]=y;
				rank[y]++;
			}
		}
};
int main()
{
	int n;
	int t = 1;
	while(cin>>n && n!=-1)
	{
		int v[n+1];
		vi g[n+1];
		int c, q,x;
		int dist[n+1];
		for(int i=1;i<=n;i++)
		{
			dist[i]=-9999999;
			cin>>v[i];
			cin>>q;
			for(int j=0;j<q;j++)
			{
				cin>>x;
				g[i].pb(x);
			}
		}
		dist[1]=100;
		for(int i=0;i<n-1;i++)
		{
			bool fez=false;
			for(int j=1;j<=n;j++)
			{
				if(dist[j]==-9999999)
					continue;
				for(int k=0;k<g[j].size();k++)
				{
					int p=g[j][k];
					if(v[j]+dist[j] > dist[p] && v[j]+dist[j]>0)
					{
						dist[p]= dist[j]+v[j];
						fez=true;
					}
				}
			}
			if(!fez)
				break;
		}
		for(int i=0;i<n-1;i++)
		{
			bool fez=false;
			for(int j=1;j<=n;j++)
			{
				if(dist[j]==-9999999)
					continue;
				for(int k=0;k<g[j].size();k++)
				{
					int p=g[j][k];
					if(v[j]+dist[j] > dist[p] && v[j]+dist[j]>0)
					{
						dist[p]= 9999999;
						fez=true;
					}
				}
			}
			if(!fez)
				break;
		}
		if(dist[n]>0)
			cout<<"winnable"<<endl;
		else
			cout<<"hopeless"<<endl;
	}
}