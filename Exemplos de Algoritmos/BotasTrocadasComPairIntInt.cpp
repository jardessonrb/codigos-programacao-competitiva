#include <bits/stdc++.h>
#define ll long long

/*
pair<tipo1, tipo2> var

pair<int, int> nomeVariavel;

var.first --> tipo1
var.second--> tipo2


vector<pair<string, string>> traduções

*/

using namespace std;

pair<int,int> tamanhos[61];

int main(int argc, char const *argv[]){
	int N, x, ans =0;

	char lado;

	cin>>N;

	for(int i = 0; i < N; i++){
		cin>>x>>lado;
		if(lado == 'E'){
		  tamanhos[x].first++;
		}else{
			tamanhos[x].second++;
		}
	}
	
	for(int i = 30; i < 60; i++){
		//com tres ou mais valores fica min({vl1, vl1, vlN})
		ans += min(tamanhos[i].first, tamanhos[i].second);
	}

	cout<<ans<<endl;

	
	return 0;
}

