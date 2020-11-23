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
#include <bitset> 
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
const int tam = 31622777;
const long long int big_lim = 2147483647;
void count_sort(vi &sa,vi &c)
{
	int n = sa.size();
	vi cnt(n);
	for(auto x:c)
		cnt[x]++;
	vi new_sa(n),pos(n);
	pos[0] = 0; 
	for(int i=1;i<n;i++)
		pos[i] = cnt[i-1] + pos[i-1];
	for(auto x:sa)
	{
		int i = c[x];
		new_sa[pos[i]] = x;
		pos[i]++;
	}
	sa = new_sa;
}
vi build_Suffix_array(string str)
{
	str += '$';
	int tam = str.size();
	vi sa(tam),c(tam);

	{
		vector<pair<char,int> > a(tam);
		for(int i=0;i<tam;i++)
			a[i] = {str[i],i};
		sort(a.begin(),a.end());
		for(int i=0;i<tam;i++)
			sa[i] = a[i].second;
		c[sa[0]] = 0;
		for(int i = 1;i<tam;i++)
		{
			if(a[i].first == a[i-1].first)
				c[sa[i]] = c[sa[i-1]];
			else
				c[sa[i]] = c[sa[i-1]]+1;
		}
	}
	int k = 0;
	while((1<<k) < tam)
	{
		for(int i=0;i<tam;i++)
			sa[i] = (sa[i] - (1<<k)+tam)%tam;
		count_sort(sa,c);
		vi new_c(tam);
		new_c[sa[0]] = 0;
		for(int i=1;i<tam;i++)
		{
			pair<int,int> ant = {c[sa[i-1]],c[(sa[i-1] + (1<<k))%tam]};
			pair<int,int> at = {c[sa[i]],c[(sa[i] + (1<<k))%tam]};
			if(ant == at)
				new_c[sa[i]] = new_c[sa[i-1]];
			else
				new_c[sa[i]] = new_c[sa[i-1]]+1;
		}
		c = new_c;
		k++;
	}
	return sa;
}
int main()
{
	string s;
	cin>>s;
	vi sa = build_Suffix_array(s);
	for(int i=0;i<sa.size();i++)
		printf("%d ",sa[i]);
	puts("");
}
