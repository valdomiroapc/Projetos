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
int numdir(string a)
{
	if(a=="south")
		return 0;
	if(a=="north")
		return 2;
	if(a=="west")
		return 3;
	return 1;
}
char dirnum(int x)
{
	if(x==0)
		return 'S';
	if(x==2)
		return 'N';
	if(x==3)
		return 'W';
	return 'E';
}
int tab[51][51];
int vis[51][51][4];
bool visited(int x,int y)
{
	if(tab[x][y]==1)
		return 1;
	if(tab[x+1][y]==1)
		return 1;
	if(tab[x][y+1]==1)
		return 1;
	if(tab[x+1][y+1]==1)
		return 1;
	return 0; 
}
int turn(int i, int j)
{
	if(i==j)
		return 0;
	if(i%2 == j%2)
		return 2;
	else
		return 1;
}
int main()
{
	int n,m;
	while(cin>>n>>m , (n || m))
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>tab[i][j];
			}
		}
		memset(vis,0,sizeof(vis));
		int bi,bj, ei,ej;
		cin>>bi>>bj>>ei>>ej;
		bj--;
		bi--;
		ej--;
		ei--;
		string dir;
		cin>>dir;
		//         S,E, N,W
		int di[4]={1,0,-1,0};
		int dj[4]={0,1,0,-1};
		if(visited(bi,bj))
		{
			puts("-1");
			continue;
		}
		queue<pair< pair<int,int>    , pair<int,int> > > fila;
		fila.push(mp( mp(0, numdir(dir)) , mp(bi,bj) ) );
		int ans=10000000;
		while(!fila.empty())
		{
			int d=fila.front().first.first;
			int direc=fila.front().first.second;
			int ai=fila.front().second.first;
			int aj=fila.front().second.second;
			/*
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(i==ai && j==aj)
					{
						cout<<dirnum(direc)<<" ";
					}
					else if(i==ei && j==ej)
						cout<<"F ";
					else
						cout<<tab[i][j]<<" ";
				}
				puts("");
			}
			cout<<d<<endl;
			puts("---");
			*/
			if(ai == ei && aj == ej)
				ans = min(ans,d);
			fila.pop();
			if(vis[ai][aj][direc])
				continue;
			vis[ai][aj][direc]=1;
			int lf=direc+1;
			int rg=direc-1;
			if(rg < 0)
				rg = 3;
			if(lf > 3)
				lf = 0;
			if(!vis[ai][aj][lf])
				fila.push( mp( mp(d+1, lf) , mp(ai,aj) ) );
			if(!vis[ai][aj][rg])
				fila.push( mp( mp(d+1, rg) , mp(ai,aj) ) );
			for(int i=1;i<=3;i++)
			{
				int pi = ai + i*di[direc];
				int pj = aj + i*dj[direc];
				if(pi < 0 || pi >=n-1 || pj<0 || pj>=m-1)
					continue;
				if(vis[pi][pj][direc]==1)
					continue;
				if(visited(pi,pj))
					break;
				fila.push( mp( mp( d+1, direc ) , mp(pi,pj) ) );
			}
		}
		if(ans==10000000)
			puts("-1");
		else
			cout<<ans<<endl;
	}
}