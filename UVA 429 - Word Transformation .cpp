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
int dif(string a, string b)
{
	if(a.size()!= b.size())
		return -1;
	int ans=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=b[i])
			ans++;
	}
	return ans;
}
int main()
{
	int t;
	int s,p;
	cin>>t;
	bool line = false;
	while(t--)
	{
		if(line)
			puts("");
		line = true;
		string a;
		map<string , vector<string > > g;
		vector<string> vet;
		while(cin>>a)
		{
			if(a=="*")
				break;
			vet.pb(a);
			a="";
		}
		for(int i=0;i<vet.size();i++)
		{
			for(int j=i+1;j<vet.size();j++)
			{
				if(dif(vet[i], vet[j])==1)
				{
					g[vet[i]].pb(vet[j]);
					g[vet[j]].pb(vet[i]);
				}
			}
		}
		getchar();
		string linha;
		while(getline(cin,linha))
		{
			if(linha.size()==0)
				break;
			string ini="",fim="";
			int i;
			for(i=0;linha[i]!=' ';i++)
			{
				ini+=linha[i];
			}
			for(i++;i<linha.size();i++)
			{
				fim+=linha[i];
			}
			queue<pair<string ,int> > fila;
			fila.push(mp(ini,0));
			set<string> vis;
			int ans=100000;
			while(!fila.empty())
			{
				string at=fila.front().first;
				int d=fila.front().second;
				fila.pop();
				if(at==fim)
				{
					ans=min(ans,d);
					continue;
				}
				vis.insert(at);
				int tam=g[at].size();
				for(int i=0;i<tam;i++)
				{
					string p=g[at][i];
					if(vis.find(p)==vis.end())
					{
						fila.push(mp(p, d+1));
					}
				}
			}
			cout<<ini<<" "<<fim<<" "<<ans<<endl;
		}
	}	
}