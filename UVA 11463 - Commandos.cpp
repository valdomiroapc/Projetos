//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
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
int main()
{
	int t;
	cin>>t;
	int u=1;
	while(t--)
	{
		int n,r;
		cin>>n>>r;
		int dist[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				dist[i][j]=9999999;
			dist[i][i]=0;
		}
		for(int i=0;i<r;i++)
		{
			int x,y;
			cin>>x>>y;
			dist[x][y] = min(dist[x][y],1);
			dist[y][x] = min(dist[y][x],1);
		}
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		int s,d;
		cin>>s>>d;
		int ans = 0;
		for(int i=0;i<n;i++)
		{
			ans = max(ans, dist[s][i] + dist[i][d]);
		}
		printf("Case %d: %d\n",u++,ans);
	}
}