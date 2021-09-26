#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
	
	vector<int> qds;
	int N, M, V, C, lim=0, atl=0;
	bool pause=true;
	
	cin>>N>>M;
	
	for(int i=0; i<N; i++)
	{
		 cin>>V;
		 qds.push_back(V);
	}
	while(pause)
	{
		int soma = 0, pos=0 ;
		bool pare=true;
		for(int i = atl; i<N; i++)
		{
			soma += qds[i];
			if(soma == M && i == lim){
				C++;
				lim = i+1;
			}
			
			if(i == N) pause = false;
			
			if(soma > M){
				atl = i+1;
				lim = atl + 1;
				break;
			}
			
		}
		
	}
	cout<<C<<endl;
	return 0;
}

