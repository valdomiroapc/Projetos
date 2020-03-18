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
double distance(ii a, ii b)
{
	return sqrt((double)((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second)));
}
int main()
{
	int t;
	int s,p;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a,b,c;
		vector<pair<int , pair<int,int> > > edge,mst;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			edge.pb(mp(c,mp(a,b)));
		}
		sort(edge.begin(),edge.end());
		unionfind u(n+1);
		int _1mst=0;
		vi idx;
		for(int i=0;i<edge.size();i++)
		{
			c=edge[i].first;
			a=edge[i].second.first;
			b=edge[i].second.second;
			if(u._find(a)!=u._find(b))
			{
				_1mst+=c;
				u._union(a,b);
				mst.pb(edge[i]);
				idx.pb(i);
			}
		}
		int _2mst=10000000;
		for(int i=0;i<mst.size();i++)
		{
			unionfind uf(n+1);
			int s=0;
			int e=0;
			for(int j=0;j<edge.size();j++)
			{
				if(edge[j]==mst[i])
					continue;
				c=edge[j].first;
				a=edge[j].second.first;
				b=edge[j].second.second;
				if(uf._find(a)!=uf._find(b))
				{
					uf._union(a,b);
					s+=c;
					e++;
				}
			}
			if(e!=mst.size())
				continue;
			_2mst=min(_2mst, s);
		}
		printf("%d %d\n",_1mst,_2mst);
	}	
}