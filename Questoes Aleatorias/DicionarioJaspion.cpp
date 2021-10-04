#include <bits/stdc++.h>
#define ll long long

using namespace std;


string traduzir(map<string, string> dicionario, string chave){
	return (!dicionario[chave].empty()) ? dicionario[chave] : chave;
}

string mapear(map<string, string> dicionario,string frase, int p){
	string traducao = "", palavra = "";
	frase += " ";
	int cont = 0;
	
	while(cont < (int)frase.size()){
		if(frase[cont] == ' '){
			if(p == 0){
				traducao += traduzir(dicionario, palavra);
				p++;
			}else{
				traducao = traducao+" "+traduzir(dicionario, palavra);
			}
			
			cont++;
			palavra = "";
		}else{
			palavra += frase[cont];
			cont++;
		}
	}

	return traducao;
}


int main(int argc, char const *argv[]){
	int T, M, N;
	string frase, palavra;
	
	cin>>T;
	fflush(stdin);
	
	while(T--){
		scanf(" %d %d ", &M, &N);
		fflush(stdin);
		
		map<string, string> traducoes;
		vector<string> frases;

		string chave, valor;

		
		for(int i=0; i<M; i++)
		{
			getline(cin, chave);
			fflush(stdin);
			getline(cin, valor);
			fflush(stdin);
			
			traducoes[chave] = valor;
			
		}
		
		
		for(int k=0; k<N;k++)
		{
			getline(cin, frase);
			frases.push_back(frase);
   	}
		
		for(int z=0; z<N;z++)
		{
			string traducao = mapear(traducoes, frases[z], 0);
			cout<<traducao<<endl;
		}
		cout<<"\n"<<endl;

	}

	return 0;
}

