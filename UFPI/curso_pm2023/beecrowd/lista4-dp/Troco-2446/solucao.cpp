#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 1010
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

int V, M;
vector<int> moedas;
bool usadas[MAXN][MAXV];
bool dp[MAXN][MAXV];

bool resolve(int troco, int moeda){
    if(troco == 0) true;

    if(troco < 0) false;

    if(moeda >= M) return false;

    if(usadas[troco][moeda]) return dp[troco][moeda];

    usadas[troco][moeda] = true;

    if(resolve(troco - moedas[moeda], moeda + 1))
        return dp[troco][moeda] = true;

    if(resolve(troco, moeda + 1))
        return dp[troco][moeda] = true;

    return dp[troco][moeda] = false;
}

int main(int argc, char const *argv[]){
    optimize;

    cin >> V >> M;

    moedas.resize(M);
    memset(dp, -1, sizeof dp);

    for (int i = 0; i < M; i++)
    {
        cin >> moedas[i];
    }

    cout << (resolve(V, 0) ? "S" : "N") << endl;
    

    return 0;
}