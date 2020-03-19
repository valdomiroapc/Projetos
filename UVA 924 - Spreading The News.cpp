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
	int e;
	cin>>e;
	vi g[e];
	for(int i=0;i<e;i++)
	{
		int n;
		cin>>n;
		int x;
		for(int j=0;j<n;j++)
		{
			cin>>x;
			g[i].pb(x);
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int ini;
		cin>>ini;
		int vis[e];
		vi day;
		memset(vis,0,sizeof(vis));
		queue<pair<int,int> > fila;
		day.pb(0);
		fila.push(mp(ini,0));
		while(!fila.empty())
		{
			int at=fila.front().first;
			int d=fila.front().second;
			fila.pop();
			if(vis[at])
				continue;
			vis[at]=1;
			if(d>=day.size())
			{
				while(d>=day.size())
					day.pb(0);
			}
			day[d]++;
			for(int i=0;i<g[at].size();i++)
			{
				int p=g[at][i];
				if(!vis[p])
					fila.push(mp(p,d+1));
			}
		}
		int m=0;
		int da=0;
		for(int i=1;i<day.size();i++)
		{
			if(day[i]>m)
			{
				m=day[i];
				da=i;
			}
		}
		if(da==0)
		{
			puts("0");
			continue;
		}
		cout<<m<<" "<<da<<endl;
	}
}