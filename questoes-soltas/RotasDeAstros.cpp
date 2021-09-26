#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(int argc, char const *argv[]){
	ll a, b;
	
	cin>>a>>b;
	
	cout<<(a / __gcd(a,b)*b)<<endl;
	return 0;
}

