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
int kadane(int mat[],int n)
{
	int ma = - inf;
	for(int l=0;l<n;l++)
	{
		int s = mat[l];
		ma = max(ma,s);
		for(int r=(l+1)%n;r!=l;r=(r+1)%n)
		{
			s+=mat[r];
			if(s>ma)
				ma=s;
			if(s<0)
				s=0;
		}
	}
	return ma;
}
int main()
{
	in;out;
	long long int mat[76][76];
	int t;
	cin>>t;
	bool fl = 1;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>mat[i][j];
		int ma = -inf;
		int s[76];
		for(int l=0;l<n;l++)
		{
			for(int i=0;i<n;i++)
			{
				s[i]=mat[l][i];
			}
			ma = max(ma,kadane(s, n));
			for(int r=(l+1)%n;r!=l;r=(r+1)%n)
			{
				for(int i=0;i<n;i++)
				{
					s[i]+=mat[r][i];
				}
				ma = max(ma,kadane(s, n));
			}
		}
		cout<<ma<<endl;
	}
}