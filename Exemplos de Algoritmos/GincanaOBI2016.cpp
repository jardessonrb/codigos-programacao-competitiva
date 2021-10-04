#include <bits/stdc++.h>
#define ll long long
using namespace std;

int MDC(ll a, ll b)
{
	if(b == 0) return a;

	return MDC(b, a % b);
}


int main(int argc, char const *argv[]){
	ll N, M;
	
	cin>>N >> M;
	
	while(MDC(N,M) != 1) M--;
	
	cout<<M<<endl;
	return 0;
}

