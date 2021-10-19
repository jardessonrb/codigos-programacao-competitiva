#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
	int x, n;
	map<int, int> prs;
	
	//set<int> prs; //Usa somente chave e não valor
	cin>>x;
	for(int i = 0; i<x; i++){
		cin>>n;
		prs[n] = n;
		//prs.insert(n);
	}
	
	cout<<((int)prs.size())<<endl;
	return 0;
}

