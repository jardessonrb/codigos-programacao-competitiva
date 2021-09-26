#include <bits/stdc++.h>

using namespace std;
string P, A;
bool flag = false;

int main(int argc, char const *argv[]){
	
	cin>>P;
	fflush(stdin);
	cin>>A;
	
	
	
	for(int i = 0; i<A.size(); i++){
		int t = P.size();
		for(int j=0; j<P.size(); j++){
			if(P[i] != A[j]){
				t--;
			}
		}
		
		if(t == 0){
			flag = true;
			break;
		}
		
	}
	
	if(flag){
		cout<<"N"<<endl;
	}
	else
	{
		cout<<"S"<<endl;
		
	}
	

	return 0;
}

