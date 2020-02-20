#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > iii;
int pai[1001];
int ra[1001];
int acha(int x)
{
	if(x==pai[x])
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
	while(scanf("%d%d",&n,&m) , (n||m))
	{
		int u,v,w;
		iii aresta[m];
		iii a;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			a.first=w;
			a.second.first=u;
			a.second.second=v;
			aresta[i]=a;
		}
		for(int i=0;i<n;i++)
		{
			pai[i]=i;
			ra[i]=1;
		}
		sort(aresta,aresta+m);
		vector<int> ans;
		for(int i=0;i<m;i++)
		{
			u=aresta[i].second.first;
			v=aresta[i].second.second;
			w=aresta[i].first;
			if(acha(u)!=acha(v))
			{
				junta(u,v);
				continue;
			}
			ans.push_back(w);
		}
		if((int)ans.size()==0)
		{
			puts("forest");
			continue;
		}
		printf("%d",ans[0]);
		for(int i=1;i<(int)ans.size();i++)
		{
			printf(" %d",ans[i]);
		}
		puts("");
	}
}
