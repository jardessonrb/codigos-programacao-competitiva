#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 101010
#define MAXV 1010
#define ll long long
#define ld long double
#define pii pair<int, int>
#define INF 2000000020LL
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
#define check_in_matriz(l, c, minl, maxc) (l >= 0 && l < minl) && (c < maxc && c >= 0) && (!visitados[l][c])
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};


vector<pii> grafo[MAXN];
int C, V;

vector<vector<int>> dijkstra(int origem){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> fila;

    vector<vector<int>> distancias(C + 1, vector<int>(2, INF));
    vector<vector<bool>> visitados(C + 1, vector<bool>(2, false));

    fila.push({0, {origem, 0}});

    distancias[origem][0] = 0;

    while (!fila.empty()){
        int custo     = fila.top().first;
        int vertice   = fila.top().second.first;
        bool paridade = fila.top().second.second;
        fila.pop();

        if(visitados[vertice][paridade]) continue;

        visitados[vertice][paridade] = true;

        bool proxima_paridade = !paridade;
        for(auto [vertice_curr, custo] : grafo[vertice]){
            if(distancias[vertice_curr][proxima_paridade] > distancias[vertice][paridade] + custo){
                distancias[vertice_curr][proxima_paridade] = distancias[vertice][paridade] + custo;

                fila.push({distancias[vertice_curr][proxima_paridade], {vertice_curr, proxima_paridade}});
            }

        }
    }

    return distancias;  
}


int main(int argc, char const *argv[]){
    optimize;

    cin >> C >> V;

    for (int i = 0, a, b, c; i < V; i++)
    {
        cin >> a >> b >> c;
        grafo[a].push_back({b, c});
        grafo[b].push_back({a, c});
    }
    

    auto resultado = dijkstra(1);

    if(resultado[C][0] == INF){
        cout << -1 << endl;
    }else {
        cout << resultado[C][0] << endl;
    }
    return 0;
}