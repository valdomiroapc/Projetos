//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <string>
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
const int ox[4]={1,0,-1,0};
const int oy[4]={0,1,0,-1};
const int inf = 999999999;
int main()
{
	int n;
	int u=1;
	while(cin>>n && n)
	{
		map<string,int> tab;
		map<int,string>invtab;
		int c=0;
		int ne;
		vector< vector<string> >g;
		string x,y;
		for(int i=0;i<n;i++)
		{
			cin>>ne;
			vector<string> l;
			for(int j=0;j<ne;j++)
			{
				cin>>x;
				l.pb(x);
				if(tab.find(x) == tab.end())
				{
					invtab[c]=x;
					tab[x]= c++;
				}
			}
			g.pb(l);
		}
		bool dist[c][c];
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<c;j++)
				dist[i][j]=0;
			dist[i][i] = 1;
		}

		for(int i=0;i<g.size();i++)
			for(int j=0;j<g[i].size()-1;j++)
				dist[tab[g[i][j]]][tab[g[i][j+1]]] = 1;
		
		int nm;
		cin>>nm;
		for(int i=0;i<nm;i++)
		{
			cin>>x>>y;
			dist[tab[x]][tab[y]] = 1;
		}
		for(int k=0;k<c;k++)
			for(int i=0;i<c;i++)
				for(int j=0;j<c;j++)
					dist[i][j] |= (dist[i][k] & dist[k][j]);

		int ans = 0;
		vector <pair<string,string> >v;
		for(int i=0;i<c;i++)
		{
			for(int j=i+1;j<c;j++)
			{
				if(!dist[i][j] && !dist[j][i])
				{
					if(v.size()<2)
						v.pb(mp(invtab[i] , invtab[j]));
					ans++;
				}
			}
		}
		printf("Case %d, ",u++);
		if(ans==0)
		{
			puts("no concurrent events.");
			continue;
		}
		printf("%d concurrent events:\n",ans);
		for(int i=0;i<v.size();i++)
		{
			cout<<"("<<v[i].first<<","<<v[i].second<<") ";
		}
		puts("");
	}
}