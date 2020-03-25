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
int main()
{
	int n;
	while(cin>>n && n)
	{
		int young[26][26], old[26][26];
		char a, c, x,y;
		int d;
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<26;j++)
			{
				young[i][j]=9999999;
				old[i][j]=9999999;
			}
			young[i][i]=0;
			old[i][i]=0;
		}
		for(int i=0;i<n;i++)
		{
			cin>>a>>c>>x>>y>>d;
			if(a=='Y')
			{
				if(c=='U')
				{
					young[x-'A'][y-'A']=min(young[x-'A'][y-'A'],d);
				}
				else
				{
					young[x-'A'][y-'A']=min(young[x-'A'][y-'A'],d);
					young[y-'A'][x-'A']=min(young[y-'A'][x-'A'],d);
				}
			}
			else
			{
				if(c=='U')
				{
					old[x-'A'][y-'A']=min(old[x-'A'][y-'A'],d);
				}
				else
				{
					old[x-'A'][y-'A']=min(old[x-'A'][y-'A'],d);
					old[y-'A'][x-'A']=min(old[y-'A'][x-'A'],d);
				}
			}
		}
		for(int k=0;k<26;k++)
			for(int i=0;i<26;i++)
				for(int j=0;j<26;j++)
					young[i][j]= min(young[i][j] , young[i][k] + young[k][j]);

		for(int k=0;k<26;k++)
			for(int i=0;i<26;i++)
				for(int j=0;j<26;j++)
					old[i][j]= min(old[i][j] , old[i][k] + old[k][j]);
		cin>>x>>y;
		int px=x-'A', py= y-'A';
		int ans = 9999999;
		for(int i=0;i<26;i++)
		{
			if(young[px][i] + old[py][i] < ans)
				ans = young[px][i] + old[py][i];
		}
		if(ans == 9999999)
		{
			puts("You will never meet.");
			continue;
		}
		cout<<ans;
		for(int i=0;i<26;i++)
		{
			if(young[px][i] + old[py][i] == ans)
				cout<<" "<<(char)(i+'A');
		}
		puts("");
	}
}