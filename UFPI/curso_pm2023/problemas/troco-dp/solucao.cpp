#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 10101
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

vector<int> moedas;
int dp[MAXN];
int dp2[MAXN][MAXN];

int troco(int N, int moeda){
    int ans = INT16_MAX;

    if(N == 0) return 0;

    if(N < 0 || moeda == moedas.size()) return INF;

    if(dp2[N][moeda] != -1) return dp2[N][moeda];

    int pega = 1 + troco(N - moedas[moeda], moeda);
    int n_pega = troco(N, moeda + 1);

    return dp2[N][moeda] = min(pega, n_pega);
}
int troco(int N){
    int ans = INT16_MAX;

    if(N == 0) return 0;

    if(dp[N] != -1) return dp[N];

    for(auto moeda : moedas){

        if(moeda > N) continue;

        int valor_troco_que_falta = 1 + troco(N - moeda);

        ans = min(ans, valor_troco_que_falta);
    }

    return dp[N] = ans;
}

int main(int argc, char const *argv[]){
    optimize;

    int N, V;

    cin >> N;

    moedas.resize(N);
    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp2);

    for (int i = 0; i < N; i++)
    {
        cin >> moedas[i];
    }

    cin >> V;
    
    cout << troco(V, 0) << endl;

    return 0;
}