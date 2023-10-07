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

int N, M;

vector<vector<int>> grafo;
map<int, bool> visitados;
vector<int> unionFind;

int find(int u){
    if(unionFind[u] == u) return u;

    return unionFind[u] = find(unionFind[u]);
}

void join(int u, int v){
    int paiU = find(u);
    int paiV = find(v);

    unionFind[paiU] = paiV;
}

void dfs(int vertice){
    if(visitados[vertice]) return;

    visitados[vertice] = true;

    for(int curr : grafo[vertice]){
        dfs(curr);
    }
}

void init(int N){
    unionFind.resize(N + 1);
    for (int i = 0; i <= N; i++)
    {
        unionFind[i] = i;
    }
    
}

bool isProprioPai(int u){
    return unionFind[u] == u;
}

int main(int argc, char const *argv[]){
    optimize;

    cin >> N >> M;

    grafo.resize(N + 1);   
    init(N);
    for (int i = 0; i < M; i++)
    {
        int nome1, nome2;

        cin >> nome1 >> nome2;

        grafo[nome1].push_back(nome2);
        grafo[nome2].push_back(nome1);

        join(nome1, nome2);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        // if(!visitados[i]){
        //     ans++;
        //     dfs(i);
        // }

        if(isProprioPai(i)){
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}