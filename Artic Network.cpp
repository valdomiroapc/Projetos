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
		cin>>s>>p;
		vii points;
		int x,y;
		for(int i=0;i<p;i++)
		{
			cin>>x>>y;
			points.pb(mp(x,y));
		}
		vector<pair<double, pair<int,int > > > edges, ans;
		for(int i=0;i<points.size();i++)
		{
			for(int j=i+1;j<points.size();j++)
			{
				edges.pb(mp( distance(points[i],points[j]) , mp(i,j) ) );
			}
		}
		sort(edges.begin(),edges.end());
		unionfind k(p+1);
		for(int i=0;i<edges.size();i++)
		{
			double d=edges[i].first;
			int u=edges[i].second.first;
			int v=edges[i].second.second;
			if(k._find(u)!=k._find(v))
			{
				k._union(u,v);
				ans.pb(edges[i]);
			}
		}
		s--;
		int c=0;
		while(c<s)
		{
			ans.pop_back();
			c++;
		}
		printf("%.2lf\n",ans.back().first);
	}	
}