#include <bits/stdc++.h>

using namespace std;

int N, P, M, cp=0, cm=0;

int main(int argc, char const *argv[]){
	cin>>N;
	
	int tam[N];
	
	for(int i =0; i<N; i++){
		cin>>tam[i];
	}
	
	for(int j =0; j<N; j++){
		if(tam[j] == 1){
			cp++;
		}
		if(tam[j] == 2){
			cm++;
		}
	}
	
	cin>>P>>M;
	
	
	if(cp >= P && cm >= M)
	{
		cout<<"S"<<endl;
	}
	else
	{
		cout<<"N"<<endl;
	}


	return 0;
}

