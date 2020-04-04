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
const int ox[4]={1,0,-1,0};
const int oy[4]={0,1,0,-1};
const int inf = 999999999;
int cap[200][200];
int mf;
int pai[200]; 
int ini = (int)'*';
int fim = (int)'#';
int tot;
int leitura()
{
	memset(cap,0,sizeof(cap));
	string linha;
	bool teve = 0;
	tot = 0;
	while(1)
	{
		linha = "";
		getline(cin,linha);
		if(linha.size() == 0)
		{
			if(!teve)
				return 0;
			else
				return 1;
		}
		teve = 1;
		char l = linha[0];
		char num = linha[1];
		cap[ini][l] = num-'0';
		tot += (num-'0');
		int it = 2;
		while(it<linha.size())
		{
			char x = linha[it];
			if(x>='0' && x<='9')
			{
				cap[(int)l][(int)x] = inf;
			}
			it++;
		}
	}
}
int f(int at, int minf)
{
	if(at == ini)
	{
		return minf;
	}
	if(pai[at] ==  -1)
		return 0;
	int x = f(pai[at], min(minf,cap[pai[at]][at]));
	cap[pai[at]][at]-=x;
	cap[at][pai[at]]+=x;
	return x;
}
int main()
{
	while(leitura())
	{
		int ans[100];
		memset(ans,0,sizeof(ans));
		for(int i='0' ;i <= '9';i++)
		{
			cap[i][fim] = 1;
		}
		mf = 0;
		while(1)
		{
			memset(pai,-1,sizeof(pai));
			int vis[200];
			memset(vis, 0,sizeof(vis));
			queue<int > fila;
			fila.push(ini);
			vis[ini] = 1;
			while(!fila.empty())
			{
				int at = fila.front();
				fila.pop();
				if(at == fim)
					break;
				for(int i=0;i<200;i++)
				{
					if(cap[at][i] && !vis[i])
					{
						vis[i] = 1;
						pai[i] = at;
						fila.push(i);
					}
				}
			}
			int fl = f(fim , inf);
			if(fl==0)
				break;
			int it = fim;
			while(it != ini)
			{
				if(it>='0' && it<='9' && pai[it]>='A' && pai[it]<='Z')
				{
					ans[it] = pai[it];
				}
				it = pai[it];
			}
			mf+=fl;
		}
		if(mf < tot)
		{
			puts("!");
			continue;
		}
		for(int i='0';i<='9';i++)
		{
			if(ans[i])
				printf("%c",ans[i]);
			else
				printf("_");
		}
		puts("");

	}
}