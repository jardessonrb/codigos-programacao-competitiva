#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 1000000

using namespace std;

int N, M, moedas[MAXN], dp[MAXN];
bool calculei[MAXN];

bool F(int falta)
{
    if(falta < 0) return false;
    if(calculei[falta]) return dp[falta];

    calculei[falta] = true;
    dp[falta] = false;

    if(falta == 0)
    {
        dp[falta] = true;
    } 
    else
    {
        for(int i = 0; i < N; i++)
            if(F(falta - moedas[i]))
                dp[falta] = true;
    }

    return dp[falta];
}

int main(int argc, char const * argv[]){

    cin>>N >>M;

    for (int i = 0; i < N; i++)
        cin>> moedas[i];

    int ans = 0;

    for (int i = 1; i < M; i++)
        if(F(i) == 0) 
            ans++;    

    cout<< ans <<endl;
    return 0;
}
