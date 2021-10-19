#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll MDC(ll a, ll b)
{
	if(b == 0) return a;

	return MDC(b, a % b);
}


ll mmc(ll a, ll b){
	return a/MDC(a, b) * b;
}

int main(int argc, char const *argv[]){
	ll a, b;
	
	cin>>a>>b;
	
	//ll res = mmc(a, b);
	//cout<<res<<endl;

	cout<<(a / __gcd(a,b) * b)<<endl;
	return 0;
}

