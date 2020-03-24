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
	while(cin>>n)
	{
		int v[n+1];
		int cicle[n+1];
		memset(cicle, 0, sizeof(cicle));
		for(int i=1;i<=n;i++)
			cin>>v[i];
		int m;
		cin>>m;
		vii g[n+1];
		int x,y;
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			g[x].pb(mp(y,(v[y]-v[x])*(v[y]-v[x])*(v[y]-v[x])));
		}
		int dist[n+1];
		for(int i=0;i<=n;i++)
			dist[i]=99999999;
		dist[1]=0;
		for(int i=0;i<n-1;i++)
		{
			bool fez=false;
			for(int j=1;j<=n;j++)
			{
				if(dist[j]==99999999)
					continue;
				for(int k=0;k<g[j].size();k++)
				{
					int p=g[j][k].first;
					int c=g[j][k].second;
					if(dist[j]+ c < dist[p])
					{
						fez=true;
						dist[p] = dist[j]+c;
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
				if(dist[j]==99999999)
					continue;
				for(int k=0;k<g[j].size();k++)
				{
					int p=g[j][k].first;
					int c=g[j][k].second;
					if(dist[j]+ c < dist[p])
					{
						cicle[j]=1;
						cicle[p]=1;
						fez=true;
						dist[p] = dist[j]+c;
					}
				}
			}
			if(!fez)
				break;
		}
		cout<<"Set #"<<t++<<endl;
		int q;
		cin>>q;
		for(int i=0;i<q;i++)
		{
			cin>>x;
			if(dist[x]< 3 || cicle[x] || dist[x] == 99999999)
				puts("?");
			else
				cout<<dist[x]<<endl;
		}
	}
}