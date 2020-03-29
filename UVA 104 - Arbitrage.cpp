//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
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
void imprime(int d, int i, int j, int cam[21][21][21])
{
	if(d==1)
	{
		cout<<i;
		return;
	}
	imprime(d-1,i,cam[d][i][j],cam);
	cout<<" "<<cam[d][i][j];
}
int main()
{
	int n;
	while(cin>>n)
	{
		double tab[21][21][21];
		int cam[21][21][21];
		for(int i=0;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					tab[i][j][k]=0.0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					tab[1][i][j]=1.0;
				else
					cin>>tab[1][i][j];
				cam[1][i][j] = i;
			}
		}
		for(int d=2;d<=n;d++)
		{
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						if(tab[d-1][i][k]*tab[1][k][j] > tab[d][i][j])
						{
							tab[d][i][j] = tab[d-1][i][k]*tab[1][k][j];
							cam[d][i][j] = k;
						}
					}
				}
			}
		}
		bool fim = false;
		for(int d=1;d<=n && !fim;d++)
		{
			for(int i=1;i<=n && !fim;i++)
			{
				if(tab[d][i][i] > 1.01)
				{
					imprime(d,i,i,cam);
					cout<<" "<<i;
					puts("");
					fim = true;
				}
			}
		}
		if(!fim)
		{
			puts("no arbitrage sequence exists");
		}
	}
}