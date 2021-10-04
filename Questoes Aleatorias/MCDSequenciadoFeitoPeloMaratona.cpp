#include <bits/stdc++.h>
#define ll long long

using namespace std;

//1º - MDC(a, b, c) --> MDC(MDC(a, b), c)
//2º MDC(a, 0) --> a
//3º MDC(a, b) ---> MDC(b, a % b)


int MDC(int a, int b)
{
	if(b == 0) return a;

	return MDC(b, a % b);
}


int main(int argc, char const *argv[])
{
	int N, x;

	cin >> N;

	int mdc = 0;

	for(int i = 1; i <= N; i++)
	{
		cin >> x;

		mdc = MDC(mdc, x);
	}

	cout << mdc << endl;


	return 0;
}
