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
string a,b;
int solve()
{
	if(a == "" || b == "")
		return 0;
	int ta = a.size();
	int tb = b.size();
	int dp[ta][tb];
	dp[0][0] = (a[0] == b[0]);
	int aux = dp[0][0];
	for(int i=1;i<ta;i++)
	{
		if(a[i] == b[0])
			aux = 1;
		dp[i][0] = aux;
	}
	aux = dp[0][0];
	for(int i=1;i<tb;i++)
	{
		if(a[0] == b[i])
			aux = 1;
		dp[0][i] = aux;
	}
	for(int i = 1;i<ta;i++)
	{
		for(int j=1;j<tb;j++)
		{
			if(a[i] == b[j])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[ta-1][tb-1];
}
int main()
{
	while(getline(cin,a))
	{

		getline(cin,b);
		cout<<solve()<<endl;
		a = "";
		b = "";
	}

}
	
