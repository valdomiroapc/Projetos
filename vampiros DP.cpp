#include <bits/stdc++.h>
using namespace std;
int d;
double p;
double dp[21][1001];
double f(int v1,int v2,int g)
{
	if(v2==0)
		return 1;
	if(v1==0)
		return 0;
	if(g==1000)
		return 1;
	double &a=dp[v1][g];
	if(a!=-1)
		return a;
	return a=f(v1+min(d,v2),v2-min(v2,d),g+1)*p+f(v1-min(v1,d),v2+min(d,v1),g+1)*(1-p);
}
int main()
{
	int v1,v2,at;
	while(scanf("%d%d%d%d",&v1,&v2,&at,&d) and (v1 or v2 or at or d) )
	{
		for(int i=0;i<21;i++)
		{
			for(int j=0;j<=1000;j++)
				dp[i][j]=-1;
		}
		p=(double)at/6.0;
		double ans=f(v1,v2,0);
		printf("%.1lf\n",ans*100.0);
	}
}
