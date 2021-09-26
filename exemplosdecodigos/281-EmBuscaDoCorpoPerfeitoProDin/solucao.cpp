#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 2010
#define INF 10000000000000
#define ll long long

using namespace std;

int N, M, peso[MAXN], beneficio[MAXN];
int dp[MAXN][MAXN];

ll F(int falta, int i)
{
    if(falta < 0) return -INF;

    if(i == N) return 0;

    if(dp[falta][i] != -1) return dp[falta][i];

    else
    {
        return dp[falta][i] = max(beneficio[i] + F(falta - peso[i], i + 1), F(falta, i = 1));
    }
    
}

int main(int argc, char const * argv[]){

    memset(dp, -1, sizeof dp);
    cin>>M >>N;

    for (int i = 0; i < N; i++)
        cin>> peso[i] >> beneficio[i];

    cout<< F(M, 0) <<endl;

    return 0;
}