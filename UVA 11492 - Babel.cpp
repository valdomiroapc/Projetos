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
	while(cin>>n , n)
	{
		map<string, vector< pair<int,string> > > tab;
		map<string,int>dist;
		string ini,fim;
		cin>>ini>>fim;
		dist[ini]=0;
		dist[fim]=0;
		string x,y,c;
		vector<pair<string,pair<string,string> > > seq;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y>>c;
			dist[c]=9999999;
			seq.pb(mp( c, mp(x,y) ));
		}
		for(int i=0;i<seq.size();i++)
		{
			if(seq[i].second.second == ini || seq[i].second.first == ini)
				tab["_start"].pb(mp(seq[i].first.size(),seq[i].first));
			if(seq[i].second.second == fim || seq[i].second.first == fim)
				tab[seq[i].first].pb(mp(0,"_end"));
			for(int j=i+1;j<seq.size();j++)
			{
				if(seq[i].first[0] != seq[j].first[0])
				{
					if(seq[i].second.second == seq[j].second.second || seq[i].second.second == seq[j].second.first || seq[i].second.first == seq[j].second.first || seq[i].second.first == seq[j].second.second)
					{	
						tab[seq[i].first].pb(mp((int)seq[j].first.size() , seq[j].first));
						tab[seq[j].first].pb(mp((int)seq[i].first.size() , seq[i].first));
					}
				}
			}
		}
		dist["_end"]= 99999999;
		dist["_start"]=0;
		priority_queue<istr, vistr, greater<istr> > fila;
		fila.push(mp(0,"_start"));
		while(!fila.empty())
		{
			string at = fila.top().second;
			int d=fila.top().first;
			fila.pop();
			if(d>dist[at])
				continue;
			int tam=tab[at].size();
			for(int i=0;i<tam;i++)
			{
				string p= tab[at][i].second;
				int ar = tab[at][i].first;
				if(d+ar>=dist[p])
					continue;
				dist[p]=d+ar;
				fila.push(mp(d+ar, p));
			}
		}
		if(dist["_end"]==99999999)
			puts("impossivel");
		else
			cout<<dist["_end"]<<endl;
	}

}