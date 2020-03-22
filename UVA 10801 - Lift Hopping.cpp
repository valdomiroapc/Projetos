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
vi in()
{
	char c;
	vi ret;
	int x=0;
	bool colocado=false;
	while(1)
	{
		c=getchar();
		if(c=='\n')
		{
			if(colocado)
				ret.pb(x);
			break;
		}
		if(c==' ')
		{
			if(colocado)
				ret.pb(x);
			x=0;
			colocado=false;
			continue;
		}
		x*=10;
		x+=(c-'0');
		colocado=true;
	}
	return ret;
}
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		vi ti;
		int x;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			ti.pb(x);
		}
		vii g[101];
		getchar();
		for(int i=0;i<n;i++)
		{
			vi seq = in();
			for(int j=0;j<seq.size();j++)
			{
				for(int l=j+1;l<seq.size();l++)
				{
					g[seq[j]].pb(mp( abs(seq[j]-seq[l]) * ti[i], seq[l] ) );
					g[seq[l]].pb(mp( abs(seq[l]-seq[j]) * ti[i], seq[j] ) );
				}
			}
		}
		priority_queue<ii , vii , greater<ii> > fila;
		int dist[101];
		for(int i=0;i<=100;i++)
			dist[i]=99999999;
		dist[0]=0;
		fila.push(mp( 0,0));
		while(!fila.empty())
		{
			int d=fila.top().first;
			int at=fila.top().second;
			fila.pop();
			int troca=0;
			if(at!=0)
				troca=60;
			if(d>dist[at])
				continue;
			for(int i=0;i<g[at].size();i++)
			{
				int p=g[at][i].second;
				int di=g[at][i].first;
				if(d+di+troca >= dist[p])
					continue;
				dist[p]=d+di+troca;
				fila.push(mp(dist[p], p ));
			}
		}
		if(dist[k]==99999999)
			cout<<"IMPOSSIBLE"<<endl;
		else
			cout<<dist[k]<<endl;
	}

}