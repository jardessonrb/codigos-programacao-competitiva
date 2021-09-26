#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()

using namespace std;
int pai[100000], N;

int sz[1000000];

vector<int> conjuntos[1000000];

int find(int x){

    if(x == pai[x]) return x;

    return pai[x] = find(pai[x]);
}


//https://gist.github.com/eduardocesb/8c8b872f58d73f5ca2081e98ac698416

void join(int u, int v){

    u = find(u);
    v = find(v);

    if(u == v) return;

    if(sz[u] > sz[v])
        swap(u, v);

    sz[v] += sz[u];
    sz[u] = 0;

    pai[u] = v;
}

struct Aresta
{
    int u, v, c;

    Aresta(int u, int v, int c): u(u), v(v), c(c) {}

    bool operator < (const Aresta &a) const { 

        return c < a.c; 
    }
};

vector<Aresta> arestas;

int main(int argc, char const *argv[]){
    int M;

    cin >>N >> M;

    for(int i = 0 ; i <= N; i++)
    {
        pai[i] = i;
        sz[i] = 1;
    }
    

    for(int i = 1, u, v, c; i <= M; i++)
    {
        cin>> u >> v >> c;

        arestas.emplace_back(u, v, c);
    }

    sort(ALL(arestas));

    long long ans = 0;
    for(auto aresta : arestas)
    {
        if(find(aresta.u) != find(aresta.v))
        {
            ans += aresta.c;

            cout << aresta.u << " <-> " << aresta.v << " = " << aresta.c << endl;

            join(aresta.u, aresta.v);
        }
    }

    cout<< ans <<endl;

    return 0;
}