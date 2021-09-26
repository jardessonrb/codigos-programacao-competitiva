#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair<int, int> botas[61];

int main(int argc, char const *argv[]){
	int qnt, tan, cont=0;
	char lado;
	
	cin>>qnt;
	
	for(int i = 0; i<qnt; i++)
	{
		cin>>tan>>lado;
		
		if(lado == 'D'){
			botas[tan].first++;
		}else{
			botas[tan].second++;
		}
 	}
 	
	for(int j = 30; j<60; j++){
		cont += min(botas[j].first, botas[j].second);
	}
	
	cout<<cont<<endl;

	return 0;
}

