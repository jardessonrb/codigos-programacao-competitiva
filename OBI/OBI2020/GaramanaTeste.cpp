#include <bits/stdc++.h>

using namespace std;
string P, A, F = "";
bool flag = false;

int main(int argc, char const *argv[]){

	cin>>P;
	fflush(stdin);
	cin>>A;
	
	for(int t=0; t<A.size(); t++){
		if(A[t] != '*'){
			F += A[t];
		}
	}

	for(int i = 0; i<A.size(); i++){
		int t = F.size();
		for(int j=0; j<F.size(); j++){
			if(P[i] != F[j]){
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

