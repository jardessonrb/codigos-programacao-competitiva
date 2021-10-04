#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int numeroPrimo,resto;

  scanf("%d", &numeroPrimo);
	
	if(numeroPrimo <= 1){
		cout<<"N"<<endl;
		return 0;
	}
	int root = sqrt(numeroPrimo);
	
	for(int i = 2; i < root; i++){
		resto = numeroPrimo % i;
		if(resto == 0){
			cout <<"N"<<endl;
			return 0;
		}
	}
	
	cout<<"S"<<endl;
	

	return 0;
}

