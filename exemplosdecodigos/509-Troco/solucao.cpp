#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 100010
#define MAXV 1010

using namespace std;

int N, M, moedas[MAXN];
bool dp[MAXN][MAXV], calculei[MAXN][MAXV];

bool F(int falta, int i)
{
    if(falta < 0) return false;
    if(falta == 0) return true;
    if(i == N) return false;

    if(calculei[falta][i]) return dp[falta][i];

    calculei[falta][i] = true;

    bool op1 = F(falta - moedas[i], i+1);

    bool op2 = F(falta, i+1);

    return dp[falta][i] = max(op1, op2);

}

int main(int argc, char const * argv[]){

    cin>>M >>N;

    for (int i = 0; i < N; i++)
        cin>> moedas[i];

    if(F(M, 0))
        cout<< "S" <<endl;
    else
        cout<< "N" <<endl;

    return 0;
}
