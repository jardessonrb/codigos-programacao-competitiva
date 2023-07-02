#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200020
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};


vector<int> grafos[MAXN];
bool visitados[MAXN];


void dfs(int u){
    if(visitados[u]) return;

    visitados[u] = true;
    
    for(auto vizinho : grafos[u]){
        cout << u << " -> " << vizinho << endl;

        dfs(vizinho);
    }
}
int main(int argc, char const *argv[]){
    optimize;
    int N, M;

    cin >> N >> M;

    for (int i = 0, u, v; i < M; i++)
    {
        cin >> u >> v;
        grafos[u].push_back(v);
        grafos[v].push_back(u);
    }

    dfs(1);   

    return 0;
}