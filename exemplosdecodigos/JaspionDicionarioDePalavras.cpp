#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char const *argv[]){
	int T, N,M;
	
	cin>>T;
	while(T--){
		scanf(" %d %d", &M, &N);

		map<string, string> traducoes;
		fflush(stdin);

		string chave, valor;

		for(int i = 0; i<M; i++)
		{
			getline(cin, chave);
			getline(cin, valor);

			traducoes[chave] = valor;
		}

		string linha;


		for(int j = 0; j<N; j++)
		{
			getline(cin, linha);

			linha+= ' ';

			string palavra = "";

			for(int i = 0; i<(int)linha.size(); i++)
			{
				char c = linha[i];
				if(c == ' ')
				{


					if(traducoes.find(palavra) == traducoes.end()){
						cout<<palavra<<" ";
					}else{
						cout <<traducoes[palavra]<< " ";
					}


					palavra = "";

				}else{
					palavra += c;

				}

			}

			cout<<endl;

		}

		cout<<endl;
		}
	
	
/*
map<chave, valor> mapa

mapa["chave"] = 10;


*/

	
	return 0;
}

