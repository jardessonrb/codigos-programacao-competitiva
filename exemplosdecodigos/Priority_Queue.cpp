#include <bits/stdc++.h>


using namespace std;

int main(int argc, char const *argv[]){
	
	priority_queue<int> pq;
	//priority_queue<int, vector<int>, greater<int>> pq;
	
	pq.push(3);
	pq.push(1);
	pq.push(4);
	pq.push(2);

	while(!pq.empty()){
		cout<<pq.top()<<endl;
		pq.pop();
	}
	
	return 0;
}

