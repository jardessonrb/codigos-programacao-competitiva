#include <bits/stdc++.h>

using namespace std;

string minhasVogais = "aeiou";

bool isVogal(char v){
	for(int i =0; i < 5; i++){
		if(v == minhasVogais[i]){
			return true;
		}
	}
	
	return false;
}
int main(){
	
	string risada, risadaVogais = "";
	
	cin >> risada;
	
	for(int i =0; i < risada.length(); i++){
		if(isVogal(risada[i])){
			risadaVogais += risada[i];
		}
	}
	
	int n = risadaVogais.length();
	
	for(int t = 0; t < n; t++){
		if(risadaVogais[t] != risadaVogais[n - t -1]){
			cout <<"N"<< endl;
			return 0;
		}
	}
	
	cout<<"S"<<endl;


	return 0;
}

