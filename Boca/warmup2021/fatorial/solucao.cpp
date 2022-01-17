#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 100010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int N, fib[100009];

int main(int argc, char const * argv[]){
    optimize;

    cin>>N;

    int soma = 0, cont = 0, fat;

    int max = sqrt(N) + 1;

 
    fib[0] = fib[1] = 1;

    for (int i = 2; i <= max; i++)
        fib[i] = i * fib[i-1];


    while(soma != N)
    {
        if(soma + fib[max] <= N)
        {
            soma += fib[max];
            cont++;

            if(soma == N) break;
        }
        else{

            max = max - 1;
        }

       
    }
    
    
    cout<< cont <<endl;

    return 0;
}