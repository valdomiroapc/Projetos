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
int n,m;
int h[101][101];
int topo[101][101];
void init_topo()
{
	memset(topo,0,sizeof(topo));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<4;k++)
			{
				int pi = i + ox[k];
				int pj = j + oy[k];
				if(pi < 0 || pi >= n || pj < 0 || pj >= m)
					continue;
				if(h[i][j] > h[pi][pj])
					topo[pi][pj]++;
			}
		}
	}
}
int toposort()
{
	queue<pair<int,int> > fila;
	int dp[n][m];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(topo[i][j] == 0)
			{
				fila.push(mp(i,j));
				dp[i][j] = -1;
				topo[i][j] = -1;
			}
		}
	}
	while(!fila.empty())
	{
		int sx = fila.front().first;
		int sy = fila.front().second;
		fila.pop();
		for(int i=0;i<4;i++)
		{
			int pi = sx + ox[i];
			int pj = sy + oy[i];
			if(pi < 0 || pi >= n || pj < 0 || pj >= m)
				continue;
			if(h[pi][pj]<h[sx][sy])
			{
				topo[pi][pj]--;
				if(topo[pi][pj] == 0)
				{
					fila.push(mp(pi,pj));
					topo[pi][pj] = -1;
				}
				dp[pi][pj] = min(dp[pi][pj] , dp[sx][sy]-1);
			}
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ans = min(ans , dp[i][j]);
		}
	}
	return -ans;
}
int main()
{
	int t;
	cin>>t;
	string name;
	while(t--)
	{
		cin>>name>>n>>m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>h[i][j];
			}
		}
		init_topo();
		cout<<name<<": "<<toposort()<<endl;
	}
}