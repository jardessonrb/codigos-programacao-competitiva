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
    int u, v, c;

    Aresta(int _u, int _v, int _c){
        this->u = _u;
        this->v = _v;
        this->c = _c;
    }

    bool operator < (const Aresta &aresta){
        return this->c < aresta.c;
    }
};

struct Grafo {
    vector<Aresta> arestas;
    vector<int> pais;

    Grafo(int N){
        pais.resize(N + 1);
        for (int i = 0; i < N; i++)
        {
            //Inicializa os pais no vetor de union find onde cada um é seu próprio pai
            pais[i] = i;
        }
        
    }

    void add(int u, int v, int c){
        arestas.emplace_back(u, v, c);
    }

    bool isCiclo(int u, int v){
        return find(u) == find(v);
    }

    void join(int u, int v){
        int pai_u = find(u);
        int pai_v = find(v);

        pais[pai_u] = pai_v;
    }

    int find(int u){
        if(pais[u] == u) return u;

        return find(pais[u]);
    }

    vector<Aresta> Kruskal(){
        vector<Aresta> arvoreMinima;

        sort(ALL(arestas));

        for(auto &aresta : arestas){
            int u = aresta.u;
            int v = aresta.v;
            int c = aresta.c;


            if(!isCiclo(u, v)){
                join(u, v);
                arvoreMinima.push_back(aresta);
            }
        }

        return arvoreMinima;
    }
};


int main(int argc, char const *argv[]){
    optimize;

    int M, N;

    while((cin >> M >> N) && (N || M)){
        ll total = 0;

        Grafo grafo(M);
        for (int i = 0, u, v, c; i < N; i++)
        {
            cin >> u >> v >> c;

            grafo.add(u, v, c);

            total += c;
        }

        auto arvore = grafo.Kruskal();

        for(auto &aresta : arvore){
            total -= aresta.c;
        }
        
        cout << total << endl;
    }



    return 0;
}