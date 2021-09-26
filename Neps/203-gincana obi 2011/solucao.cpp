#include <bits/stdc++.h>

using namespace std;

int visitados[1005];
vector <int> grafo[1005];

int n, m;

void dfs (int u) {

    if (visitados[u] != -1){
        return;
    }

    for (auto it : grafo[u]){
        visitados[u] = 1;
        dfs(it);
    }
}

int main () {

    int u, v;
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        visitados[i] = -1;
    }


    for (int i = 0; i < m; i++){
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    int ans = 0;
    
    for (int i = 1; i <= n; i++){
        if (visitados[i] == -1 && grafo[i].empty()) {
            ans++;
        }
        else if (visitados[i] == -1){
            ans++;
            dfs(i);
        }
    }

    cout << ans << endl;

    return 0;
}