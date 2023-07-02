#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
	int N;
	int n1, n2, d1, d2;
	char opc, b1, b2;
	
	cin>>N;
	
	for(int i=0; i<N; i++)
	{
		cin>>n1 >>b1 >> d1 >> opc >> n2 >> b2 >> d2;
		
		cout<<((n1*d2 + n2*d1)/ d1*d2)<<endl;
		
	}

	return 0;
}



