//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>
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
bool vis[2001][2001], mat[2001][2001];
int main()
{
	int p,d;
	while(scanf("%d", &p) && p)
	{
		memset(vis, 0, sizeof(vis));
		queue<pair<int,pair<int,int> > > fila;
		int x,y;
		while(p--)
		{
			scanf("%d%d", &x,&y);
			fila.push(mp(0,mp(x,y)));
			vis[x][y]=1;
		}
		memset(mat, 0, sizeof(mat));
		scanf("%d", &p);
		while(p--)
		{
			scanf("%d%d", &x,&y);
			mat[x][y]=1;
		}
		while(!fila.empty())
		{
			d = fila.front().first;
			x = fila.front().second.first;
			y = fila.front().second.second;
			fila.pop();
			if(mat[x][y])
			{
				printf("%d\n",d);
				break;
			}
			for(int i=0;i<4;i++)
			{
				int px = x + ox[i];
				int py = y + oy[i];
				if(px < 0 || px >2000 || py< 0 || py>2000 || vis[px][py])
					continue;
				vis[px][py]=1;
				fila.push(mp(d+1,mp(px,py)));
			}
		}
	}
}