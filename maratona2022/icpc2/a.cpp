#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200020
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

vector<pair<int, int>> grafo[16*17];
bool visitados[16*17];
int soma = 0;
int somaVi = 0;
void dfs(int x){
    if(visitados[x]) return;
    visitados[x] =  true;
    somaVi++;

    int index = 0;
    int s = 1000;
    for(auto v : grafo[x]){
        if(visitados[v.first]) continue;

        if(s < v.second){
            s = v.second;
        }
    }

    soma += s;

    for (auto v : grafo[x])
    {
       dfs(v.first);
    }
    
}

int main(int argc, char const *argv[]){
    optimize;
    
    int N, M , W;

    cin >> N >> M >> W;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        grafo[a].push_back({b, c});
        grafo[b].push_back({a, c});
    }

    dfs(W);

    cout << soma << " " << somaVi << endl;
    
    return 0;
}