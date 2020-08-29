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
int string_to_int(string x)
{
	int ret = 0;
	for(int i=0;i<x.size();i++)
	{
		ret*=10;
		ret+=(x[i]-'0');
	}
	return ret;
}
vi kmp(string x)
{
	vi ret;
	int j=0;
	ret.pb(0);
	for(int i=1;i<x.size();i++)
	{
		while(j && x[j] != x[i])
			j = ret[j-1];
		if(x[j] == x[i])
			j++;
		ret.pb(j);
	}
	return ret;
}
struct palavra
{
	int sx,sy,fx,fy;
	palavra(int a,int b,int c,int d)
	{
		sx=a;
		sy=b;
		fx=c;
		fy=d;
	}
};
int visited[110][110][8];
void search(int x,int y, int d,int c, vector<string>&mat,string &st,vi &k,vector<palavra> &ans)
{
	if(ans.size())
		return;
	visited[x][y][d] = 1;
	while(c && mat[x][y] != st[c])
		c = k[c-1];
	if(mat[x][y] == st[c])
	{
	 	c++;
	}
	if(c == st.size())
	{
		int sx = x;
		int sy = y;
		int aux = st.size();
		while(--aux)
		{
			sx-=ox[d];
			sy-=oy[d];
		}
		if(sy != y || sx <= x)
			ans.push_back(palavra(sx+1,sy+1,x+1,y+1));
		c = k[c-1];
	}
	//----
	int px = x + ox[d];
	int py = y + oy[d];
	if(px >=0 && px < mat.size() && py >= 0 && py < mat.size() && !ans.size())
		search(px,py,d,c,mat,st,k,ans);
	//----
	for(int i=0;i<8;i++)
	{
		if(visited[x][y][i] || ans.size())
			continue;
		search(x,y,i,0,mat,st,k,ans);
	}
}

void solve(vector<string> &mat, vector<string> &words)
{
	for(int i=0;i<words.size();i++)
	{
		vi k = kmp(words[i]);
		vector<palavra> ans;
		memset(visited,0,sizeof(visited));
		search(0,0,0,0,mat,words[i], k, ans);
		if(ans.size())
			cout<<ans[0].sx<<","<<ans[0].sy<<" "<<ans[0].fx<<","<<ans[0].fy<<endl;
		else
			puts("Not found");
	}
}

int main ()
{
	vector<string> entrada;
	string x;
	while(cin>>x)
		entrada.pb(x);
	int pos = 0;
	while(entrada[pos][0] != '0')
	{
		int tam = string_to_int(entrada[pos++]);
		vector<string> mat;
		int c=tam;
		while(c--)
			mat.pb(entrada[pos++]);
		vector<string> words;
		while(entrada[pos][0]<'0' || entrada[pos][0]>'9')
			words.pb(entrada[pos++]);
		solve(mat,words);
	}
}
	