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

vector<int> solve(int N){
    initConjuntos(N);
    vector<int> mst(2);
    sort(ALL(grafo));
    int ans = 0;
    for(auto &aresta : grafo){
        int u = aresta.origem;
        int v = aresta.destino;
        int z = aresta.custo;

        if(!isContainsCiclos(u, v)){

            join(u, v);
            ans += z;
        }
    }
    mst[1] = ans;

    ans = 0;
    reverse(ALL(grafo));
    initConjuntos(N);
    for(auto &aresta : grafo){
        int u = aresta.origem;
        int v = aresta.destino;
        int z = aresta.custo;

        if(!isContainsCiclos(u, v)){

            join(u, v);
            ans += z;
        }
    }

    mst[0] = ans;

    return mst;
}

int main(int argc, char const *argv[]){
    optimize;

    int N, M;

    cin >> N;

    set<int> val;
    for(int i = 0, origem, destino, custo; i < N; i++)
    {
        cin >> origem >> destino >> custo;

        grafo.emplace_back(origem, destino, custo);

        val.insert(origem);
        val.insert(destino);
    }
    
    vector<int> mst = solve(val.size());

    cout << mst[0]  << endl;
    cout << mst[1]  << endl;

    return 0;
}