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
typedef vector< vector<int> > vvi;
typedef vector< vector<ii> > vvii;
const int ox[4]={1,0,-1,0};
const int oy[4]={0,1,0,-1};
const int inf = 999999999;
const int mod = 1e9+7;
int custo[27];
int topo[27];
vi g[27];
void le()
{
	string linha;
	while(1)
	{
		char v = getchar();
		if(v == EOF || v=='\n')
			break;
		v -='A';
		cin>>custo[v];
		char x;
		while(1)
		{
			x = getchar();
			if(x=='\n')
				break;
			if(x>='A' && x<='Z')
			{
				x-='A';
				g[x].pb(v);
				topo[v]++;
			}
		}
	}
}
int toposort()
{
	queue<int>fila;
	int dp[27];
	memset(dp,0,sizeof(dp));
	for(int i='A';i<='Z';i++)
	{
		if(topo[i-'A'] == 0)
		{
			dp[i-'A'] = -custo[i-'A'];
			fila.push(i-'A');
		}
	}
	while(!fila.empty())
	{
		int at = fila.front();
		fila.pop();
		for(int i=0;i<g[at].size();i++)
		{
			int p = g[at][i];
			topo[p]--;
			dp[p]=min(dp[p], dp[at] - custo[p]);
			if(topo[p]==0)
				fila.push(p);
		}
	}
	int ans = inf;
	for(int i='A';i<='Z';i++)
		ans = min(ans, dp[i-'A']);
	return -ans;
}
int main()
{
	int t;
	cin>>t;
	getchar();
	getchar();
	while(t--)
	{
		memset(custo,0,sizeof(custo));
		memset(topo,0,sizeof(topo));
		for(int i=0;i<=26;i++)
			g[i].clear();
		le();
		cout<<toposort()<<endl;
		if(t>0)
			puts("");
	}
}