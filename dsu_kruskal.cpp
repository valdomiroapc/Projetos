#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fast_io cin.tie(0), cin.sync_with_stdio(false);
struct UF
{
	vector<int> pai,r;
	UF(int n){
		pai.resize(n);
		r.resize(n);
		for(int i=0;i<n;i++){
			pai[i] = i;
		}
		for(int i=0;i<n;i++){
			r[i]=1;
		}
	}
	UF(){}
	int acha(int x){
		if(pai[x]==x)
			return x;
		return pai[x]=acha(pai[x]);
	}
	void unir(int x,int y){
		x = acha(x);
		y = acha(y);
		if(r[x] > r[y]){
			pai[y] = x;
			r[x] += r[y];
		}
		else{
			pai[x] = y;
			r[y]+=r[x];
		}
	}
	bool mesmo_conj(int x,int y){
		return acha(x)==acha(y);
	}
};

int main(){
	fast_io
	int n,m; 
	while(cin>>n>>m and (n or m)){
		vector<pair<int, pair<int,int> > > arestas;
		long long int val = 0;
		for(int i=0;i<m;i++){
			int a,b,p;cin>>a>>b>>p;
			arestas.pb({p,{a,b}});
			val+=(long long int)p;
		}
		sort(arestas.begin(),arestas.end());
		UF stru(n+1);
		long long int ans = 0;
		for(int i=0;i<arestas.size();i++){
			int peso = arestas[i].first;
			int a = arestas[i].second.first;
			int b = arestas[i].second.second;
			if(!stru.mesmo_conj(a,b)){
				stru.unir(a,b);
				ans += (long long int)peso;
			}
		}
		cout<<val-ans<<endl;
	}
}
