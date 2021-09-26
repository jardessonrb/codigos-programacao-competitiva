#include <bits/stdc++.h>


using namespace std;

int S, T, P, ans = 0, saloes[210], z = 0;
bool visitados[210];
vector<int> rotas[1000000];

void dfs(int u)
{
	if(visitados[u] == true) return;

	visitados[u] = true;

	for(auto it : rotas[u])
	{
		if(saloes[u] > saloes[it] && visitados[it] != true)
		{
			ans++;
			dfs(it);
		}
	}

}


int main(int argc, char const *argv[])
{
	cin>>S>>T>>P;

	int u, v;
	for (int i = 1; i <= S; ++i)
	{
		cin>>saloes[i];
		visitados[i] = false;
	}
	
	
	for (int i = 0; i < T; ++i)
	{
		cin>>u>>v;

		rotas[u].push_back(v);
		rotas[v].push_back(u);
	}

	dfs(P);

	cout<< ans <<endl; 
	return 0;
}