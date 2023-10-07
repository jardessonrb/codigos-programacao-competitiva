#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 101010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 0x7FFFFFFFFFFFFFFF
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
#define check_in_matriz(l, c, minl, maxc) (l >= 0 && l < minl) && (c < maxc && c >= 0) && (!visitados[l][c])
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
ll dp[105][1005];

struct Muro {
    int vertice;
    ll felicidade;
    int gasto;

    Muro(int v, ll f, int g) : vertice(v), felicidade(f), gasto(g) {}
};

int chegada;
vector<Muro> grafo[150];

ll dfs(int vertice, int borracha){

    if(borracha < 0) return -INF;

    if(vertice == chegada) return 0;

    if(dp[vertice][borracha] != -1) return dp[vertice][borracha];

    ll ans = -INF;

    for(Muro x : grafo[vertice]){
        ans = max(ans, dfs(x.vertice, borracha - x.gasto) + x.felicidade);
    }

    return dp[vertice][borracha] = ans;
}

int32_t main(int argc, char const *argv[]){
    optimize;
    int N, M, partida, borracha;

    cin >> N >> M;
    cin >> partida >> chegada;
    cin >> borracha;

    ll f;
    for (int i = 0, a, b, g; i < M; i++)
    {
        cin >> a >> b >> f >> g;

        Muro m1(b, f, g);
        Muro m2(a, f, g);
        grafo[a].push_back(m1);
        grafo[b].push_back(m2);
    }

    memset(dp, -1, sizeof dp);
    ll ans = dfs(partida, borracha);
    
    cout << (ans > 0 ? ans  : -1) << endl;

    return 0;
}