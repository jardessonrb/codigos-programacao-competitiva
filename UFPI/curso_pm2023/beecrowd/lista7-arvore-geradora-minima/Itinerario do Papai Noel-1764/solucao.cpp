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

    Aresta(int u, int v, int c){
        this->origem = u;
        this->destino = v;
        this->custo = c;
    }

    bool operator < (const Aresta &outra){
        return this->custo < outra.custo;
    }
};

struct UnionFind {
    vector<int> pai;

    UnionFind(){}

    UnionFind(int N){
        resize(N);
    }

    void resize(int N){
        this->pai.resize(N + 1);

        for (int i = 0; i <= N; i++)
        {
            pai[i] = i;
        }
    }

    int find(int u){
        if(this->pai[u] == u) return u;

        return this->pai[u] = find(this->pai[u]);
    }

    bool isMesmoConjunto(int u, int v){
        return find(u) == find(v);
    }

    void join(int u, int v){
        int paiU = find(u);
        int paiV = find(v);

        this->pai[paiU] = paiV;
    }
};

struct Grafo {

    UnionFind unionFind;
    vector<Aresta> arestas;

    Grafo(int N){
        this->unionFind.resize(N);
    }


    void add(int u, int v, int c){
        Aresta aresta(u, v, c);

        add(aresta);
    }

    void add(Aresta aresta){
        this->arestas.push_back(aresta);
    }

    bool contemCiclo(int u, int v){
        return this->unionFind.isMesmoConjunto(u, v);
    }

    vector<Aresta> calcMST(){
        vector<Aresta> mst;

        sort(ALL(this->arestas));

        for(auto &aresta : this->arestas){
            int u =  aresta.origem;
            int v =  aresta.destino;
            int c =  aresta.custo;

            if(!contemCiclo(u, v)){

                this->unionFind.join(u, v);
                mst.push_back(aresta);
            }
        }

        return mst;
    }

};

int main(int argc, char const *argv[]){
    optimize;

    int N, M;

    while((cin >> N >> M) && (N || M)){

        Grafo grafo(N);
        for(int i = 0, a, b, c; i < M; i++){
            cin >> a >> b >> c;

            grafo.add(a, b, c);
        }

        vector<Aresta>  mst = grafo.calcMST();
        ll total = 0;
        for(auto aresta : mst){
            total += aresta.custo;
        }

        cout << total << endl;
    }

    return 0;
}