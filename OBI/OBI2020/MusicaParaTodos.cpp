#include <bits/stdc++.h>

using namespace std;
int N,M,C, cont=0;

struct amigo{
	int ord;
	int pref;
	int dest;
};

int main(int argc, char const *argv[]){
	cin>>N>>M>>C;
	
	int mu[M];
	amigo amg[N];
	
	for(int i=0; i<M; i++){
		mu[i] = (i+1);
	}
	int A, B;
	
	for(int j=0; j<N; j++){
		cin>>A>>B;
		amg[j].ord  = (j+1);
		amg[j].pref = A;
		amg[j].dest = B;
	}
	int ps = N;
	bool res = false;
	
	while(ps--){
		int ts = 0;
		
		for(int j=0; j<N; j++){
			if(amg[j].dest == C){
				C = amg[j].pref;
				cont++;
			}
			else
			{
				ts++;
			}
	  }
	  
	  if(ts == N)
		{
			res = true;
			break;
		}
		
	}
	
	if(res){
		cout<<cont<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	
	
	

	return 0;
}

