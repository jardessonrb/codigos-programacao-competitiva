/*
1 2
1 3
2 4
2 5
2 6
3 7
7 9
6 8
*/
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200020
#define MAXL 23
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;
vector<int> grafo[MAXN];
int N, Q, dp[MAXN][MAXL], nivel[MAXN];


int LCA(int u, int v) 
{
    if(nivel[u] < nivel[v]) swap(u, v);

    for(int i = MAXL - 1; i >= 0; i--)
    {
        if(dp[u][i] != -1 && nivel[dp[u][i]] >= nivel[v])
        {
            //FAZ UM PULO DE 2^i DE U
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

    for(int v : grafo[u])
    {
        if(v != p)
        {
            dp[v][0] = u;
            dfs(v, u);
        }
    }
}

void precalc()
{
    dfs(1, 0);

    for (int i = 1; i < MAXL; i++)
    {
        for(int u = 1; u <= N; u++) 
        {
            if(dp[u][i - 1] != -1)
            {
                dp[u][i] = dp[dp[u][i -1]][i - 1];
            }
        }
    }
    
}
int main(int argc, char const *argv[]){
    //optimize;
    memset(dp, -1, sizeof dp);

    cin>> N;

    for(int i = 1, u, v; i < N; i++)
    {
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    precalc();

    cin >> Q;
    int u, v;

    while(Q--)
    {
        cin >> u >> v;
        int resultLCA = LCA(u, v);
        cout << "LCA "<< u <<" e "<< v << " = "<< resultLCA <<endl;
        cout<<"Distancia: "<<u<<" e "<<v<<" = "<< (nivel[u] + nivel[v] - (2 * nivel[resultLCA])) <<endl;
    }    

    return 0;
}