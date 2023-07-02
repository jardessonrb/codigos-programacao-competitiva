#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 101010
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

bool visitados[10000];

int ans = 0;

void dfs(int pai, vector<int>* grafo){
    if(visitados[pai]) return;

    visitados[pai] = true;

    for(auto x : grafo[pai]){
        if(!visitados[x]){
            ans += 2;
            dfs(x, grafo);
        }
    }
}

int main(int argc, char const *argv[]){
    optimize;

    int T;

    cin >> T;

    while (T--)
    {

        vector<int> grafo[10000];
        int inicio, arestas, vertices;

        cin >> inicio;

        cin >> vertices >> arestas;

        int a, b;
        for (int i = 0; i < arestas; i++)
        {
            cin >> a >> b;

            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        memset(visitados, false, sizeof visitados);
        ans = 0;
        dfs(inicio, grafo);

        cout << ans << endl;
    }
    
    return 0;
}