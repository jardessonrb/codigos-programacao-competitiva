#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char const *argv[]){
	
	vector<int> impar, pares;
	int num;
	for(int i = 0; i<10; i++){
		cin>>num;
		if(num % 2 ==0) {
			pares.push_back(num);
			
		}else{
			impar.push_back(num);
		}
	}
	
	for(int i = 0; i<(int)pares.size(); i++){
		cout<<pares[i]<<" ";
	}
	cout<<endl;
	for(int i = 0; i<(int)impar.size(); i++){
		cout<<impar[i]<<" ";
	}
	cout<<endl;

	return 0;
}

