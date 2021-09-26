#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
	int C, N, chegada, duracao, ans = 0;
	
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(int i=0; i<C; i++)
	{
		pq.push(0);
	}
	
	for(int i=0; i<C; i++)
  {
  	cin>>chegada>>duracao;
  	
  	int proximo = pq.top();
  	pq.pop();
  	
  	if(proximo -chegada > 20)
  	{
  		ans++;
		}
		
		pq.push(duracao + max(chegada, proximo));

	}
	
	cout<<ans<<endl;
	return 0;
}

