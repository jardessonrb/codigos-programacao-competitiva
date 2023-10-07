#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 101010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 1e8+10
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
#define check_in_matriz(l, c, minl, maxc) (l >= 0 && l < minl) && (c < maxc && c >= 0) && (!visitados[l][c])
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int N, M;
map<string, vector<string>> grafo;

int main(int argc, char const *argv[]){
    optimize;

    cin >> N >> M;

    string a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;

        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    
    queue<pair<string, int>> fila;
    fila.push({"*", 0});


    map<string, int> distancia;
    map<string, bool> visitado;

    while(!fila.empty()){
        string verticeAtual = fila.front().first;
        int disVerticeAtual = fila.front().second;

        fila.pop();

        for(auto x : grafo[verticeAtual]){
            if(!visitado[x]){
                fila.push({x, disVerticeAtual + 1});
                distancia[x] = disVerticeAtual + 1;
                visitado[x] = true;
            }
        }
    }

    cout << distancia["Entrada"] + distancia["Saida"] << endl;

    return 0;
}