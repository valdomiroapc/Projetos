#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> iii;
int pai[200001];
int ra[200001];
int acha(int x)
{
	if(pai[x]==x)
		return x;
	return pai[x]=acha(pai[x]);
}
void junta(int x,int y)
{
	x=acha(x);
	y=acha(y);
	if(ra[x]>=ra[y])
	{
		pai[y]=x;
		ra[x]++;
	}
	else
	{
		pai[x]=y;
		ra[y]++;
	}
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m), (n || m))
	{
		iii arestas[m];
		int x,y,c;
		iii a;
		long long int tot=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&c);
			a.first=c;
			a.second.first=x;
			a.second.second=y;
			arestas[i]=a;
			tot+=c;
		}
		for(int i=0;i<n;i++)
		{
			pai[i]=i;
			ra[i]=1;
		}
		sort(arestas,arestas+m);
		long long int mc=0;
		for(int i=0;i<m;i++)
		{
			a=arestas[i];
			if(acha(a.second.first)!=acha(a.second.second))
			{
				mc+=a.first;
				junta(a.second.first,a.second.second);
			}
		}
		printf("%lld\n",tot-mc);
	}
}
