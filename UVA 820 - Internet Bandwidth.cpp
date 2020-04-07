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
const int ox[8]={-1,-2,-2, -1,1,2,2,1};
const int oy[8]={-2,-1,1, 2,2,1,-1,-2};
const int inf = 999999999;
const int mod = 1e9+7;
int main()
{
	int n;
	int u=1;
	while(cin>>n && n)
	{
		int g[n+1][n+1];
		int p[n+1];
		int s,t,c;
		int mf=0;
		cin>>s>>t>>c;
		memset(g,0,sizeof(g));
		int x,y,b;
		for(int i=0;i<c;i++)
		{
			cin>>x>>y>>b;
			g[x][y]+=b;
			g[y][x]+=b;
		}
		while(1)
		{
			memset(p,-1,sizeof(p));
			queue<pair<int,int> >fila;
			fila.push(mp(s,inf));
			p[s] = s;
			int f;
			while(!fila.empty())
			{
				int at = fila.front().first;
				int atf = fila.front().second;
				fila.pop();
				if(at==t)
				{
					f=atf;
					break;
				}
				for(int i=1;i<=n;i++)
				{
					if(g[at][i] && p[i]==-1)
					{
						p[i] = at;
						fila.push(mp(i, min(atf, g[at][i]) ));
					}
				}
			}
			if(p[t]==-1)
				break;
			int at = t;
			while(at!=s)
			{	
				g[at][p[at]]+=f;
				g[p[at]][at]-=f;
				at = p[at];
			}
			mf+=f;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n",u++,mf);
	}
}