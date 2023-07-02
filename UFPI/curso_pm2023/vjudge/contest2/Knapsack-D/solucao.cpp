#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 110
#define MAXW 1e5
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int N, C;
ll dp[MAXN][100000 + 10];
ll valores[MAXN];
ll pesos[MAXN];

ll solve(int peso, int capacidade){
    if(peso >= N) return  0;

    if(capacidade <= 0) return 0;

    if(dp[peso][capacidade] != -1) return dp[peso][capacidade];

    ll npega = solve(peso + 1, capacidade);
    ll pega = 0;

    if(pesos[peso] <= capacidade) {
        pega = valores[peso] + solve(peso + 1, capacidade - pesos[peso]);
    }

    dp[peso][capacidade] = max(pega, npega);

    return dp[peso][capacidade];
}

int main(int argc, char const *argv[]){
    optimize;

    cin >> N >> C;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < N; i++)
    {
        cin >> pesos[i] >> valores[i];
    }
    

    cout << solve(0, C) << endl;

    return 0;
}