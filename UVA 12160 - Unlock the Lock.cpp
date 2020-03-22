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
	int l,u,r;
	int t=1;
	while(cin>>l>>u>>r && (l || u || r) )
	{
		vi rv;
		int x;
		for(int i=0;i<r;i++)
		{
			cin>>x;
			rv.pb(x);
		}
		queue<pair<int,int > > fila;
		int vis[10000];
		memset(vis,0,sizeof(vis));
		fila.push(mp(l,0));
		int ans =-1;
		while(!fila.empty())
		{
			int at=fila.front().first;
			int d=fila.front().second;
			fila.pop();
			if(vis[at])
				continue;
			if(at==u)
			{
				ans=d;
				break;
			}
			vis[at]=1;
			for(int i=0;i<r;i++)
			{
				int p=(at+rv[i])%10000;
				if(vis[p])
					continue;
				fila.push(mp(p,d+1));
			}
		}
		printf("Case %d: ",t++);
		if(ans==-1)
			puts("Permanently Locked");
		else
			printf("%d\n",ans);
	}
}