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
	int p,r;
	int u = 1;
	while(cin>>p>>r && (p || r))
	{
		int mat[p+1][p+1];
		map<string , int> tab;
		string x,y;
		int c=0;
		for(int i=0;i<p;i++)
		{
			for(int j=0;j<p;j++)
				mat[i][j] = inf;
			mat[i][i] = 0;
		}
		for(int i=0;i<r;i++)
		{
			cin>>x>>y;
			int xx;
			int yy;
			if(tab.find(x) == tab.end())
			{
				tab[x]= c++;
			}
			if(tab.find(y) == tab.end())
			{
				tab[y]= c++;
			}
			xx = tab[x];
			yy = tab[y];
			mat[xx][yy]=1;
			mat[yy][xx]=1;
		}
		for(int k=0;k<p;k++)
			for(int i=0;i<p;i++)
				for(int j=0;j<p;j++)
					mat[i][j] = min(mat[i][j] , mat[i][k] + mat[k][j]);
		int ans = 0;
		for(int i=0;i<p;i++)
		{
			for(int j=0;j<p;j++)
			{
				ans = max(ans, mat[i][j]);
			}
		}
		if(ans == inf)
			printf("Network %d: DISCONNECTED\n\n",u++);
		else
			printf("Network %d: %d\n\n",u++, ans);
	}
}