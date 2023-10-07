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

vector<vector<int>> grafo;
vector<vector<bool>> visitados;
int N, M;

void dfs(int linha, int coluna){
    if(visitados[linha][coluna]) return;

    visitados[linha][coluna] = true;

    for (int i = 0; i < 4; i++)
    {
        int grafox = linha  + dx[i];
        int grafoy = coluna + dy[i];

        if((grafox >= 1 && grafox <= N) && (grafoy >= 1 && grafoy <= M)){
            if(grafo[grafox][grafoy] == 1 && !visitados[grafox][grafoy]){
                dfs(grafox, grafoy);
            }
        }
    }
    
    
}

int main(int argc, char const *argv[]){
    optimize;

    cin >> N >> M;

    grafo.resize(N + 1, vector<int>(M + 1));
    visitados.resize(N + 1, vector<bool>(M + 1));


    int valor;
    for (int l = 1; l <= N; l++)
    {
       for (int c = 1; c <= M; c++)
       {
            cin >> valor;
            grafo[l][c] = valor;
       }
       
    }

    int ans = 0;
    for (int l = 1; l <= N; l++)
    {
       for (int c = 1; c <= M; c++)
       {
           if(!visitados[l][c] && grafo[l][c] == 1){
                ans++;
                dfs(l, c);
           }
       }
    }

    cout << ans << endl;

    return 0;
}