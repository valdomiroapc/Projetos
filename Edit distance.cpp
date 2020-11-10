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
#include <stack>
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define pb push_back
#define mp make_pair
#define fast_io cin.tie(0), cin.sync_with_stdio(false);
#define PI 3.14159265359
#define eps 1e-9
#define unvisited -1
typedef vector<int>vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef pair<int, string> istr;
typedef vector<istr> vistr;
typedef vector< vector<int> > vvi;
typedef vector< vector<ii> > vvii;
const int ox[8]={1,0,-1,0,1,-1,1,-1};
const int oy[8]={0,1,0,-1,1,-1,-1,1};
const int inf = 1000000001;
const int mod = 1e9+7;
const int tam = 1e5+5;
int solve(string a,string b)
{
	a = '$' + a;
	b = '$' + b;
	int ta = a.size();
	int tb = b.size();
	int dp[ta][tb];
	for(int i=0;i<ta;i++)
		dp[i][0] = i;
	for(int i=0;i<tb;i++)
		dp[0][i] = i;
	for(int i=1;i<ta;i++)
	{
		for(int j=1;j<tb;j++)
		{
			if(a[i] == b[j])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) +1;
		}
	}
	return dp[ta-1][tb-1];
}
int main()
{
	int t;
	cin>>t;
	getchar();
	int u=1;
	while(t--)
	{
		string a,b;
		getline(cin,a);
		getline(cin,b);
		printf("%d\n",solve(a,b));
	}

}
	
