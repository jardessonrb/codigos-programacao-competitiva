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

bool visitados[100000];
int cont = 0;

void dfs(int x, vector<int> *grafo){
    visitados[x] = true;
    cont++;

    for(auto y : grafo[x]){
        if(!visitados[y]){
            dfs(y, grafo);
        }
    }
}

int main(int argc, char const *argv[]){
    optimize;

    int N, M;
    while (true)
    {
        cin >> N >> M;

        if(N == 0 && M == 0){
            break;
        }

        vector<int> grafo[N+10];
        for (int i = 0, v, w, p; i < M; i++)
        {
            cin >> v >> w >> p;
            grafo[v].push_back(w);
            if(p == 2){
                grafo[w].push_back(v);
            }
        }

        int ok = 1; 
        for (int i = 1; i <= N; i++)
        {
            cont = 0;
            memset(visitados, false, sizeof visitados);
            dfs(i, grafo);
            if(cont != N){
                ok = 0;
                break;
            }

        }
        
        cout << ok << endl;
    }
    

    return 0;
}