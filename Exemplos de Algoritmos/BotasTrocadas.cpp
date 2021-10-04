#include <bits/stdc++.h>
#define ll long long
int E[30], D[30];
using namespace std;

int main(int argc, char const *argv[]){
	int N, x, ans =0;
	
	char lado;
	
	cin>>N;
	
	for(int i = 0; i < N; i++){
		cin>>x>>lado;
		if(lado == 'E'){
		  E[x]++;
		}else{
			D[x]++;
		}
	}
	for(int i = 30; i < 60; i++){
		//com tres ou mais valores fica min({vl1, vl1, vlN})
		ans += min(E[i], D[i]);
	}
	
	cout<<ans<<endl;
	
	return 0;
}

