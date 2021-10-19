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

int dp[MAXN][MAXL], nivel[MAXN], info[MAXN][MAXL], pai[MAXN], sz[MAXN];

//dp[u][i] --> o cara de distancia 2^i de u, no caminho de u até a raiz 

vii grafo[MAXN];
int N, R;

ll distancia[MAXN];

//O(log(N))
int LCA(int u, int v)
{
    if(nivel[u] < nivel[v]) swap(u, v);

    int ans = 0;

    for(int i = MAXL - 1; i >= 0; i--)
    {
        if(dp[u][i] != -1 && nivel[dp[u][i]] >= nivel[v])
        {
            //FAZ UM PULO DE TAMANHO 2^i DE U
            ans = max(ans, info[u][i]);
            u = dp[u][i];
        }
    }

    if(u == v) return ans;

    for(int i = MAXL - 1; i >= 0; i--)
    {
        if(dp[u][i] != dp[v][i])
        {
            //FAZ UM PULO DE TAMANHO 2^i DE U E DE V
            ans = max({ans, info[u][i], info[v][i]});
            u = dp[u][i];
            v = dp[v][i];
        }
    }

    ans = max({ans, info[v][0], info[u][0]});

    return ans;
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
        info[v][0] = c;
        dfs(v, u);
    }
}


struct Aresta
{
    int u, v, c;

    Aresta(int u = 0, int v = 0, int c = 0) : u(u), v(v), c(c) {}

    bool operator < (const Aresta &a) const
    {
        return c < a.c;
    }
};

vector<Aresta> arestas;

ll K;

int find(int u)
{
    return pai[u] = (u == pai[u] ? u : find(pai[u]));
}

void join(int u, int v)
{
    u = find(u);
    v = find(v);

    if(sz[u] > sz[v]) swap(u, v);

    sz[v] += sz[u];
    pai[u] = v;
}


void MST()
{
    for(int i = 1; i <= N; i++) pai[i] = i, sz[i] = 1;
    
    sort(ALL(arestas));

    for(auto aresta : arestas)
    {
        int u = aresta.u;
        int v = aresta.v;
        int c = aresta.c;

        //Faz parte
        if(find(u) != find(v))
        {
            grafo[u].EB(v, c);
            grafo[v].EB(u, c);

            K += c;

            join(u, v);
        }
    }
}

void precalc()
{
    MST();

    dfs(1, 0);

    for(int i = 1; i < MAXL; i++)
        for(int u = 1; u <= N; u++)
            if(dp[u][i - 1] != -1)
            {
                info[u][i] = max(info[u][i - 1], info[dp[u][i - 1]][i - 1]);
                dp[u][i] = dp[dp[u][i - 1]][i - 1];
            }
}

unordered_map<int, int> custo[MAXN];

int main(int argc, char const *argv[])
{
	optimize;

    cin >> N >> R;

    for(int i = 1, u, v, c; i <= R; i++)
    {
        cin >> u >> v >> c;

        arestas.EB(u, v, c);

        custo[u][v] = custo[v][u] = c;
    }

    precalc();

    int Q, u, v;

    cin >> Q;

    for(int i = 1; i <= Q; i++)
    {
        cin >> u >> v;

        cout << (K - LCA(u, v) + custo[u][v]) << endl;
    }

	return 0;
}