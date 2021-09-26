#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 200020
#define MAXL 23
#define endl '\n'

using namespace std;

const ld PI = acos(-1.0);
const int BLOCK = 333;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int dp[MAXN][MAXL], nivel[MAXN];

//dp[u][i] --> o cara de distancia 2^i de u, no caminho de u até a raiz 

vii grafo[MAXN];
int N;

ll distancia[MAXN];

//O(log(N))
int LCA(int u, int v)
{
    if(nivel[u] < nivel[v]) swap(u, v);

    for(int i = MAXL - 1; i >= 0; i--)
    {
        if(dp[u][i] != -1 && nivel[dp[u][i]] >= nivel[v])
        {
            //FAZ UM PULO DE TAMANHO 2^i DE U
            u = dp[u][i];
        }
    }

    if(u == v) return u;

    for(int i = MAXL - 1; i >= 0; i--)
    {
        if(dp[u][i] != dp[v][i])
        {
            //FAZ UM PULO DE TAMANHO 2^i DE U E DE V
            u = dp[u][i];
            v = dp[v][i];
        }
    }

    return dp[u][0];
}

void dfs(int u, int p)
{
    nivel[u] = nivel[p] + 1;

    for(auto x : grafo[u]) if(x.first != p)
    {
        int v = x.first;
        ll c = x.second;

        distancia[v] = distancia[u] + c;
        dp[v][0] = u;
        dfs(v, u);
    }
}

void precalc()
{
    dfs(1, 0);

    for(int i = 1; i < MAXL; i++)
        for(int u = 1; u <= N; u++)
            if(dp[u][i - 1] != -1)
                dp[u][i] = dp[dp[u][i - 1]][i - 1];
}


int main(int argc, char const *argv[])
{
	optimize;

    while((cin >> N) && N)
    {
        //LIMPA OS VALORES
        for(int i = 0; i <= N; i++)
        {
            for(int j = 0; j < MAXL; j++)
                dp[i][j] = -1;
            
            grafo[i].clear();
        }

        for(int i = 1, u, v; i < N; i++)
        {
            cin >> u >> v;

            u++;

            grafo[i + 1].EB(u, v);
            grafo[u].EB(i + 1, v);
        }

        precalc();

        int Q, u, v;

        cin >> Q;

        for(int i = 1; i <= Q; i++)
        {
            cin >> u >> v;

            u++;
            v++;

            cout << (distancia[u] + distancia[v] - (2 * distancia[LCA(u, v)])) << " \n"[i == Q];
        }

    }

	return 0;
}