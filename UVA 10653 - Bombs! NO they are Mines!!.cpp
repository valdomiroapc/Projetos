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
	int n,m;
	while(cin>>n>>m && (n || m))
	{
		int tab[n+1][m+1];
		memset(tab,0,sizeof(tab));
		int r;
		cin>>r;
		int l,k;
		for(int i=0;i<r;i++)
		{
			cin>>l>>k;
			for(int j=0;j<k;j++)
			{
				int x;
				cin>>x;
				tab[l][x]=1;
			}
		}
		int sx,sy,fx,fy;
		cin>>sx>>sy>>fx>>fy;
		int vis[n+1][m+1];
		memset(vis,0,sizeof(vis));
		queue<pair<int, pair<int,int > > > fila;
		fila.push(mp(0,mp(sx,sy)));
		int px[4]={1,0,-1,0};
		int py[4]={0,1,0,-1};
		int ans=1000000;
		while(!fila.empty())
		{
			int d=fila.front().first;
			int x=fila.front().second.first;
			int y=fila.front().second.second;
			fila.pop();
			if(vis[x][y])
				continue;
			if(x==fx && y==fy)
				ans=min(ans,d);
			vis[x][y]=1;
			for(int i=0;i<4;i++)
			{
				int cx=x+px[i];
				int cy=y+py[i];
				if(cx<0 || cx>=n || cy<0 || cy>=m)
					continue;
				if(vis[cx][cy] || tab[cx][cy])
					continue;
				fila.push(mp(d+1,mp(cx,cy)));
			}
		}
		cout<<ans<<endl;
	}
}