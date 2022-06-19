#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define MAXV 10000000

using namespace std;

int freq[MAXV], N, fib[MAXV] = {1, 1};
bool calculei[MAXV];

int F(int N)
{
    if(N < 2){
        fib[N] = 1;

        return fib[N];
    }

    if(calculei[N]) return fib[N];

    fib[N] = F(N - 1) + F(N - 2);
    
    freq[N]++;
    calculei[N] = true;

    return fib[N];
}

int main(int argc, char const * argv[]){

    cin>>N;

    // fib[0] = fib[1] = 1;

    // //por programacao dinamica por Bottom Up
    // for (int i = 2; i <= N; i++)
    //     fib[i] = fib[i-1] + fib[i-2];
    
    // cout<< fib[N] <<endl;

    //por programacao dinamica com funcao por Top Down
    //F(N);

    // cout << "Fibonacci de " << N << " eh: " << fib[N - 1] << endl;
    cout << "Fibonacci de " << N << " eh: " << F(N - 1)  << endl;

    //Printa as sequencias de cada fibo.
    for (int i = 0; i <= N; i++)
    {
        cout<<i<<" "<<freq[i]<<endl;
    }
    
    return 0;
}