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

struct Aresta {
    int origem, destino, custo;

    Aresta(int u, int v, int c) : origem(u), destino(v), custo(c){}

    bool operator < (const Aresta &outra){
        return custo < outra.custo;
    }
};

vector<Aresta> grafo;
vector<int> conjuntos;

void initConjuntos(int N){
    conjuntos.resize(N + 1);
    for (int i = 0; i <= N; i++)
    {
        conjuntos[i] = i;
    }
}

int find(int u){
    if(conjuntos[u] == u) return u;

    return conjuntos[u] = find(conjuntos[u]);
}

void join(int u, int v){
    int pai_u = find(u);
    int pai_v = find(v);

    conjuntos[pai_u] = pai_v;
}

bool isContainsCiclos(int u, int v){
    return find(u) == find(v);
}

vector<Aresta> solve(){
    vector<Aresta> mst;
    sort(ALL(grafo));
    for(auto &aresta : grafo){
        int u = aresta.origem;
        int v = aresta.destino;
        int z = aresta.custo;

        if(!isContainsCiclos(u, v)){

            join(u, v);

            mst.push_back(aresta);
        }
    }

    return mst;
}

int main(int argc, char const *argv[]){
    optimize;

    int N, M;

    cin >> N >> M;

    for (int i = 0, origem, destino, custo; i < M; i++)
    {
        cin >> origem >> destino >> custo;

        grafo.emplace_back(origem, destino, custo);
    }
    
    initConjuntos(N);
    vector<Aresta> mst = solve();

    ll soma = 0;
    for(auto &aresta : mst){
        soma += aresta.custo;
    }

    cout << soma  << endl;

    return 0;
}