#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200020
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

vector<int> grafo[5001];
vector<bool> visitados;

void dfs(int v, int pai){
    visitados[v] = true;

    for(auto x : grafo[v]){
        if(!visitados[x] && x != pai){
            dfs(x, v);
        }
    }
}

int main(int argc, char const *argv[]){
    optimize;

    int N, A;

    cin >> N >> A;
    visitados.resize(N + 1, false);

    for (int i = 0; i < A; i++)
    {
       int a, b;

       cin >> a >> b;

       grafo[a].push_back(b);
       grafo[b].push_back(a);
    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if(!visitados[i]){
            ans++;
            dfs(i, 0);
        }
    }
    
    cout << ans << endl;

    return 0;
}