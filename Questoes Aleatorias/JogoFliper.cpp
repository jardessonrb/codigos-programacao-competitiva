#include <bits/stdc++.h>

using namespace std;


int main(){
	int P, R;
	
	scanf("%d%d",&P,&R);
	if(P != 0 && P != 1 or R != 0 && R != 1){
		return 0;
	}
	
	if(P == 1 && R == 1){
		cout<<"A"<<endl;
		return 0;
	}
	
	if(P == 0){
		cout<<"C"<<endl;
		return 0;
	}
	
	if(P == 1 && R == 0){
		cout<<"B"<<endl;
		return 0;
	}

	return 0;
}

