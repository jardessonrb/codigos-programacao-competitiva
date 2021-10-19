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
	ll a,b,c,d;
	
	cin>>a>>b>>c>>d;
	
	ll f = mmc(b, d);
	
	ll e = (a*(f/b)) + (c*(f/d));
	
	ll mdc = MDC(e, f);
	
	cout<<(e/mdc)<<""<<(f/mdc)<<endl;
	
	
	return 0;
}

