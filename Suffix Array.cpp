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
vi construct_suffix_array(string str)
{
	str+='$'; // acrescenta um caractere que é menor que todos os caracteres (letras e números)
	int n = str.size();
	// p é o suffix array atual.
	// c é o vetor que nos permite acessar um valor correspondente a ordenação do sufixo atual.
	vector<int> p(n),c(n);

	{
		vector<pair<char,int> > a(n); // vetor auxiliar para ordenar os sufixos baseando-se no primeiro caractere.

		for(int i=0;i<n;i++)
			a[i] = {str[i],i}; // composto pelo primeiro caractere e pelo indice deste caractere na string original.
		sort(a.begin(),a.end()); // ordenar os sufixos baseado-se no primeiro caractere
		for(int i=0;i<n;i++)
			p[i] = a[i].second;// O suffix array é composto pelo indice dos sufixos ordenados.
		
		c[p[0]] = 0; // atribuímos a cada suffixo na ordem original um número que corresponderia à sua ordem se estivesse ordenado  
		for(int i=1;i<n;i++)
		{
			if(a[i].first == a[i-1].first) // suffixos iguais devem ter o mesmo valor de ordenação
				c[p[i]] = c[p[i-1]];
			else
				c[p[i]] = c[p[i-1]]+1;
		}
	}
	// a ordenação será feita considerando (2^k) caracteres dos suffixos.
	// o primeiro passo foi feito acima considerando apenas 1 caractere
	// nos próximos passos consideraremos o dobro de caracteres do passo anterior até ter certeza de que a ordenação está correta
	int k=0;
	while((1<<k) < n)
	{
		vector<pair<pair<int,int>,int> >a(n);
		for(int i=0;i<n;i++)
			a[i] = {{c[i],c[(i+(1<<k))%n]},i}; // podemos comparar string de tamanho 2^k considerando suas metades.
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++)
			p[i] = a[i].second;
		c[p[0]] = 0;
		for(int i=1;i<n;i++)
		{
			if(a[i].first  == a[i-1].first)
				c[p[i]] = c[p[i-1]];
			else
				c[p[i]] = c[p[i-1]]+1;
		}
		k++;
	}
	return p;
}
int main()
{
	string s;
	cin>>s;
	vi suffix_array = construct_suffix_array(s);
	for(int i=0;i<suffix_array.size();i++)
		cout<<suffix_array[i]<<" ";
	puts("");
}
