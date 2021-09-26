#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(int argc, char const *argv[]){
	ll N;
	
	cin>>N;
	
	vector<ll> divisores;
	
	int root =  sqrt(N);
	
	divisores.push_back(N);
	
	if(N != 1)
	  divisores.push_back(N);

	for(int i= 2; i<=N; i++)
	{
		if(N%i == 0){
			divisores.push_back(i);
			
			if(i != N/i){
				divisores.push_back(N / i);
			}
		}
		
	}
	
	sort(divisores.begin(), divisores.end());
	
	for(int i = 0; i<(int)divisores.size(); i++){
		cout <<divisores[i]<<" ";
	}
	
	cout<<endl;
	
	
	
//	For semelhante ao foreach();
//	for(ll ou auto it: divisores){
//		cout <<it<<" ";
//	}
//	cout<<endl;
	return 0;
}

