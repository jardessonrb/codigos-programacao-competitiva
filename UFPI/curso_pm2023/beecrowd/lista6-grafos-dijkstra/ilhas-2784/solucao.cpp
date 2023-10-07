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
#define check_in_matriz(l, c, minl, maxc) (l >= 0 && l < minl) && (c < maxc && c >= 0) && (!visitados[l][c])
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

vector<pair<int, int>> grafo[MAXN];
int N, V, ilha;

vector<int> dijkstra(int origem){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;

    vector<int> distancias(N + 1, INT_MAX);
    vector<bool> visitados(N + 10, false);

    distancias[origem] = 0;

    fila.push({0, origem});

    while(!fila.empty()){
        auto [distancia, current] =  fila.top();
        // int distancia       = fila.top().first;
        // int vertice_current = fila.top().second;
        fila.pop();

        if(visitados[current]) continue;

        visitados[current] = true;

        for(auto [vizinho, custo] : grafo[current]){
            if(distancias[vizinho] > distancias[current] + custo){

                distancias[vizinho] = distancias[current] + custo;

                fila.push({distancias[vizinho], vizinho});
            }
        }
    }

    return distancias;

}

int main(int argc, char const *argv[]){
    optimize;

    cin >> N >> V;

    for (int i = 0, u, v, c; i < V; i++)
    {
       cin >> u >> v >> c;

       grafo[u].push_back({v, c});
       grafo[v].push_back({u, c});

    }
    
    cin >> ilha;

    vector<int> distancias = dijkstra(ilha);
    sort(ALL(distancias));
    int minping = INT_MAX;
    int maxping = INT_MIN;

    for(auto dis : distancias) {
        if(dis != 0 && dis != INT_MAX){
            minping = min(minping, dis);
            maxping = max(maxping, dis);
        }
    }

    cout << maxping - minping << endl;


    return 0;
}