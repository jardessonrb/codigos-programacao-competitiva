#include <bits/stdc++.h>

using namespace std;

int d = 1;

//int recursividade(int a, int b)
//{
//	a /= b;
//	cout<<a<<endl;
//	if(a <= 1) return a;
//
//	return recursividade(a, b);
//}

int fatoracao(int a, int b){
	int t = max(a, b), s = 0;
	for(int i=2; i<t; i++){
		if(a%i == 0) {
			a /= i;
			s = i;
			break;
		}
	}
	for(int i=2; i<t; i++){
		if(b%i == 0) {
			b /= i;
			if(s == i) {
				d *= i;
			}
			break;
		}
	}
	
	if(a > 1 && b > 1) return fatoracao(a, b);
	
	if(a <= 1 || b <= 1) return 0;
	
	
}

int main(int argc, char const *argv[]){
	
	int a, b;
	
	cin>>a >>b;
	
	int t = fatoracao(a, b);
	
	cout<<d<<endl;
	
	//recursividade(a, b);

	return 0;
}

