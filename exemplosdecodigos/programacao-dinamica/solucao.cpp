#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define MAXV 10000000

using namespace std;

int freq[MAXV], N, fib[MAXV];
bool calculei[MAXV];

int F(int N)
{

    if(calculei[N]) return fib[N];

    freq[N]++;

    calculei[N] = true;

    if(N < 2){
        fib[N] = 1;
    }else{
        fib[N] = F(N -1) + F(N -2);
    }

    return fib[N];
}

int main(int argc, char const * argv[]){

    cin>>N;

    fib[0] = fib[1] = 1;

    //por programacao dinamica por Bottom Up
    for (int i = 2; i <= N; i++)
        fib[i] = fib[i-1] + fib[i-2];
    
    cout<< fib[N] <<endl;

    //por programacao dinamica com funcao por Top Down
    //F(N);


    //Printa as sequencias de cada fibo.
    // for (int i = 0; i <= 10; i++)
    // {
    //     cout<<i<<" "<<freq[i]<<endl;
    // }
    
    return 0;
}