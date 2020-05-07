#include<iostream>
#include<deque>
#include<queue>
#include<math.h>
#include<cmath>
#include<string>
#include<string.h>
#include<stdio.h>
#include<set>
#include<vector>
#include<iomanip>
#include<map>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<cstdlib>
#include<unordered_set>
#include<algorithm>
#include<chrono>
using namespace std;
#define in freopen("in","r",stdin);
#define out freopen("out", "w", stdout);
#define ll long long int
#define ull unsigned long long int
#define mp make_pair
#define pb push_back
typedef vector<long long int>vi;
typedef pair<int,int>ii;
typedef vector<ii> vii;
typedef pair<int , ii> iii;
typedef vector<iii> viii;
const int mod = 1000007;
const int inf = 2147483647;
int mx[8]={1,0,-1,0,1,-1,-1,1};
int my[8]={0,1,0,-1,1,-1,1,-1};
long long int kadane(long long int mat[],int c)
{
	long long ma=-2147483648;
	long long int s = 0;
	for(int i=0;i<c;i++)
	{
		s+=mat[i];
		if(ma<s)
			ma=s;
		if(s<0)
			s=0;
	}
	return ma;
}
long long int f1( long long int mat[][21],int b,int c)
{
	long long ma=-2147483648;
	long long int s[21];
	for(int l=0;l<b;l++)
	{
		memset(s,0,sizeof(s));
		for(int r=l;r<b;r++)
		{
			for(int i=0;i<c;i++)
			{
				s[i] += mat[r][i];
			}
			ma = max(ma,kadane(s,c));
		}
	}
	return ma;
}
int main()
{
	in;out;
	long long int mat[21][21][21];
	int t;
	cin>>t;
	bool fl = 1;
	while(t--)
	{
		if(!fl)
			puts("");
		fl=0;
		int a,b,c;
		cin>>a>>b>>c;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				for(int k=0;k<c;k++)
					cin>>mat[i][j][k];
		long long int s[21][21];
		long long ans=-2147483648;
		for(int l=0;l<a;l++)
		{
			memset(s,0,sizeof(s));
			for(int r=l;r<a;r++)
			{
				for(int i=0;i<b;i++)
				{
					for(int j=0;j<c;j++)
					{
						s[i][j]+=mat[r][i][j];
					}
				}
				ans = max(ans, f1(s,b,c) );
			}
		}
		cout<<ans<<endl;
	}
}
